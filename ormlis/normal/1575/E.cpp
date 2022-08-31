#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <bitset>
#include <random>
#include <string>
#include <vector>
#include <complex>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

using namespace std;

const int MOD = 1e9 + 7;

int add(int a, int b) {
  if (a + b < MOD)
    return a + b;
  return a + b - MOD;
}

pair<int, int> add(const pair<int, int> &a, const pair<int, int> &b) {
  return make_pair(add(a.first, b.first), add(a.second, b.second));
}

int sub(int a, int b) {
  if (a >= b)
    return a - b;
  return a + MOD - b;
}

int mul(int a, int b) {
  return a * 1ll * b % MOD;
}

const int MAXN = 200'200;
vector<pair<int, int>> G[MAXN];
int sz[MAXN];
bool used[MAXN];
int A[MAXN];

void dfs_sz(int v, int p) {
  sz[v] = 1;
  for (auto t : G[v]) {
    if (t.first == p || used[t.first])
      continue;
    dfs_sz(t.first, v);
    sz[v] += sz[t.first];
  }
}

struct fenw{
  pair<int, int> val[MAXN];
  int chng[MAXN];
  int ttime;
  fenw(){
    ttime = 0;
  }
  pair<int, int> get(int i) {
    pair<int, int> ans(0, 0);
    for (; i >= 0; i = (i & (i + 1)) - 1) {
      if (chng[i] == ttime)
        ans = add(ans, val[i]);
    }
    return ans;
  }
  void plus(int i, pair<int, int> x) {
    for (; i < MAXN; i = (i | (i + 1))) {
      if (chng[i] == ttime) {
        val[i] = add(val[i], x);
      } else {
        val[i] = x;
        chng[i] = ttime;
      }
    }
  }
};

fenw fenw1;
fenw fenw2;

vector<pair<int, int>> cur;
void zhfs(int v, int p, int col, int cnt, int sum) {
  cur.emplace_back(cnt, sum);
  for (auto t : G[v]) {
    if (t.first == p || used[t.first])
      continue;
    zhfs(t.first, v, t.second, cnt + (col != t.second), add(sum, A[t.first]));
  }
}

int k;
int res = 0;

void centroid(int v) {
  dfs_sz(v, -1);
  int u = v, p = -1;
  while (true) {
    pair<int, int> u_max(-1, -1);
    for (auto t : G[u]) {
      if (used[t.first] || t.first == p)
        continue;
      u_max = max(u_max, make_pair(sz[t.first], t.first));
    }
    if (2 * u_max.first >= sz[v]) {
      p = u;
      u = u_max.second;
    } else {
      break;
    }
  }
  for (auto t : G[u]) {
    if (used[t.first])
      continue;
    zhfs(t.first, u, t.second, 0, A[t.first]);
    for (auto [cnt, sum] : cur) {
      if (cnt > k)
        continue;
      res = add(res, add(sum, A[u]));
      auto tmp = fenw1.get(k - cnt - t.second);
      res = add(add(res, tmp.first), mul(tmp.second, sum));
      tmp = fenw2.get(k - cnt - 1 + t.second);
      res = add(add(res, tmp.first), mul(tmp.second, sum));
    }
    for (auto [cnt, sum] : cur) {
      if (t.second == 0)
        fenw1.plus(cnt, make_pair(add(sum, A[u]), 1));
      else
        fenw2.plus(cnt, make_pair(add(sum, A[u]), 1));
    }
    cur.clear();
  }
  ++fenw1.ttime;
  ++fenw2.ttime;
  used[u] = true;
  for (auto t : G[u]) {
    if (used[t.first])
      continue;
    centroid(t.first);
  }
}

int main() {
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#endif

  int n;
  cin >> n >> k;
  for (int i = 0; i < n; ++i)
    cin >> A[i];
  for (int i = 1; i < n; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    G[a - 1].emplace_back(b - 1, c);
    G[b - 1].emplace_back(a - 1, c);
  }
  centroid(0);
  for (int i = 0; i < n; ++i)
    res = add(res, A[i]);
  cout << res << '\n';
  return 0;
}