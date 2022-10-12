// Permutation Tree
// Time: O(N log N)
// Memory: O(N)
// Reference: https://codeforces.com/blog/entry/78898

#include <bits/stdc++.h>
using namespace std;

const int kCutNode = 69;
const int kJoinIncreasingNode = 420;
const int kJoinDecreasingNode = 1337;

// Segment Tree that supports range addition and range min query
struct SegTree {
  int size;
  struct Node {
    int value, lazy;
    Node(int _value=0): value(_value), lazy(0) {}
  };
  vector<Node> nodes;

  SegTree(int n) {
    size = n;
    nodes.resize(n*2);
  }

  inline void addNode(int idx, int val) {
    nodes[idx].value += val;
    nodes[idx].lazy += val;
  }

  void propagate(int idx, int l, int r) {
    int mid = (l + r) >> 1;
    addNode(idx + 1, nodes[idx].lazy);
    addNode(idx + (mid-l+1)*2, nodes[idx].lazy);
    nodes[idx].lazy = 0;
  }

  Node merge(const Node &l, const Node &r) {
    return Node(min(l.value, r.value));
  }

  void add(int idx, int l, int r, int ll, int rr, int val) {
    if (ll > r || rr < l) return;
    if (ll <= l && r <= rr) return addNode(idx, val);

    propagate(idx, l, r);

    int mid = (l + r) >> 1;
    add(idx + 1, l, mid, ll, rr, val);
    add(idx + (mid-l+1)*2, mid+1, r, ll, rr, val);
    nodes[idx] = merge(nodes[idx + 1], nodes[idx + (mid-l+1)*2]);
  }

  Node queryMin(int idx, int l, int r, int ll, int rr) {
    if (ll > r || rr < l) return Node(1e9);
    if (ll <= l && r <= rr) return nodes[idx];

    propagate(idx, l, r);

    int mid = (l + r) >> 1;
    return merge(queryMin(idx + 1, l, mid, ll, rr),
        queryMin(idx + (mid-l+1)*2, mid+1, r, ll, rr));
  }

  inline void add(int l, int r, int val) {
    add(0, 0, size-1, l, r, val);
  }

  inline int queryMin(int l, int r) {
    return queryMin(0, 0, size-1, l, r).value;
  }
};

struct Node {
  int type, l, r;
  vector<Node*> children;

  Node(int val): type(kCutNode), l(val), r(val) {}
  Node(int _type, int _l, int _r): type(_type), l(_l), r(_r) {}

  int length() { return r - l + 1; }
};

// Input: A permutation of a = (0, 1, ..., n-1)
// Output: Root of the permutation tree
// Input can be 1-based
Node* buildPermutationTree(int n, int a[]) {
  vector<Node*> nodes;
  vector<int> maximums, minimums;
  maximums.push_back(-1); minimums.push_back(-1);

  SegTree segtree(n);

  for (int i = 0; i < n; ++i) {
    while (maximums.size() > 1 && a[maximums.back()] < a[i]) {
      int size = maximums.size();
      segtree.add(maximums[size-2] + 1, maximums[size-1], a[i] - a[maximums.back()]);
      maximums.pop_back();
    }
    maximums.push_back(i);

    while (minimums.size() > 1 && a[minimums.back()] > a[i]) {
      int size = minimums.size();
      segtree.add(minimums[size-2] + 1, minimums[size-1], a[minimums.back()] - a[i]);
      minimums.pop_back();
    }
    minimums.push_back(i);

    Node* current = new Node(a[i]);

    while (nodes.size() > 0) {
      if ((nodes.back()->type == kJoinIncreasingNode && nodes.back()->r + 1 == current->l) ||
          (nodes.back()->type == kJoinDecreasingNode && nodes.back()->l == current->r + 1)) {
        // Add current node as child of the top of the stack
        nodes.back()->children.push_back(current);
        nodes.back()->l = min(nodes.back()->l, current->l);
        nodes.back()->r = max(nodes.back()->r, current->r);
        current = nodes.back();
        nodes.pop_back();
        continue;
      }

      if (nodes.back()->r + 1 == current->l) {
        // Make a new join increasing parent node
        Node *parent = new Node(kJoinIncreasingNode, nodes.back()->l, current->r);
        parent->children.push_back(nodes.back());
        parent->children.push_back(current);
        current = parent;
        nodes.pop_back();
        continue;
      }

      if (nodes.back()->l == current->r + 1) {
        // Make a new join decreasing parent node
        Node *parent = new Node(kJoinDecreasingNode, current->l, nodes.back()->r);
        parent->children.push_back(nodes.back());
        parent->children.push_back(current);
        current = parent;
        nodes.pop_back();
        continue;
      }

      if (segtree.queryMin(0, i - current->length()) == 0) {
        // Make a new cut parent node
        Node *parent = new Node(kCutNode, current->l, current->r);
        
        int length = current->length();
        parent->children.push_back(current);

        do {
          current = nodes.back();
          nodes.pop_back();
          length += current->length();
          parent->l = min(parent->l, current->l);
          parent->r = max(parent->r, current->r);
          parent->children.push_back(current);
        } while (parent->length() > length);

        reverse(parent->children.begin(), parent->children.end());
        current = parent;
        continue;
      }

      break;
    }

    nodes.push_back(current);
    segtree.add(0, i, -1);
  }

  assert(nodes.size() == 1);
  return nodes.back();
}

int n;
int a[300005];

long long dfs(Node *u) {
  long long ret = (u->type == kCutNode ? 1 : 1LL * (u->children.size()) * (u->children.size() - 1) / 2);
  for (Node *v: u->children) {
    ret += dfs(v);
  }
  return ret;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int r, c;
    scanf("%d %d", &r, &c);
    a[--r] = --c;
  }

  Node *root = buildPermutationTree(n, a);
  printf("%lld\n", dfs(root));
  return 0;
}