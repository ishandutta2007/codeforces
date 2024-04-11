#include <bits/stdc++.h>
using namespace std;

using lint = long long;

class SegTree {
 public:
  int sz;
  vector<lint> coord;
  vector<lint> tree;
  SegTree(vector<lint> x) {
    coord = x;
    sort(begin(coord), end(coord));
    coord.resize(unique(begin(coord), end(coord)) - begin(coord));
    sz = coord.size();
    tree.assign(2 * sz, -1e18);
  }
  void Update(lint p, lint x) {
    p = lower_bound(begin(coord), end(coord), p) - begin(coord);
    for (p += sz; p > 0; p /= 2) {
      tree[p] = max(tree[p], x);
    }
  }
  lint Query(lint l, lint r) {
    lint z = -1e18;
    l = lower_bound(begin(coord), end(coord), l) - begin(coord);
    r = upper_bound(begin(coord), end(coord), r) - begin(coord);
    for (l += sz, r += sz; l < r; l /= 2, r /= 2) {
      if (l & 1) z = max(z, tree[l++]);
      if (r & 1) z = max(z, tree[--r]);
    }
    return z;
  }
};

void Main() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<lint> p(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    p[i] = a[i];
    if (i) p[i] += p[i - 1];
  }
  // dp[x] = max: dp[y] + cost(y + 1, x)
  // dp[x] = max: dp[y] + x - y if p[x] > p[y]
  // dp[x] = max: dp[y] + y - x if p[x] < p[y]
  // dp[x] = max: dp[y] if p[x] = p[y]
  p.emplace_back(0);
  SegTree segpos(p), segneg(p);
  p.pop_back();
  map<lint, lint> best;
  best[0] = 0;
  segpos.Update(0, 0);
  segneg.Update(0, 0);
  for (int i = 0; i < n; i++) {
    lint ret = -1e18;
    if (best.count(p[i]) == 0) {
      best[p[i]] = -1e18;
    } else {
      ret = max(ret, best[p[i]]);
    }
    ret = max(ret, segpos.Query(p[i] + 1, 1e18) - i - 1);
    ret = max(ret, segneg.Query(-1e18, p[i] - 1) + i + 1);
    segpos.Update(p[i], ret + i + 1);
    segneg.Update(p[i], ret - i - 1);
    best[p[i]] = max(best[p[i]], ret);
    if (i + 1 == n) {
      cout << ret << '\n';
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    Main();
  }
  return 0;
}