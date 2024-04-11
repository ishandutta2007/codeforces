#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, q;
int a[N];

struct SegTree {
  long long sum[N << 2];
  int mini[N << 2], maxi[N << 2];
  int lazy[N << 2];

  inline void updateNode(int idx, int l, int r, int val) {
    mini[idx] = maxi[idx] = val;
    sum[idx] = 1LL * val * (r - l + 1);
    lazy[idx] = val;
  }

  inline void push(int idx, int l, int r) {
    if (lazy[idx] == -1) return;
    int mid = (l + r) >> 1;
    updateNode(idx*2 + 1, l, mid+0, lazy[idx]);
    updateNode(idx*2 + 2, mid+1, r, lazy[idx]);
    lazy[idx] = -1;
  }

  inline void pull(int idx) {
    sum[idx] = sum[idx*2 + 1] + sum[idx*2 + 2];
    mini[idx] = min(mini[idx*2 + 1], mini[idx*2 + 2]);
    maxi[idx] = max(maxi[idx*2 + 1], maxi[idx*2 + 2]);
  }

  void build(int idx, int l, int r) {
    lazy[idx] = -1;
    if (l == r) return updateNode(idx, l, r, a[l]);

    int mid = (l + r) >> 1;
    build(idx*2 + 1, l, mid+0);
    build(idx*2 + 2, mid+1, r);
    pull(idx);
  }

  void update(int idx, int l, int r, int ll, int rr, int val) {
    if (l > rr || r < ll || mini[idx] >= val) return;
    if (l >= ll && r <= rr && maxi[idx] <= val) return updateNode(idx, l, r, val);

    push(idx, l, r);
    int mid = (l + r) >> 1;
    update(idx*2 + 1, l, mid+0, ll, rr, val);
    update(idx*2 + 2, mid+1, r, ll, rr, val);
    pull(idx);
  }

  pair<int, int> queryCount(int idx, int l, int r, int ll, int s) {
    if (r < ll) return make_pair(0, 0);
    if (l >= ll) {
      if (sum[idx] <= s) return make_pair(r - l + 1, sum[idx]);
      if (l == r) return make_pair(0, 0);
    }

    push(idx, l, r);

    int mid = (l + r) >> 1;
    pair<int, int> ret = queryCount(idx*2 + 1, l, mid+0, ll, s);
    if (ret.first == max(0, mid - max(l, ll) + 1)) {
      pair<int, int> ret2 = queryCount(idx*2 + 2, mid+1, r, ll, s - ret.second);
      ret.first += ret2.first;
      ret.second += ret2.second;
    }

    return ret;
  }

  int queryIdx(int idx, int l, int r, int val) {
    if (mini[idx] > val) return -1;
    if (l == r) return l;

    push(idx, l, r);

    int mid = (l + r) >> 1;
    int ret = queryIdx(idx*2 + 1, l, mid, val);
    if (ret != -1) return ret;
    return queryIdx(idx*2 + 2, mid+1, r, val);
  }

  void build() {
    build(0, 0, n-1);
  }

  // Update max(a[i], val) in non-increasing a
  void update(int l, int r, int val) {
    update(0, 0, n-1, l, r, val);
  }

  // Returns (length, sum) of largest subarray starting from l with sum <= s
  pair<int, int> queryCount(int l, int s) {
    return queryCount(0, 0, n-1, l, s);
  }

  // Find smallest idx <= val
  int queryIdx(int val) {
    return queryIdx(0, 0, n-1, val);
  }
} tree;

void update(int x, int y) {
  tree.update(0, x, y);
}

int query(int x, int y) {
  int ret = 0;
  while (x != -1) {
    pair<int, int> p = tree.queryCount(x, y);

    ret += p.first;
    y -= p.second;

    if (p.first == n-x) break;

    x = tree.queryIdx(y);
  }

  return ret;
}

int main() {
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    assert(a[i] > 0);
  }

  tree.build();
  while (q--) {
    int t, x, y;
    scanf("%d %d %d", &t, &x, &y);
    --x;
    assert(y > 0);

    if (t == 1) update(x, y);
    else if (t == 2) printf("%d\n", query(x, y));
  }

  return 0;
}