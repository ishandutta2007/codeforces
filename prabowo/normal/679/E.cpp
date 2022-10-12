#include <bits/stdc++.h>
using namespace std;

vector<long long> p42 = {
  1LL, 42LL, 1764LL, 74088LL, 3111696LL, 130691232LL, 5489031744LL,
  230539333248LL, 9682651996416LL, 406671383849472LL, 17080198121677824LL,
};

long long get_diff_to_nearest_p42(long long val) {
  return *lower_bound(p42.begin(), p42.end(), val) - val;
}

class SegTree {
  struct Node {
    long long val, diff_min;
    long long lazy_add, lazy_set;
    bool all_same;
    Node(long long _val = 0) {
      val = _val;
      diff_min = get_diff_to_nearest_p42(val);
      lazy_add = lazy_set = 0;
      all_same = true;
    }
  };
  
  int n;
  vector<Node> nodes;
  
  void merge(int node) {
    Node &l = nodes[node*2 + 1];
    Node &r = nodes[node*2 + 2];
    Node &cur = nodes[node];
    
    if (l.all_same && r.all_same && l.val == r.val) {
      cur.val = l.val;
      cur.diff_min = l.diff_min;
      cur.all_same = true;
    } else {
      cur.diff_min = min(l.diff_min, r.diff_min);
      cur.all_same = false;
    }
  }
  
  void set_node(int node, int val) {
    nodes[node].lazy_set = val;
    nodes[node].lazy_add = 0;
    nodes[node].all_same = true;
    nodes[node].val = val;
    nodes[node].diff_min = get_diff_to_nearest_p42(val);    
  }
  
  void add_node(int node, long long val) {    
    nodes[node].lazy_add += val;
    nodes[node].val += val;
    nodes[node].diff_min -= val;
  }
  
  void propagate(int node) {
    Node &cur = nodes[node];
    
    if (cur.lazy_set > 0) {
      set_node(node*2 + 1, cur.lazy_set);
      set_node(node*2 + 2, cur.lazy_set);
      cur.lazy_set = 0;
    }
    
    if (cur.lazy_add > 0) {
      add_node(node*2 + 1, cur.lazy_add);
      add_node(node*2 + 2, cur.lazy_add);
      cur.lazy_add = 0;
    }
  }
  
  void build(int node, int l, int r, int a[]) {
    if (l == r) {
      nodes[node] = Node(a[l]);
      return;
    }
    
    int mid = l + r >> 1;
    
    build(node*2 + 1, l, mid+0, a);
    build(node*2 + 2, mid+1, r, a);
    merge(node);
  }
  
  void add(int node, int l, int r, int ll, int rr, int val) {
    if (l > rr || r < ll) return;
    if (l >= ll && r <= rr) return add_node(node, val);
    
    propagate(node);
    int mid = l + r >> 1;
    
    add(node*2 + 1, l, mid+0, ll, rr, val);
    add(node*2 + 2, mid+1, r, ll, rr, val);
    merge(node);
  }
  
  void set(int node, int l, int r, int ll, int rr, int val) {
    if (l > rr || r < ll) return;
    if (l >= ll && r <= rr) return set_node(node, val);
    
    propagate(node);
    int mid = l + r >> 1;
    
    set(node*2 + 1, l, mid+0, ll, rr, val);
    set(node*2 + 2, mid+1, r, ll, rr, val);
    merge(node);
  }
  
  void fix_negative_diff(int node, int l, int r) {
    if (nodes[node].diff_min >= 0) return;
    if (nodes[node].all_same) {
      nodes[node].diff_min = get_diff_to_nearest_p42(nodes[node].val);
      return;
    }
    
    propagate(node);
    int mid = l + r >> 1;
    
    fix_negative_diff(node*2 + 1, l, mid+0);
    fix_negative_diff(node*2 + 2, mid+1, r);
    merge(node);
  }
  
  long long get(int node, int l, int r, int x) {
    if (l > x || r < x) return 0LL;
    if (nodes[node].all_same) return nodes[node].val;
    
    propagate(node);
    int mid = l + r >> 1;
    
    return get(node*2 + 1, l, mid+0, x) +
           get(node*2 + 2, mid+1, r, x);
  }
  
 public:
  SegTree(int _n): n(_n) {
    nodes.resize(n * 4);
  }
 
  void build(int a[]) {
    build(0, 0, n-1, a);
  }
  
  void add(int l, int r, int val) {
    add(0, 0, n-1, l, r, val);
    fix_negative_diff(0, 0, n-1);
  }
  
  void set(int l, int r, int val) {
    set(0, 0, n-1, l, r, val);
  }
  
  long long get(int x) {
    return get(0, 0, n-1, x);
  }
  
  bool has_power42() {
    return nodes[0].diff_min == 0;
  }
};

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  
  int a[n];
  for (int i=0; i<n; i++) scanf("%d", a + i);
  
  SegTree tree(n);
  tree.build(a);
  
  while (q--) {
    int t;
    scanf("%d", &t);
    
    if (t == 1) {
      int x;
      scanf("%d", &x);
      printf("%lld\n", tree.get(--x));
    } else if (t == 2) {
      int l, r, val;
      scanf("%d %d %d", &l, &r, &val);
      tree.set(--l, --r, val);
    } else if (t == 3) {
      int l, r, val;
      scanf("%d %d %d", &l, &r, &val);
      --l, --r;
      
      do {
        tree.add(l, r, val);
      } while (tree.has_power42());
    }
  }
  return 0;
}