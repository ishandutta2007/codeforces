#include <bits/stdc++.h>
using namespace std;

class SegTree {
 public:
  int sz;
  vector<pair<int, int>> tree;
  vector<int> lazy;

  void Apply(int n, int x) {
    tree[n].first += x;
    lazy[n] += x;
  }

  void Push(int n, int lc, int rc) {
    Apply(lc, lazy[n]);
    Apply(rc, lazy[n]);
    lazy[n] = 0;
  }

  void Pull(int n, int lc, int rc) {
    tree[n].first = min(tree[lc].first, tree[rc].first);
    tree[n].second = 0;
    if (tree[n].first == tree[lc].first) tree[n].second += tree[lc].second;
    if (tree[n].first == tree[rc].first) tree[n].second += tree[rc].second;
  }

  void Update(int n, int tl, int tr, int l, int r, int x) {
    if (tr < l || r < tl || tl > tr || l > r) return;
    if (l <= tl && tr <= r) return Apply(n, x);
    int md = (tl + tr) / 2;
    int z = n + 2 * (md - tl + 1);
    Push(n, n + 1, z);
    Update(n + 1, tl, md, l, r, x);
    Update(z, md + 1, tr, l, r, x);
    Pull(n, n + 1, z);
  }

  void Update(int l, int r, int x) {
    return Update(1, 0, sz - 1, l, r, x);
  }  

  pair<int, int> Query(int n, int tl, int tr, int l, int r) {
    if (tr < l || r < tl || tl > tr || l > r) return pair(1e9, 0);
    if (l <= tl && tr <= r) return tree[n];
    int md = (tl + tr) / 2;
    int z = n + 2 * (md - tl + 1);
    Push(n, n + 1, z);
    auto p1 = Query(n + 1, tl, md, l, r);
    auto p2 = Query(z, md + 1, tr, l, r);
    auto res = min(p1, p2); res.second = 0;
    if (res.first == p1.first) res.second += p1.second;
    if (res.first == p2.first) res.second += p2.second;
    return res;
  }

  pair<int, int> Query(int l, int r) {
    return Query(1, 0, sz - 1, l, r);
  }

  void Build(int n, int tl, int tr) {
    if (tl == tr) {
      tree[n] = pair(0, 1);
      lazy[n] = 0;
      return;
    }
    int md = (tl + tr) / 2;
    int z = n + 2 * (md - tl + 1);
    Build(n + 1, tl, md);
    Build(z, md + 1, tr);
    tree[n].first = 0;
    tree[n].second = tree[n + 1].second + tree[z].second;
  }

  SegTree(int sz) : sz(sz) {
    tree.assign(2 * sz, pair(0, 1));
    lazy.assign(2 * sz, 0);
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> pref(n + 2), mxpref(n + 2), mnpref(n + 2);
    vector<int> suff(n + 2), mxsuff(n + 2), mnsuff(n + 2);
    for (int i = 1; i <= n; i++) {
      pref[i] = (s[i - 1] == '+' ? 1 : -1) + pref[i - 1];
    }
    SegTree seg(n + 2);
    for (int i = n; i >= 1; i--) {
      seg.Update(i, n + 1, (s[i - 1] == '+' ? 1 : -1));
      mnsuff[i] = seg.Query(i, n).first;    
    }
    seg = SegTree(n + 2);
    for (int i = n; i >= 1; i--) {
      seg.Update(i, n + 1, (s[i - 1] == '+' ? -1 : 1));
      mxsuff[i] = -seg.Query(i, n).first;   
    }
    for (int i = 1; i <= n; i++) {
      mxpref[i] = max(pref[i], mxpref[i - 1]);
      mnpref[i] = min(pref[i], mnpref[i - 1]);
    }
    // for (int i = n; i >= 1; i--) {
    //   mxsuff[i] = max(mxsuff[i], mxsuff[i + 1]);
    //   mnsuff[i] = min(mnsuff[i], mnsuff[i + 1]);
    // }
    // for (int i = 1; i <= n; i++) cout << mnsuff[i] << " \n"[i == n];
    // for (int i = 1; i <= n; i++) cout << mxsuff[i] << " \n"[i == n];
    
    while (m--) {
      int l, r;
      cin >> l >> r;
      l--, r++;
      int mn = min(mnpref[l], pref[l] + mnsuff[r]);
      int mx = max(mxpref[l], pref[l] + mxsuff[r]);
      cout << (mx - mn + 1) << '\n';
    }
  }
  return 0;
}