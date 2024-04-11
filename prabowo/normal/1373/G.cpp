#include <bits/stdc++.h>
using namespace std;
 
const int N = 400005;
const int INF = 1e9;
 
int n, m, k;

struct SegTree {
  int maxi[N << 2];
  int lazy[N << 2];
  
  void build(int node, int l, int r) {
    lazy[node] = 0;
    if (l == r) {
      maxi[node] = l - n - 1;
      return;
    }

    int mid = (l + r) >> 1;
    build(node*2 + 1, l, mid+0);
    build(node*2 + 2, mid+1, r);
    maxi[node] = max(maxi[node*2 + 1], maxi[node*2 + 2]);
  }

  void propagate(int node) {
    if (lazy[node] == 0) return;
    
    maxi[node*2 + 1] += lazy[node];
    maxi[node*2 + 2] += lazy[node];
    lazy[node*2 + 1] += lazy[node];
    lazy[node*2 + 2] += lazy[node];
    lazy[node] = 0;
  }
  
  void update(int node, int l, int r, int a, int b, int val) {
    if (l > b || r < a) return;
    if (l >= a && r <= b) {
      maxi[node] += val;
      lazy[node] += val;
      return;
    }
    
    propagate(node);
    
    int mid = (l + r) >> 1;
    
    update(node*2 + 1, l, mid+0, a, b, val);
    update(node*2 + 2, mid+1, r, a, b, val);
    maxi[node] = max(maxi[node*2 + 1], maxi[node*2 + 2]);
  }

  int query(int node, int l, int r, int a, int b) {
    if (l > b || r < a) return -INF;
    if (l >= a && r <= b) return maxi[node];

    propagate(node);

    int mid = (l + r) >> 1;

    return max(query(node*2 + 1, l, mid+0, a, b),
               query(node*2 + 2, mid+1, r, a, b));
  }
  
  void build() {
    build(0, 1, n*2);
  }

  void update(int l, int r, int val) {
    update(0, 1, n*2, l, r, val);
  }

  int query(int l, int r) {
    return query(0, 1, n*2, l, r);
  }
} tree;



int solve() {
  scanf("%d %d %d", &n, &k, &m);
  tree.build();
  set<pair<int, int>> pawns;
  multiset<int> furthest;

  while (m--) {
    int x, y;
    scanf("%d %d", &x, &y);
    int yy = y + abs(x - k);
    if (pawns.count({x, y})) {
      pawns.erase({x, y});
      tree.update(1, yy, -1);
      furthest.erase(furthest.find(yy));
    } else {
      pawns.insert({x, y});
      tree.update(1, yy, 1);
      furthest.insert(yy);
    }

    if (pawns.size() == 0) {
      printf("0\n");
    } else {
      int f = max(n, *furthest.rbegin());
      int ans = max(0, tree.query(1, f));
      printf("%d\n", ans);
    }
  }
  return 0;
}
 
int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) solve();
  return 0;
}