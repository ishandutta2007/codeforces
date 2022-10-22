#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <unordered_map>
#include <queue>
#include <iterator>
#include <sstream>
#include <cassert>
#include <locale>
#include <numeric>
#include <random>

#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';

using namespace std;
const int root = 212, mod = 1e9 + 7, N = 1e6 + 2, M = 11;

struct SegTree {
    int size;
    vector <int> val, add, tree;
    SegTree(vector <int>& a){
      size = 1;
      while (size < a.size()) size <<= 1;
      val.resize(2 * size -1);
      add.resize(2 * size - 1);
      tree.resize(2 * size - 1);
      build(0, 0, size, a);
    }
    void build(int v, int lx, int rx, vector <int>& a){
      if (lx + 1 == rx){
        if (lx < a.size()) val[v] = a[lx];
        else val[v] = -mod * mod;
        add[v] = mod * mod;
        tree[v] = val[v] - add[v];
        return;
      }
      int m = (lx + rx) / 2;
      build(2 * v + 1, lx, m, a);
      build(2 * v + 2, m, rx, a);
      val[v] = max(val[2 * v + 1], val[2 * v + 2]);
      add[v] = mod * mod;
      tree[v] = max(tree[2 * v + 1], tree[2 * v + 2]);
    }
    void push(int v){
      add[2 * v + 1] = min(add[2 * v + 1], add[v]);
      add[2 * v + 2] = min(add[2 * v + 2], add[v]);
      tree[2 * v + 1] = max(tree[2 * v + 1], val[2 * v + 1] - add[2 * v + 1]);
      tree[2 * v + 2] = max(tree[2 * v + 2], val[2 * v + 2] - add[2 * v + 2]);
    }
    void upd(int v, int lx, int rx, int l, int r, int x){
      if (l <= lx and rx <= r){
        add[v] = min(add[v], x);
        tree[v] = max(tree[v], val[v] - add[v]);
        return;
      }
      if (rx <= l or r <= lx) return;
      int m = (lx + rx) / 2;
      push(v);
      upd(2 * v + 1, lx, m, l, r, x);
      upd(2 * v + 2, m, rx, l, r, x);
      tree[v] = max(tree[2 * v + 1], tree[2 * v + 2]);
    }
    void upd(int l, int r, int x){
      upd(0, 0, size, l, r, x);
    }
    int get(int v, int lx, int rx, int l, int r){
      if (l <= lx and rx <= r) return tree[v];
      if (rx <= l or r <= lx) return -mod * mod;
      int m = (lx + rx) / 2;
      push(v);
      return max(get(2 * v + 1, lx, m, l, r), get(2 * v + 2, m, rx, l, r));
    }
    int get(int l, int r){
      return get(0, 0, size, l, r);
    }
};

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(6);

  int n, q; cin >> n >> q;
  vector <vector <int>> pref(3, vector <int>(n + 1));
  for (int i = 0; i < 3; ++i){
    for (int j = 0, x; j < n; ++j){
      cin >> x;
      pref[i][j + 1] = pref[i][j] + x;
    }
  }

  vector <vector <int>> qs(q, vector <int>(3));
  for (auto &x: qs) {
    for (auto &y: x) cin >> y;
    x[0]--, x[1]--;
  }
  vector <int> dp(n + 1, -mod * mod);
  vector <vector <int>> ls(n + 1), rs(n + 1);
  for (int i = 0; i < q; ++i){
    ls[qs[i][0]].push_back(i);
    rs[qs[i][1]].push_back(i);
  }
  vector <int> v(n), add(n, mod * mod);
  for (int i = 0; i < n; ++i){
    v[i] = pref[0][i + 1] - pref[1][i];
  }
  SegTree tree(v);
  for (int i = n - 1; i >= 0; --i){
    for (auto &x: rs[i]){
      tree.upd(qs[x][0], i + 1, qs[x][2]);
    }
    dp[i + 1] = tree.get(0, i + 1);
    dp[i + 1] += pref[1][i + 1];
  }
  multiset <int> heap;
  for (int i = 0; i < n; ++i){
    for (auto &x: ls[i])
      heap.insert(dp[i] - pref[1][i] - qs[x][2]);
    if (!heap.empty())
      dp[i + 1] = max(dp[i + 1], *(--heap.end()) + pref[1][i + 1]);
    for (auto &x: rs[i])
      heap.erase(heap.find(dp[qs[x][0]] - pref[1][qs[x][0]] - qs[x][2]));
  }

  int ans = -mod * mod;
  for (int i = 1; i <= n; ++i)
    ans = max(ans, dp[i] + pref[2][n] - pref[2][i - 1]);
  cout << ans << '\n';


  return 0;
}