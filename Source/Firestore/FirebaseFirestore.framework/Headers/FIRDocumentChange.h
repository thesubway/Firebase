/*
 * Copyright 2017 Google
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#import <Foundation/Foundation.h>

#import "FIRFirestoreSwiftNameSupport.h"

NS_ASSUME_NONNULL_BEGIN

@class FIRDocumentSnapshot;

/** An enumeration of document change types. */
typedef NS_ENUM(NSInteger, FIRDocumentChangeType) {
  /** Indicates a new document was added to the set of documents matching the query. */
  FIRDocumentChangeTypeAdded,
  /** Indicates a document within the query was modified. */
  FIRDocumentChangeTypeModified,
  /**
   * Indicates a document within the query was removed (either deleted or no longer matches
   * the query.
   */
  FIRDocumentChangeTypeRemoved
} FIR_SWIFT_NAME(DocumentChangeType);

/**
 * A `FIRDocumentChange` represents a change to the documents matching a query. It contains the
 * document affected and the type of change that occurred (added, modified, or removed).
 */
FIR_SWIFT_NAME(DocumentChange)
@interface FIRDocumentChange : NSObject

/**   */
- (id)init __attribute__((unavailable("FIRDocumentChange cannot be created directly.")));

/** The type of change that occurred (added, modified, or removed). */
@property(nonatomic, readonly) FIRDocumentChangeType type;

/** The document affected by this change. */
@property(nonatomic, strong, readonly) FIRDocumentSnapshot *document;

/**
 * The index of the changed document in the result set immediately prior to this FIRDocumentChange
 * (i.e. supposing that all prior FIRDocumentChange objects have been applied). NSNotFound for
 * FIRDocumentChangeTypeAdded events.
 */
@property(nonatomic, readonly) NSUInteger oldIndex;

/**
 * The index of the changed document in the result set immediately after this FIRDocumentChange
 * (i.e. supposing that all prior FIRDocumentChange objects and the current FIRDocumentChange object
 * have been applied). NSNotFound for FIRDocumentChangeTypeRemoved events.
 */
@property(nonatomic, readonly) NSUInteger newIndex;

@end

NS_ASSUME_NONNULL_END
