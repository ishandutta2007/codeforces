#include <bits/stdc++.h>

using namespace std;


class PQNode {
    // PQNodes are not exposed by pqtrees, they are internally used only.
    friend class PQTree;
    friend class QNodeChildrenIterator;

public:
    // Enum types we use throughout.
    enum PQNode_types  {leaf, pnode, qnode};
    enum PQNode_marks  {unmarked, queued, blocked, unblocked};
    enum PQNode_labels {empty, full, partial};

    // Returns the type of the current node, an enum of type PQNode_types.
    PQNode_types Type();

    // Returns the value of the leaf node.  Fails assertion if not leaf node.
    int LeafValue();

    // Returns all of this Node's children if it has any.
    // Return Value is the |children| argument.
    void Children(vector<PQNode*> *children);

private:
    /***** Used by P Nodes only *****/

    // A doubly-linked of links which form the children of a p-node, the order
    // of the list is arbitrary.
    list<PQNode*> circular_link_;

    // A count of the number of children used by a node.
    int ChildCount();

    // Returns the first |circular_link_| child with a given label or NULL.
    PQNode* CircularChildWithLabel(PQNode_labels label);

    // Moves the full children of this node to children of |new_node|.
    void MoveFullChildren(PQNode* new_node);

    // Replaces the circular_link pointer of |old_child| with |new_child|.
    void ReplaceCircularLink(PQNode* old_child, PQNode* new_child);

    /***** Used by Q Nodes only *****/

    // A set containing the two endmost children of a Q-node
    PQNode *endmost_children_[2];
    PQNode *pseudo_neighbors_[2];

    // Boolean indicating whether or not this is a pseudonode/child.
    bool pseudonode_, pseudochild_;

    // Returns the first endmost child with a given label or NULL.
    PQNode* EndmostChildWithLabel(PQNode_labels label);

    // Returns the first immediate sibling with a given label or NULL.
    PQNode* ImmediateSiblingWithLabel(PQNode_labels label);

    // Returns the first immediate sibling without a given label or NULL.
    PQNode* ImmediateSiblingWithoutLabel(PQNode_labels label);

    // Adds an immediate sibling to this node.
    void AddImmediateSibling(PQNode* sibling);

    // Adds an immediate sibling to this node.
    void RemoveImmediateSibling(PQNode* sibling);

    // Nulls otu the immediate siblings of this node.
    void ClearImmediateSiblings();

    // Returns the number of immediate siblings this node has (0, 1, or 2).
    int ImmediateSiblingCount() const;

    // Replaces the |endmost_children_| pointer to |old_child| with |new_child|.
    void ReplaceEndmostChild(PQNode* old_child, PQNode* new_child);

    // Replaces the immediate sibling of |old_child| with |new_child|.
    void ReplaceImmediateSibling(PQNode* old_child, PQNode* new_child);

    // Replaces the partial child |old_child| with |new_child|.
    void ReplacePartialChild(PQNode* old_child, PQNode* new_child);

    // Forces a Q-Node to "forget" it's pointers to it's endmost children.
    // Useful if you want to delete a Q-Node but not it's children.
    void ForgetChildren();

    // Returns true if all of the full and partial children of this node are
    // consecutive, with the partial children on the outside.
    bool ConsecutiveFullPartialChildren();

    /***** Used by Both Node types *****/

    // A set containing all the children of a node currently known to be full.
    set<PQNode*> full_children_;

    // A set containing all the children of a node currently known to be partial.
    set<PQNode*> partial_children_;

    // Only children of Q nodes have more than 0 immediate siblings.  Stores the
    // siblings to either side of this node in its parent's children.  One or both
    // siblings may be NULL.
    PQNode *immediate_siblings_[2];

    // Label is an indication of whether the node is empty, full, or partial
    enum PQNode_labels label_;

    // Mark is a designation used during the first pass of the reduction
    // algorithm.  Every node is initially unmarked.  It is marked
    // queued when it is placed onto the queue during the bubbling up.
    // It is marked either blocked or unblocked when it is processed.  Blocked
    // nodes can become unblocked if their siblings become unblocked.
    enum PQNode_marks mark_;

    // type is a designation telling whether the node is a leaf, P, or Q.
    enum PQNode_types type_;

    // the immediate ancestor of a node.  This field is always
    // valid for children of P-nodes and for endmost children of Q-nodes
    PQNode* parent_;

    // A count of the number of pertinent children currently possessed by a node
    int pertinent_child_count;

    // A count of the number of pertinent leaves currently possessed by a node
    int pertinent_leaf_count;

    // The value of the PQNode if it is a leaf.
    int leaf_value_;

    // Makes a deep copy of a node, sets this to be it's parent and returns copy.
    PQNode* CopyAsChild(const PQNode& to_copy);

    // Makes a deep copy of copy.
    void Copy(const PQNode& copy);

    // deep assignment operator
    PQNode& operator=(const PQNode& to_copy);

    // Return the next child in the immediate_siblings chain given a last pointer
    // if last pointer is null, will return the first sibling.  Behavior similar
    // to an iterator.
    PQNode* QNextChild(PQNode *last) const;

    void ReplaceChild(PQNode* old_child, PQNode* new_child);

    // removes this node from a q-parent and puts toInsert in it's place
    void SwapQ(PQNode *toInsert);

    // returns this node's parent (same as parent_ unless this node is a non-end
    // child of a Q-Node, in which case returns NULL)
    PQNode* Parent() const;

    // deep copy constructor
    PQNode(const PQNode& to_copy);

    // Constructor for a leaf PQNode.
    PQNode(int value);

    // Constructor for non-leaf PQNode.
    PQNode();

    // Deep destructor.
    ~PQNode();

    // Label's this node as full, updating the parent if needed.
    void LabelAsFull();

    // Walks the tree to build a map from values to leaf pointers.
    void FindLeaves(map<int, PQNode*> &leafAddress);

    // Walks the tree to find it's Frontier, returns one possible ordering.
    void FindFrontier(list<int> &ordering);

    // Resets a bunch of temporary variables after the reduce walks
    void Reset();

    // Walks the tree and prints it's structure to |out|.  P-nodes are
    // represented as ( ), Q-nodes as [ ], and leafs by their integer id. Used
    // primarily for debugging purposes
    void Print(string *out) const;

    void Identify() const;
};

// Q-Nodes have an unusual structure that makes iterating over their children
// slightly tricky.  This class makes the iterating much simpler.
//
// A Q-Node has two children whose ordering is defined strictly, but can be
// reversed, ie: (1,2,3,4) or (4,3,2,1) but not (2,1,4,3).  The Q-Node itself
// has only unordered pointers to the 1 or 2 children nodes on the ends of this
// list.  Each child contains pointers to the 1 or two siblings on either side
// of itself, but knows nothing of the ordering.
//
// Usage:
//   for (QNodeChildrenIterator it(candidate_node); !it.IsDone(); it.Next()) {
//     Process(it.Current());
//   }
class QNodeChildrenIterator {
public:
    // Creates an iterator of the children of |parent| optionally forcing the
    // iteration to start on the |begin_side|.
    QNodeChildrenIterator(PQNode* parent, PQNode* begin_side=NULL);

    // Returns a pointer to the current PQNode child in the list.
    PQNode* Current();

    // Next advances the current position in the child list.  If |IsDone()|,
    // operation has no effect.
    void Next();

    // Resets the iterator to the beginning of the list of children, optionally
    // forcing the iteration to start on the |begin_side|.
    void Reset(PQNode* begin_side=NULL);

    // Indicate whether or not all children have been looped through.  The initial
    // list order (forward or reverse) is consistent during the life of the
    // object.
    bool IsDone();

private:
    // Next() helper method to deal with pseudonodes.
    void NextPseudoNodeSibling();
    PQNode* parent_;
    PQNode* current_;
    PQNode* next_;
    PQNode* prev_;
};

PQNode::PQNode_types PQNode::Type() {
    return type_;
}

int PQNode::LeafValue() {
    assert(type_ == leaf);
    return leaf_value_;
}

void PQNode::Children(vector<PQNode*> *children) {
    assert(children->empty());
    if (type_ == pnode) {
        for (list<PQNode*>::const_iterator i = circular_link_.begin();
             i != circular_link_.end(); ++i)
            children->push_back(*i);
    } else if (type_ == qnode) {
        for(QNodeChildrenIterator qit(this); !qit.IsDone(); qit.Next())
            children->push_back(qit.Current());
    }
}

int PQNode::ChildCount() {
    return circular_link_.size();
}

PQNode* PQNode::CopyAsChild(const PQNode& to_copy) {
    PQNode* temp = new PQNode(to_copy);
    temp->parent_ = this;
    return temp;
}

PQNode::PQNode(const PQNode& to_copy) {
    Copy(to_copy);
}

void PQNode::Copy(const PQNode& to_copy) {
    // Copy the easy stuff
    leaf_value_            = to_copy.leaf_value_;
    pertinent_leaf_count  = to_copy.pertinent_leaf_count;
    pertinent_child_count = to_copy.pertinent_child_count;
    type_                  = to_copy.type_;
    mark_                  = to_copy.mark_;
    label_                 = to_copy.label_;
    pseudonode_            = to_copy.pseudonode_;
    pseudochild_           = to_copy.pseudochild_;

    // Make sure that these are unset initially
    parent_ = NULL;
    partial_children_.clear();
    full_children_.clear();
    circular_link_.clear();
    endmost_children_[0] = NULL;
    endmost_children_[1] = NULL;
    ClearImmediateSiblings();
    ForgetChildren();

    // Copy the nodes in circular link for pnodes.
    // If it is not a pnode, it will be empty, so this will be a no-op.
    for (list<PQNode*>::const_iterator i = to_copy.circular_link_.begin();
         i != to_copy.circular_link_.end(); i++)
        circular_link_.push_back(CopyAsChild(**i));

    // Copy the sibling chain for qnodes
    if (type_ == qnode) {
        PQNode *current, *last;
        // Pointers to nodes we are going to copy
        PQNode *curCopy, *lastCopy, *nextCopy;
        endmost_children_[0] = CopyAsChild(*to_copy.endmost_children_[0]);
        curCopy = to_copy.endmost_children_[0];
        lastCopy = NULL;
        last = endmost_children_[0];

        // Get all the intermediate children
        nextCopy = curCopy->QNextChild(lastCopy);
        while (nextCopy != NULL) {
            lastCopy = curCopy;
            curCopy  = nextCopy;
            current  = CopyAsChild(*curCopy);
            current->AddImmediateSibling(last);
            last->AddImmediateSibling(current);
            last = current;
            nextCopy = curCopy->QNextChild(lastCopy);
        }

        // Now set our last endmost_children_ pointer to our last child
        endmost_children_[1] = current;
    }
}

PQNode& PQNode::operator=(const PQNode& to_copy) {
    // Check for self copy
    if (&to_copy == this)
        return *this;
    Copy(to_copy);
    // Return ourself for chaining.
    return *this;
}

void PQNode::LabelAsFull() {
    label_ = full;
    if (parent_)
        parent_->full_children_.insert(this);
}

// Return the next child in the immediate_siblings_ chain given a last pointer.
// If last pointer is null, will return the first sibling.
PQNode* PQNode::QNextChild(PQNode *last) const {
    if (immediate_siblings_[0] == last) {
        return immediate_siblings_[1];
    } else {
        if (!last && 2 == ImmediateSiblingCount()) // occurs at edge of pseudonode.
            return immediate_siblings_[1];
        return immediate_siblings_[0];
    }
}

void PQNode::ReplaceChild(PQNode* old_child, PQNode* new_child) {
    if (type_ == pnode) {
        ReplaceCircularLink(old_child, new_child);
    } else {  // qnode
        for (int i = 0; i < 2 && old_child->immediate_siblings_[i]; ++i) {
            PQNode *sibling = old_child->immediate_siblings_[i];
            sibling->ReplaceImmediateSibling(old_child, new_child);
        }
        ReplaceEndmostChild(old_child, new_child);
    }
    new_child->parent_ = old_child->parent_;
    if (new_child->label_ == partial)
        new_child->parent_->partial_children_.insert(new_child);
    if (new_child->label_ == full)
        new_child->parent_->full_children_.insert(new_child);
}

// Removes this node from a q-parent and puts toInsert in it's place
void PQNode::SwapQ(PQNode *toInsert) {
    toInsert->pseudochild_ = pseudochild_;
    toInsert->ClearImmediateSiblings();
    for (int i = 0; i < 2; ++i) {
        if (parent_->endmost_children_[i] == this)
            parent_->endmost_children_[i] = toInsert;
        if (immediate_siblings_[i])
            immediate_siblings_[i]->ReplaceImmediateSibling(this, toInsert);
    }
    ClearImmediateSiblings();
    parent_ = NULL;
}

PQNode* PQNode::Parent() const {
    // This shouldn't be required, but somewhere a parent pointer is getting
    // leaked for an internal Q-Node that shouldn't have a parent pointer.
    if (immediate_siblings_[0] == NULL || immediate_siblings_[1] == NULL)
        return parent_;
    return NULL;
}

PQNode::PQNode(int value) {
    leaf_value_             = value;
    type_                  = leaf;
    parent_                = NULL;
    label_                 = empty;
    mark_                  = unmarked;
    pertinent_child_count  = 0;
    pertinent_leaf_count   = 0;
    endmost_children_[0] = NULL;
    endmost_children_[1] = NULL;
    ClearImmediateSiblings();
    ForgetChildren();
}

PQNode::PQNode() {
    pseudonode_ = false;
    parent_ = NULL;
    label_ = empty;
    mark_ = unmarked;
    pertinent_child_count = 0;
    pertinent_leaf_count = 0;
    endmost_children_[0] = NULL;
    endmost_children_[1] = NULL;
    ClearImmediateSiblings();
    ForgetChildren();
}

PQNode::~PQNode() {
    if (type_ == qnode) {
        PQNode *last     = NULL;
        PQNode *current  = endmost_children_[0];
        while(current) {
            PQNode *next = current->QNextChild(last);
            delete last;
            last    = current;
            current = next;
        }
        delete last;
    } else if (type_ == pnode) {
        for (list<PQNode*>::iterator i = circular_link_.begin();
             i != circular_link_.end(); i++)
            delete *i;
        circular_link_.clear();
    }
}

PQNode* PQNode::CircularChildWithLabel(PQNode_labels label) {
    for (list<PQNode*>::iterator i = circular_link_.begin();
         i != circular_link_.end(); i++) {
        if ((*i)->label_ == label)
            return *i;
    }
    return NULL;
}


PQNode* PQNode::EndmostChildWithLabel(PQNode_labels label) {
    for (int i = 0; i < 2; ++i)
        if (endmost_children_[i] && endmost_children_[i]->label_ == label)
            return endmost_children_[i];
    return NULL;
}

PQNode* PQNode::ImmediateSiblingWithLabel(PQNode_labels label) {
    for (int i = 0; i < 2 && immediate_siblings_[i]; ++i)
        if (immediate_siblings_[i]->label_ == label)
            return immediate_siblings_[i];
    return NULL;
}

PQNode* PQNode::ImmediateSiblingWithoutLabel(PQNode_labels label) {
    for (int i = 0; i < 2 && immediate_siblings_[i]; ++i)
        if (immediate_siblings_[i]->label_ != label)
            return immediate_siblings_[i];
    return NULL;
}

void PQNode::AddImmediateSibling(PQNode *sibling) {
    int null_idx = ImmediateSiblingCount();
    assert(null_idx < 2);
    immediate_siblings_[null_idx] = sibling;
}

void PQNode::RemoveImmediateSibling(PQNode *sibling) {
    if (immediate_siblings_[0] == sibling) {
        immediate_siblings_[0] = immediate_siblings_[1];
        immediate_siblings_[1] = NULL;
    } else if (immediate_siblings_[1] == sibling) {
        immediate_siblings_[1] = NULL;
    } else {
        assert(false);
    }
}

void PQNode::ClearImmediateSiblings() {
    for (int i = 0; i < 2; ++i)
        immediate_siblings_[i] = NULL;
}

int PQNode::ImmediateSiblingCount() const {
    int count = 0;
    for (int i = 0; (i < 2) && immediate_siblings_[i]; ++i)
        ++count;
    return count;
}

void PQNode::ReplaceEndmostChild(PQNode* old_child, PQNode* new_child) {
    for (int i = 0; i < 2; ++i) {
        if (endmost_children_[i] == old_child) {
            endmost_children_[i] = new_child;
            return;
        }
    }
}

void PQNode::ReplaceImmediateSibling(PQNode* old_child, PQNode* new_child) {
    for (int i = 0; i < 2 && immediate_siblings_[i]; ++i)
        if (immediate_siblings_[i] == old_child)
            immediate_siblings_[i] = new_child;
    new_child->immediate_siblings_[new_child->ImmediateSiblingCount()] = this;
}

void PQNode::ReplacePartialChild(PQNode* old_child, PQNode* new_child) {
    new_child->parent_ = this;
    partial_children_.insert(new_child);
    partial_children_.erase(old_child);
    if (type_ == pnode) {
        circular_link_.remove(old_child);
        circular_link_.push_back(new_child);
    } else {
        old_child->SwapQ(new_child);
    }
}

void PQNode::ForgetChildren() {
    for (int i = 0; i < 2; ++i)
        endmost_children_[i] = NULL;
}

bool PQNode::ConsecutiveFullPartialChildren() {
    // Trivial Case:
    if (full_children_.size() + partial_children_.size() <= 1)
        return true;
    // The strategy here is to count the number of each label of the siblings of
    // all of the full and partial children and see if the counts are correct.
    map<PQNode_labels, int> counts;
    for(set<PQNode*>::iterator it = full_children_.begin();
        it != full_children_.end(); ++it) {
        for (int i = 0; i < 2 && (*it)->immediate_siblings_[i]; ++i)
            counts[(*it)->immediate_siblings_[i]->label_]++;
    }
    for(set<PQNode*>::iterator it = partial_children_.begin();
        it != partial_children_.end(); ++it) {
        for (int i = 0; i < 2 && (*it)->immediate_siblings_[i]; ++i)
            counts[(*it)->immediate_siblings_[i]->label_]++;
    }
    if (counts[partial] != partial_children_.size())
        return false;
    // Depending on how many partials there are, most full children will get
    // counted twice.
    if (counts[full] != (full_children_.size() * 2) - (2 - counts[partial]))
        return false;
    return true;
}

void PQNode::MoveFullChildren(PQNode* new_node) {
    for (set<PQNode*>::iterator i = full_children_.begin();
         i != full_children_.end(); ++i) {
        circular_link_.remove(*i);
        new_node->circular_link_.push_back(*i);
        (*i)->parent_ = new_node;
    }
}

void PQNode::ReplaceCircularLink(PQNode* old_child, PQNode* new_child) {
    circular_link_.remove(old_child);
    circular_link_.push_back(new_child);
}

// FindLeaves, FindFrontier, Reset, and Print are very similar recursive
// functions.  Each is a depth-first walk of the entire tree looking for data
// at the leaves.
// TODO: Could probably be implemented better using function pointers.
void PQNode::FindLeaves(map<int, PQNode*> &leafAddress) {
    if (type_ == leaf) {
        leafAddress[leaf_value_] = this;
    } else if (type_ == pnode) {
        // Recurse by asking each child in circular_link_ to find it's leaves.
        for (list<PQNode*>::iterator i = circular_link_.begin();
             i!=circular_link_.end(); i++)
            (*i)->FindLeaves(leafAddress);
    } else if (type_ == qnode) {
        // Recurse by asking each child in my child list to find it's leaves.
        PQNode *last    = NULL;
        PQNode *current = endmost_children_[0];
        while (current) {
            current->FindLeaves(leafAddress);
            PQNode *next = current->QNextChild(last);
            last    = current;
            current = next;
        }
    }
}

void PQNode::FindFrontier(list<int> &ordering) {
    if (type_ == leaf) {
        ordering.push_back(leaf_value_);
    } else if (type_ == pnode) {
        for (list<PQNode*>::iterator i = circular_link_.begin();
             i != circular_link_.end();i++)
            (*i)->FindFrontier(ordering);
    } else if (type_ == qnode) {
        PQNode *last    = NULL;
        PQNode *current = endmost_children_[0];
        while (current) {
            current->FindFrontier(ordering);
            PQNode *next = current->QNextChild(last);
            last    = current;
            current = next;
        }
    }
}

// Resets a bunch of temporary variables after the reduce walks
void PQNode::Reset() {
    if (type_ == pnode) {
        for (list<PQNode*>::iterator i = circular_link_.begin();
             i != circular_link_.end(); i++)
            (*i)->Reset();
    } else if (type_ == qnode) {
        PQNode *last    = NULL;
        PQNode *current = endmost_children_[0];
        while (current) {
            current->Reset();
            PQNode *next = current->QNextChild(last);
            last    = current;
            current = next;
        }
    }

    full_children_.clear();
    partial_children_.clear();
    label_                 = empty;
    mark_                  = unmarked;
    pertinent_child_count = 0;
    pertinent_leaf_count  = 0;
    pseudochild_           = false;
    pseudonode_            = false;
}

// Walks the tree from the top and prints the tree structure to the string out.
// Used primarily for debugging purposes.

int answer = 1;
const int mod = 998244353;
using ll = long long;
void PQNode::Print(string *out) const {
    if (type_ == leaf) {
        char value_str[10];
        sprintf(value_str, "%d", leaf_value_);
        *out += value_str;
    } else if (type_ == pnode) {
        *out += "(";
        int cnt = 0;
        for (list<PQNode*>::const_iterator i = circular_link_.begin();
             i != circular_link_.end(); i++) {
            (*i)->Print(out);
            cnt++;
            answer = (answer * (ll)cnt) % mod;
            // Add a space if there are more elements remaining.
            if (++i != circular_link_.end())
                *out += " ";
            --i;
        }
        *out += ")";
    } else if (type_ == qnode) {
        *out += "[";
        PQNode *last     = NULL;
        PQNode *current  = endmost_children_[0];
        while (current) {
            current->Print(out);
            PQNode *next = current->QNextChild(last);
            last     = current;
            current  = next;
            if (current)
                *out += " ";
        }
        answer = (answer * (ll)2) % mod;
        *out += "]";
    }
}

void PQNode::Identify() const {
    cout << "Node: " << this;
    cout << " Parent: " << parent_ << endl;
    if (type_ == leaf) {
        cout << "Type: leaf  Value: " << leaf_value_ << endl;
    } else {
        string value;
        Print(&value);
        if (type_ == pnode)
            cout << "Type: pnode Value: " << value << endl;
        if (type_ == qnode)
            cout << "Type: qnode Value: " << value << endl;
    }
}



/***** QNodeChildrenIterator class *****/

QNodeChildrenIterator::QNodeChildrenIterator(
        PQNode* parent, PQNode* begin_side) {
    parent_ = parent;
    Reset(begin_side);
}

void QNodeChildrenIterator::Reset(PQNode* begin_side) {
    current_ = parent_->endmost_children_[0];
    if (begin_side)
        current_ = begin_side;
    prev_ = NULL;
    next_ = current_->immediate_siblings_[0];
}

PQNode* QNodeChildrenIterator::Current() {
    return current_;
}

void QNodeChildrenIterator::NextPseudoNodeSibling() {
    // This should only be called from the first Next() call after Reset() and
    // only if the first subnode has two immediate siblings.  We want to advance
    // our iterator to the non-empty sibling of |current_|
    prev_ = current_;
    current_ = current_->ImmediateSiblingWithLabel(PQNode::full);
    if (!current_)
        current_ = current_->ImmediateSiblingWithLabel(PQNode::partial);
}

void QNodeChildrenIterator::Next() {
    // If the first child has 2 immediate siblings, then we are on
    // the edge of a pseudonode.
    if (IsDone())
        return;
    if (prev_ == NULL && current_->ImmediateSiblingCount() == 2) {
        NextPseudoNodeSibling();
    } else {
        prev_ = current_;
        current_ = next_;
    }

    if (current_) {
        next_ = current_->immediate_siblings_[0];
        if (next_ == prev_)
            next_ = current_->immediate_siblings_[1];
    }
}

bool QNodeChildrenIterator::IsDone() {
    return current_ == NULL;
}

class PQTree {
private:

    // Root node of the PQTree
    PQNode *root_;

    // The number of blocks of blocked nodes during the 1st pass
    int block_count_;

    // The number of blocked nodes during the 1st pass
    int blocked_nodes_;

    // A variable (0 or 1) which is a count of the number of virtual nodes which
    // are imagined to be in the queue during the bubbling up.
    int off_the_top_;

    // Keeps track of all reductions performed on this tree in order
    list<set<int> > reductions_;

    // Keeps a pointer to the leaf containing a particular value this map actually
    // increases the time complexity of the algorithm.  To fix, you can create an
    // array of items so that each item hashes to its leaf address in constant
    // time, but this is a tradeoff to conserve space.
    map<int, PQNode*> leaf_address_;

    // A reference to a pseudonode that cannot be reached through the root
    // of the tree.  The pseudonode is a temporary node designed to handle
    // a special case in the first bubbling up pass it only exists during the
    // scope of the reduce operation
    PQNode* pseudonode_;

    // true if a non-safe reduce has failed, tree is useless.
    bool invalid_;

    // Loops through the consecutive blocked siblings of an unblocked node
    // recursively unblocking the siblings.
    // Args:
    //   sibling: next sibling node to unblock (if already unblocked, this call
    //            is a no-op).
    //   parent: Node to set as the parent of all unblocked siblings
    int UnblockSiblings(PQNode* sibling);

    // All of the templates for matching a reduce are below.  The template has a
    // letter describing which type of node it refers to and a number indicating
    // the index of the template for that letter.  These are the same indices in
    // the Booth & Lueker paper.  The return value indicates whether or not the
    // pattern accurately matches the template
    bool TemplateL1(PQNode* candidate_node);
    bool TemplateQ1(PQNode* candidate_node);
    bool TemplateQ2(PQNode* candidate_node);
    bool TemplateQ3(PQNode* candidate_node);
    bool TemplateP1(PQNode* candidate_node, bool is_reduction_root);
    bool TemplateP2(PQNode* candidate_node);
    bool TemplateP3(PQNode* candidate_node);
    bool TemplateP4(PQNode* candidate_node);
    bool TemplateP5(PQNode* candidate_node);
    bool TemplateP6(PQNode* candidate_node);

    // This procedure is the first pass of the Booth&Leuker PQTree algorithm
    // It processes the pertinent subtree of the PQ-Tree to determine the mark
    // of every node in that subtree
    // the pseudonode, if created, is returned so that it can be deleted at
    // the end of the reduce step
    bool Bubble(set<int> S);

    bool ReduceStep(set<int> S);

public:
    // Default constructor - constructs a tree using a set
    // Only reductions using elements of that set will succeed
    PQTree(set<int> S);
    PQTree(const PQTree& to_copy);
    ~PQTree();

    // Returns the root PQNode used for exploring the tree.
    PQNode* Root();

    // Mostly for debugging purposes, Prints the tree to standard out
    string Print() const;

    // Cleans up pointer mess caused by having a pseudonode
    void CleanPseudo();

    // Reduces the tree but protects if from becoming invalid if the reduction
    // fails, takes more time.
    bool SafeReduce(set<int>);
    bool SafeReduceAll(list<set<int> >);

    //reduces the tree - tree can become invalid, making all further
    //reductions fail
    bool Reduce(set<int> S);
    bool ReduceAll(list<set<int> > L);

    // Returns 1 possible frontier, or ordering preserving the reductions
    list<int> Frontier();

    // Assignment operator
    PQTree& operator=(const PQTree& to_copy);

    // Copies to_copy.  Used for the copy constructor and assignment operator.
    void CopyFrom(const PQTree& to_copy);


    // Returns a frontier not including leaves that were not a part of any
    // reduction
    list<int> ReducedFrontier();

    // Returns the reductions that have been performed on this tree.
    list<set<int> > GetReductions();

    // Returns the set of all elements on which a reduction was performed.
    set<int> GetContained();
};

PQTree::PQTree(const PQTree& to_copy) {
    CopyFrom(to_copy);
}

PQTree& PQTree::operator=(const PQTree& to_copy) {
    if (&to_copy != this)
        CopyFrom(to_copy);
    return *this;
}

void PQTree::CopyFrom(const PQTree& to_copy) {
    root_                 = new PQNode(*to_copy.root_);
    block_count_   = to_copy.block_count_;
    blocked_nodes_ = to_copy.blocked_nodes_;
    invalid_         = to_copy.invalid_;
    off_the_top_   = to_copy.off_the_top_;
    pseudonode_         = NULL;
    reductions_         = to_copy.reductions_;

    leaf_address_.clear();
    root_->FindLeaves(leaf_address_);
}

int PQTree::UnblockSiblings(PQNode* candidate_node) {
    assert (candidate_node->mark_ == PQNode::unblocked);
    int unblocked_count = 0;
    for (int i = 0; i < 2 && candidate_node->immediate_siblings_[i]; ++i) {
        PQNode* sibling = candidate_node->immediate_siblings_[i];
        if (sibling->mark_ == PQNode::blocked) {
            sibling->parent_ = candidate_node->parent_;
            sibling->mark_ = PQNode::unblocked;
            unblocked_count++;
            unblocked_count += UnblockSiblings(sibling);
        }
    }
    return unblocked_count;
}

// All the different templates for matching a reduce are below.  The template
// has a letter describing which type of node it refers to and a number
// indicating the index of the template for that letter.  These are the same
// indices found in the Booth & Lueker paper.
//
// Each template method is called in order within the reduce phase.  The
// template method determines if the Node passed to it is of the form that the
// template method can reduce.  If so, the method processes the Node and returns
// true.  If not, the method makes no changes and returns false.  Methods
// should be attempted in order until one of them returns true and then the
// remainder of the methods should be skipped.  The template ordering is:
// L1, P1, P2, P3, P4, P5, P6, Q1, Q2, Q3

bool PQTree::TemplateL1(PQNode* candidate_node) {
    // L1's pattern is simple: the node is a leaf node.
    if (candidate_node->type_ != PQNode::leaf)
        return false;

    candidate_node->LabelAsFull();
    return true;
}

bool PQTree::TemplateQ1(PQNode* candidate_node) {
    // Q1's Pattern is a Q-Node that has only full children.
    if (candidate_node->type_ != PQNode::qnode)
        return false;
    for (QNodeChildrenIterator it(candidate_node); !it.IsDone(); it.Next()) {
        if (it.Current()->label_ != PQNode::full)
            return false;
    }

    candidate_node->LabelAsFull();
    return true;
}

bool PQTree::TemplateQ2(PQNode* candidate_node) {
    // Q2's pattern is a Q-Node that either:
    // 1) contains consecutive full children with one end of the consecutive
    //    ordering being one of |candidate_node|'s |endmost_children|, also full.
    // 2) contains a single partial child that is one of |candidate_node|'s
    //    |endmost_children|.
    // 3) One of |candidate_node|'s |endmost_childdren| is full, consecutively
    //    followed by 0 or more full children, followed by one partial child.
    if (candidate_node->type_ != PQNode::qnode ||
        candidate_node->pseudonode_ ||
        candidate_node->partial_children_.size() > 1 ||
        !candidate_node->ConsecutiveFullPartialChildren())
        return false;

    bool has_partial = candidate_node->partial_children_.size() > 0;
    bool has_full = candidate_node->full_children_.size() > 0;

    if (has_full && !candidate_node->EndmostChildWithLabel(PQNode::full))
        return false;
    if (!has_full && !candidate_node->EndmostChildWithLabel(PQNode::partial))
        return false;

    // If there is a partial child, merge it's children into the candidate_node.
    if (has_partial) {
        PQNode* to_merge = *candidate_node->partial_children_.begin();
        for (int i = 0; i < 2; ++i) {
            PQNode* child = to_merge->endmost_children_[i];
            PQNode* sibling = to_merge->ImmediateSiblingWithLabel(child->label_);
            if (sibling) {
                sibling->ReplaceImmediateSibling(to_merge, child);
            } else {
                candidate_node->ReplaceEndmostChild(to_merge, child);
                child->parent_ = candidate_node;
            }
        }
        to_merge->ForgetChildren();
        delete to_merge;
    }

    candidate_node->label_ = PQNode::partial;
    if (candidate_node->parent_)
        candidate_node->parent_->partial_children_.insert(candidate_node);
    return true;
}

bool PQTree::TemplateQ3(PQNode* candidate_node) {
    // Q3's pattern is a Q-Node that contains 0-2 partial children.  It can
    // contain any number of empty and full children, but any full children must
    // be consecutive and sandwiched between any partial children.  Unlike Q2,
    // the consecutive full and partial children need not be endmost children.
    if (candidate_node->type_ != PQNode::qnode ||
        candidate_node->partial_children_.size() > 2 ||
        !candidate_node->ConsecutiveFullPartialChildren())
        return false;

    // Merge each of the partial children into |candidate_node|'s children
    for (set<PQNode*>::iterator j = candidate_node->partial_children_.begin();
         j != candidate_node->partial_children_.end(); j++) {
        PQNode* to_merge = *j;
        for (int i = 0; i < 2; ++i) {
            PQNode* sibling = to_merge->immediate_siblings_[i];
            if (sibling) {
                PQNode* child = to_merge->EndmostChildWithLabel(sibling->label_);
                if (!child)
                    child = to_merge->EndmostChildWithLabel(PQNode::full);
                sibling->ReplaceImmediateSibling(to_merge, child);
            } else {
                PQNode* empty_child = to_merge->EndmostChildWithLabel(PQNode::empty);
                empty_child->parent_ = candidate_node;
                candidate_node->ReplaceEndmostChild(to_merge, empty_child);
            }
        }

        to_merge->ForgetChildren();
        delete to_merge;
    }
    return true;
}

// A note here.  An error in the Booth and Leuker Algorithm fails to consider
// the case where a P-node is full, is the pertinent root, and is not an endmost
// child of a q-node.  In this case, we need to know that the P-node is a
// pertinent root and not try to update its parent whose pointer is possibly
// invalid.
bool PQTree::TemplateP1(PQNode* candidate_node, bool is_reduction_root) {
    // P1's pattern is a P-Node with all full children.
    if (candidate_node->type_ != PQNode::pnode ||
        candidate_node->full_children_.size() != candidate_node->ChildCount())
        return false;

    candidate_node->label_ = PQNode::full;
    if (!is_reduction_root)
        candidate_node->parent_->full_children_.insert(candidate_node);
    return true;
}

bool PQTree::TemplateP2(PQNode* candidate_node) {
    // P2's pattern is a P-Node at the root of the perinent subtree containing
    // both empty and full children.
    if (candidate_node->type_ != PQNode::pnode ||
        !candidate_node->partial_children_.empty())
        return false;

    // Move candidate_node's full children into their own P-node
    if (candidate_node->full_children_.size() >= 2) {
        PQNode* new_pnode = new PQNode;
        new_pnode->type_ = PQNode::pnode;
        new_pnode->parent_ = candidate_node;
        candidate_node->MoveFullChildren(new_pnode);
        candidate_node->circular_link_.push_back(new_pnode);
    }
    // Mark the root partial
    candidate_node->label_ = PQNode::partial;

    return true;
}
bool PQTree::TemplateP3(PQNode* candidate_node) {
    // P3's pattern is a P-Node not at the root of the perinent subtree
    // containing both empty and full children.
    if (candidate_node->type_ != PQNode::pnode ||
        !candidate_node->partial_children_.empty())
        return false;

    // P3's replacement is to create a Q-node that places all of the full
    // elements in a single P-Node child and all of the empty elements in a
    // single Q-Node child.  This new Q-Node is called a pseudonode as it isn't
    // properly formed (Q-Nodes should have at least 3 children) and will not
    // survive in it's current form to the end of the reduction.
    PQNode* new_qnode = new PQNode;
    new_qnode->type_ = PQNode::qnode;
    new_qnode->label_ = PQNode::partial;
    candidate_node->parent_->ReplacePartialChild(candidate_node, new_qnode);

    // Set up a |full_child| of |new_qnode| containing all of |candidate_node|'s
    // full children.
    PQNode* full_child;
    if (candidate_node->full_children_.size() == 1) {
        full_child = *candidate_node->full_children_.begin();
        candidate_node->circular_link_.remove(full_child);
    } else {
        full_child = new PQNode;
        full_child->type_ = PQNode::pnode;
        full_child->label_ = PQNode::full;
        candidate_node->MoveFullChildren(full_child);
    }
    full_child->parent_ = new_qnode;
    full_child->label_ = PQNode::full;
    new_qnode->endmost_children_[0] = full_child;
    new_qnode->full_children_.insert(full_child);

    // Set up a |empty_child| of |new_qnode| containing all of |candidate_node|'s
    // empty children.
    PQNode* empty_child;
    if (candidate_node->circular_link_.size() == 1) {
        empty_child = *candidate_node->circular_link_.begin();
        candidate_node->circular_link_.clear();
        delete candidate_node;
    } else {
        empty_child = candidate_node;
    }
    empty_child->parent_ = new_qnode;
    empty_child->label_ = PQNode::empty;
    new_qnode->endmost_children_[1] = empty_child;

    // Update the immediate siblings links (erasing the old ones if present)
    empty_child->immediate_siblings_[0] = full_child;
    full_child->immediate_siblings_[0] = empty_child;

    return true;
}

bool PQTree::TemplateP4(PQNode* candidate_node) {
    // P4's pattern is a P-Node at the root of the perinent subtree containing
    // one partial child and any number of empty/full children.
    if (candidate_node->type_ != PQNode::pnode ||
        candidate_node->partial_children_.size() != 1)
        return false;

    PQNode* partial_qnode = *candidate_node->partial_children_.begin();
    PQNode* empty_child = partial_qnode->EndmostChildWithLabel(PQNode::empty);
    PQNode* full_child = partial_qnode->EndmostChildWithLabel(PQNode::full);

    if (!empty_child || !full_child)
        return false;

    // Move the full children of |candidate_node| to children of |partial_qnode|.
    // TODO: Lots of redundancy between lines 271-287, 326-342, and 345-359.
    if (!candidate_node->full_children_.empty()) {
        PQNode *full_children_root;
        if (candidate_node->full_children_.size() == 1) {
            full_children_root = *(candidate_node->full_children_.begin());
            candidate_node->circular_link_.remove(full_children_root);
        } else {
            full_children_root = new PQNode;
            full_children_root->type_ = PQNode::pnode;
            full_children_root->label_ = PQNode::full;
            candidate_node->MoveFullChildren(full_children_root);
        }
        full_children_root->parent_ = partial_qnode;
        partial_qnode->ReplaceEndmostChild(full_child, full_children_root);
        partial_qnode->full_children_.insert(full_children_root);
        full_child->AddImmediateSibling(full_children_root);
        full_children_root->AddImmediateSibling(full_child);
    }

    // If |candidate_node| now only has one child, get rid of |candidate_node|.
    if (candidate_node->circular_link_.size() == 1) {
        if (candidate_node->Parent()) {
            candidate_node->parent_->ReplaceChild(candidate_node, partial_qnode);
        } else {
            partial_qnode->parent_ = NULL;
            if (root_ == candidate_node) {
                root_ = partial_qnode;
            } else {
                for (int i = 0; i < 2; ++i) {
                    PQNode *sibling = candidate_node->immediate_siblings_[i];
                    sibling->ReplaceImmediateSibling(candidate_node, partial_qnode);
                }
            }
        }
        candidate_node->circular_link_.clear();
        delete candidate_node;
    }
    return true;
}

bool PQTree::TemplateP5(PQNode* candidate_node) {
    // P4's pattern is a P-Node not at the root of the perinent subtree
    // containing one partial child and any number of empty/full children.
    if (candidate_node->type_ != PQNode::pnode ||
        candidate_node->partial_children_.size() != 1)
        return false;

    // |partial_qnode| will become the pertinent subtree root after replacement.
    PQNode* partial_qnode = *candidate_node->partial_children_.begin();
    assert(partial_qnode->type_ == PQNode::qnode);
    PQNode* empty_child = partial_qnode->EndmostChildWithLabel(PQNode::empty);
    PQNode* full_child = partial_qnode->EndmostChildWithLabel(PQNode::full);
    PQNode* empty_sibling = candidate_node->CircularChildWithLabel(PQNode::empty);

    if (!empty_child || !full_child)
        return false;

    // Move partial_qnode from candidate_node's child to it's parent's child
    candidate_node->parent_->ReplaceChild(candidate_node, partial_qnode);
    partial_qnode->pertinent_leaf_count = candidate_node->pertinent_leaf_count;
    candidate_node->circular_link_.remove(partial_qnode);

    // Move the full children of |candidate_node| to children of |partial_qnode|.
    if (!candidate_node->full_children_.empty()) {
        PQNode *full_children_root;
        if (candidate_node->full_children_.size() == 1) {
            full_children_root = *candidate_node->full_children_.begin();
            candidate_node->circular_link_.remove(full_children_root);
        } else {
            full_children_root = new PQNode;
            full_children_root->type_ = PQNode::pnode;
            full_children_root->label_ = PQNode::full;
            candidate_node->MoveFullChildren(full_children_root);
        }

        full_children_root->parent_ = partial_qnode;
        full_child->AddImmediateSibling(full_children_root);
        full_children_root->AddImmediateSibling(full_child);
        partial_qnode->ReplaceEndmostChild(full_child, full_children_root);
    }

    // If candidate_node still has some empty children, insert them
    if (candidate_node->ChildCount()) {
        PQNode *empty_children_root;
        if (candidate_node->ChildCount() == 1) {
            empty_children_root = empty_sibling;
        } else {
            empty_children_root = candidate_node;
            empty_children_root->label_ = PQNode::empty;
            empty_children_root->ClearImmediateSiblings();
        }

        empty_children_root->parent_ = partial_qnode;
        empty_child->AddImmediateSibling(empty_children_root);
        empty_children_root->AddImmediateSibling(empty_child);
        partial_qnode->ReplaceEndmostChild(empty_child, empty_children_root);
    }
    if (candidate_node->ChildCount() < 2) {
        // We want to delete candidate_node, but not it's children.
        candidate_node->circular_link_.clear();
        delete candidate_node;
    }

    return true;
}

bool PQTree::TemplateP6(PQNode* candidate_node) {
    if (candidate_node->type_ != PQNode::pnode ||
        candidate_node->partial_children_.size() != 2)
        return false;

    // TODO: Convert these to an array so we don't have 2 of everything.
    PQNode* partial_qnode1 = *candidate_node->partial_children_.begin();
    PQNode* partial_qnode2 = *(++(candidate_node->partial_children_.begin()));

    PQNode* empty_child1 = partial_qnode1->EndmostChildWithLabel(PQNode::empty);
    PQNode* full_child1 = partial_qnode1->EndmostChildWithLabel(PQNode::full);
    if (!empty_child1 || !full_child1)
        return false;

    PQNode* empty_child2 = partial_qnode2->EndmostChildWithLabel(PQNode::empty);
    PQNode* full_child2 = partial_qnode2->EndmostChildWithLabel(PQNode::full);
    if (!empty_child2 || !full_child2)
        return false;

    // Move the full children of candidate_node to be children of partial_qnode1
    if (!candidate_node->full_children_.empty()) {
        PQNode *full_children_root = NULL;
        if (candidate_node->full_children_.size() == 1) {
            full_children_root = *candidate_node->full_children_.begin();
            candidate_node->circular_link_.remove(full_children_root);
        } else {
            // create full_children_root to be a new p-node
            full_children_root = new PQNode;
            full_children_root->type_ = PQNode::pnode;
            full_children_root->label_ = PQNode::full;
            candidate_node->MoveFullChildren(full_children_root);
        }
        full_children_root->parent_ = partial_qnode1;
        full_child2->parent_ = partial_qnode1;

        full_child1->AddImmediateSibling(full_children_root);
        full_child2->AddImmediateSibling(full_children_root);
        full_children_root->AddImmediateSibling(full_child1);
        full_children_root->AddImmediateSibling(full_child2);
    } else  {
        full_child1->AddImmediateSibling(full_child2);
        full_child2->AddImmediateSibling(full_child1);
    }
    partial_qnode1->ReplaceEndmostChild(full_child1, empty_child2);
    empty_child2->parent_ = partial_qnode1;

    // We dont need |partial_qnode2| any more
    candidate_node->circular_link_.remove(partial_qnode2);
    partial_qnode2->ForgetChildren();
    delete partial_qnode2;

    // If |candidate_node| now only has one child, get rid of |candidate_node|.
    if (candidate_node->circular_link_.size() == 1) {
        partial_qnode1->parent_ = candidate_node->parent_;
        partial_qnode1->pertinent_leaf_count = candidate_node->pertinent_leaf_count;
        partial_qnode1->label_ = PQNode::partial;

        if (candidate_node->parent_) {
            candidate_node->parent_->partial_children_.insert(partial_qnode1);
            if (candidate_node->parent_->type_ == PQNode::pnode) {
                candidate_node->parent_->ReplaceCircularLink(candidate_node,
                                                             partial_qnode1);
            } else {
                for (int i = 0; i < 2 && candidate_node->immediate_siblings_[i]; ++i) {
                    PQNode* sibling = candidate_node->immediate_siblings_[i];
                    sibling->ReplaceImmediateSibling(candidate_node, partial_qnode1);
                }
                candidate_node->parent_->ReplaceEndmostChild(candidate_node,
                                                             partial_qnode1);
            }
        } else {
            root_ = partial_qnode1;
            partial_qnode1->parent_ = NULL;

            // Delete candidate_node, but not it's children.
            candidate_node->circular_link_.clear();
            delete candidate_node;
        }
    }
    return true;
}

// This procedure is the first pass of the Booth & Leuker PQTree algorithm.
// It processes the pertinent subtree of the PQ-Tree to determine the mark
// of every node in that subtree.
bool PQTree::Bubble(set<int> reduction_set) {
    queue<PQNode*> q;
    block_count_ = 0;
    blocked_nodes_ = 0;
    off_the_top_ = 0;

    // Stores blocked nodes
    set<PQNode*> blocked_list;

    // Insert the set's leaves into the queue
    for (set<int>::iterator i = reduction_set.begin();
         i != reduction_set.end(); ++i) {
        PQNode *temp = leaf_address_[*i];
        assert (temp);
        q.push(temp);
    }

    while (q.size() + block_count_ + off_the_top_ > 1) {
        if (q.empty())
            return false;

        PQNode* candidate_node = q.front();
        q.pop();
        candidate_node->mark_ = PQNode::blocked;

        // Get the set of blocked and PQNode::unblocked siblings
        set<PQNode*> unblocked_siblings;
        set<PQNode*> blocked_siblings;
        for (int i = 0; i < 2 && candidate_node->immediate_siblings_[i]; ++i) {
            PQNode* sibling = candidate_node->immediate_siblings_[i];
            if (sibling->mark_ == PQNode::blocked) {
                blocked_siblings.insert(sibling);
            } else if (sibling->mark_ == PQNode::unblocked) {
                unblocked_siblings.insert(sibling);
            }
        }

        // We can unblock |candidate_node| if any of there conditions is met:
        //  - 1 or more of its immediate siblings is unblocked.
        //  - It has 1 immediate sibling meaning it is a corner child of a q node.
        //  - It has 0 immediate siblings meaning it is a p node.
        if (!unblocked_siblings.empty()) {
            candidate_node->parent_ = (*unblocked_siblings.begin())->parent_;
            candidate_node->mark_ = PQNode::unblocked;
        } else if (candidate_node->ImmediateSiblingCount() < 2) {
            candidate_node->mark_ = PQNode::unblocked;
        }

        // If |candidate_node| is unblocked, we can process it.
        if (candidate_node->mark_ == PQNode::unblocked) {
            if (!blocked_siblings.empty()) {
                int list_size = UnblockSiblings(candidate_node);
                candidate_node->parent_->pertinent_child_count += list_size;
                blocked_nodes_ -= list_size;
            }

            if (!candidate_node->parent_) {
                off_the_top_ = 1;
            } else {
                candidate_node->parent_->pertinent_child_count++;
                if (candidate_node->parent_->mark_ == PQNode::unmarked) {
                    q.push(candidate_node->parent_);
                    candidate_node->parent_->mark_ = PQNode::queued;
                }
            }
            block_count_ -= blocked_siblings.size();
        } else {
            block_count_ += 1 - blocked_siblings.size();
            blocked_nodes_ += 1;
            blocked_list.insert(candidate_node);
        }
    }

    if (block_count_ > 1 || (off_the_top_ == 1 && block_count_ != 0))
        return false;

    // In this case, we have a block that is contained within a Q-node.  We must
    // assign a psuedonode to handle it.
    if (block_count_ == 1 && blocked_nodes_ > 1) {
        pseudonode_ = new PQNode;
        pseudonode_->type_ = PQNode::qnode;
        pseudonode_->pseudonode_ = true;
        pseudonode_->pertinent_child_count = 0;

        // Find the blocked nodes and which of those are endmost children.
        int side = 0;
        for (set<PQNode*>::iterator i = blocked_list.begin();
             i != blocked_list.end(); ++i) {
            PQNode* blocked = *i;
            if (blocked->mark_ == PQNode::blocked) {  // may have become unblocked
                pseudonode_->pertinent_child_count++;
                pseudonode_->pertinent_leaf_count += blocked->pertinent_leaf_count;
                for (int j = 0; j < 2; ++j) {
                    PQNode* sibling = blocked->immediate_siblings_[j];
                    if (sibling->mark_ == PQNode::unmarked) {
                        blocked->RemoveImmediateSibling(sibling);
                        sibling->RemoveImmediateSibling(blocked);
                        pseudonode_->pseudo_neighbors_[side] = sibling;
                        pseudonode_->endmost_children_[side++] = blocked;
                        break;
                    }
                }
                blocked->parent_ = pseudonode_;
                blocked->pseudochild_ = true;
            }
        }
        q.push(pseudonode_);
    }
    return true;
}

bool PQTree::ReduceStep(set<int> reduction_set) {
    // Build a queue with all the pertinent leaves in it
    queue<PQNode*> q;
    for (set<int>::iterator i = reduction_set.begin();
         i != reduction_set.end(); i++) {
        PQNode* candidate_node = leaf_address_[*i];
        if (candidate_node == NULL)
            return false;
        candidate_node->pertinent_leaf_count = 1;
        q.push(candidate_node);
    }

    while (!q.empty()) {
        // Remove candidate_node from the front of the queue
        PQNode* candidate_node = q.front();
        q.pop();

        // We test against different templates depending on whether |candidate_node|
        // is the root of the pertinent subtree.
        if (candidate_node->pertinent_leaf_count < reduction_set.size()) {
            PQNode* candidate_parent = candidate_node->parent_;
            candidate_parent->pertinent_leaf_count +=
                    candidate_node->pertinent_leaf_count;
            candidate_parent->pertinent_child_count--;
            // Push |candidate_parent| onto the queue if it no longer has any
            // pertinent children.
            if (candidate_parent->pertinent_child_count == 0)
                q.push(candidate_parent);

            // Test against each template in turn until one of them returns true.
            if      (TemplateL1(candidate_node)) {}
            else if (TemplateP1(candidate_node, /*is_reduction_root=*/ false)) {}
            else if (TemplateP3(candidate_node)) {}
            else if (TemplateP5(candidate_node)) {}
            else if (TemplateQ1(candidate_node)) {}
            else if (TemplateQ2(candidate_node)) {}
            else {
                CleanPseudo();
                return false;
            }
        } else {  // candidate_node is the root of the reduction subtree
            // Test against each template in turn until one of them returns true.
            if      (TemplateL1(candidate_node)) {}
            else if (TemplateP1(candidate_node, /*is_reduction_root=*/ true)) {}
            else if (TemplateP2(candidate_node)) {}
            else if (TemplateP4(candidate_node)) {}
            else if (TemplateP6(candidate_node)) {}
            else if (TemplateQ1(candidate_node)) {}
            else if (TemplateQ2(candidate_node)) {}
            else if (TemplateQ3(candidate_node)) {}
            else {
                CleanPseudo();
                return false;
            }
        }
    }
    CleanPseudo();
    return true;
}

void PQTree::CleanPseudo() {
    if (pseudonode_) {
        // The parents of these nodes should be ignored in the next round, but
        // pointers to the pseudonode which has been deleted make me nervous, so
        // null them all out.
        PQNode *last    = NULL;
        PQNode *current = pseudonode_->endmost_children_[0];
        while (current) {
            current->parent_ = NULL;
            PQNode *next = current->QNextChild(last);
            last    = current;
            current = next;
        }

        for (int i = 0; i < 2; i++) {
            pseudonode_->endmost_children_[i]->AddImmediateSibling(
                    pseudonode_->pseudo_neighbors_[i]);
            pseudonode_->pseudo_neighbors_[i]->AddImmediateSibling(
                    pseudonode_->endmost_children_[i]);
        }

        pseudonode_->ForgetChildren();
        delete pseudonode_;
        pseudonode_ = NULL;
    }
}

// Basic constructor from an initial set.
PQTree::PQTree(set<int> reduction_set) {
    // Set up the root node as a P-Node initially.
    root_ = new PQNode;
    root_->type_ = PQNode::pnode;
    invalid_ = false;
    pseudonode_ = NULL;
    block_count_ = 0;
    blocked_nodes_ = 0;
    off_the_top_ = 0;
    for (set<int>::iterator i = reduction_set.begin();
         i != reduction_set.end(); i++) {
        PQNode *new_node;
        new_node = new PQNode(*i);
        leaf_address_[*i] = new_node;
        new_node->parent_ = root_;
        new_node->type_ = PQNode::leaf;
        root_->circular_link_.push_back(new_node);
    }
}

PQNode* PQTree::Root() {
    return root_;
}

string PQTree::Print() const {
    string out;
    root_->Print(&out);
    return out;
}

//reduces the tree but protects if from becoming invalid
//if the reduction fails, takes more time
bool PQTree::SafeReduce(set<int> S) {
    //using a backup copy to enforce safety
    PQTree toCopy(*this);

    if (!Reduce(S)) {
        //reduce failed, so perform a copy
        root_ = new PQNode(*toCopy.root_);
        block_count_ = toCopy.block_count_;
        blocked_nodes_ = toCopy.blocked_nodes_;
        off_the_top_ = toCopy.off_the_top_;
        invalid_ = toCopy.invalid_;
        leaf_address_.clear();
        root_->FindLeaves(leaf_address_);
        return false;
    }
    return true;
}

bool PQTree::SafeReduceAll(list<set<int> > L) {
    //using a backup copy to enforce safety
    PQTree toCopy(*this);
    if (!ReduceAll(L)) {
        //reduce failed, so perform a copy
        root_ = new PQNode(*toCopy.root_);
        block_count_ = toCopy.block_count_;
        blocked_nodes_ = toCopy.blocked_nodes_;
        off_the_top_ = toCopy.off_the_top_;
        invalid_ = toCopy.invalid_;
        leaf_address_.clear();
        root_->FindLeaves(leaf_address_);
        return false;
    }
    return true;
}


bool PQTree::Reduce(set<int> reduction_set) {
    if (reduction_set.size() < 2) {
        reductions_.push_back(reduction_set);
        return true;
    }
    if (invalid_)
        return false;
    if (!Bubble(reduction_set)) {
        invalid_ = true;
        return false;
    }
    if (!ReduceStep(reduction_set)) {
        invalid_ = true;
        return false;
    }

    // Reset all the temporary variables for the next round.
    root_->Reset();

    // Store the reduction set for later lookup.
    reductions_.push_back(reduction_set);
    return true;
}

bool PQTree::ReduceAll(list<set<int> > L) {
    for (list<set<int> >::iterator S = L.begin(); S != L.end(); S++) {
        if (!Reduce(*S))
            return false;
    }
    return true;
}

list<int> PQTree::Frontier() {
    list<int> out;
    root_->FindFrontier(out);
    return out;
}

list<set<int> > PQTree::GetReductions() {
    return reductions_;
}

// Default destructor, Needs to delete the root.
PQTree::~PQTree() {
    delete root_;
}
using namespace std;

int main() {
#ifdef ONPC
    freopen("../a.in", "r", stdin);
    freopen("../a.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ddd;
    for(size_t i=0; i<m; ++i) {
        vector<int> g;
        int k;
        cin >> k;
        g.resize(k);
        for (int &j : g)
            cin >> j;
        ddd.push_back(g);
    }

    vector<int> o(n);
    iota(o.begin(), o.end(), 1);
    set<int> ST{o.begin(), o.end()};
    PQTree tree(ST);

    //reverse(ddd.begin(), ddd.end());
    for (auto g : ddd) {
        if (!tree.Reduce({g.begin(), g.end()})) {
            cout << 0;
            return 0;
        }
        //cerr << tree.print_expression() << '\n';
    }
    answer = 1;
    tree.Print();
    cout << answer;
}

// { 6  [ { 1  3  8  { 2  10 } }  5  11  9  { 4  7 } ] }
// { 6  [ { 4  7 }  9  11  5  { 1  3  8  { 2  10 } } ] }