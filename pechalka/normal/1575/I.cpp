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

long long tree[(1 << 18) + 228];

void build(int v, int left, int right, vector<long long> &A) {
  if (left + 1 == right) {
    tree[v] = A[left];
    return;
  }
  int mid = (left + right) / 2;
  build(2 * v + 1, left, mid, A);
  build(2 * v + 2, mid, right, A);
  tree[v] = 0;
}

long long get(int v, int left, int right, int i) {
  if (left + 1 == right)
    return tree[v];
  int mid = (left + right) / 2;
  if (i < mid)
    return tree[v] + get(2 * v + 1, left, mid, i);
  return tree[v] + get(2 * v + 2, mid, right, i);
}

void add(int v, int left, int right, int x, int y, long long d) {
  if (y <= left || right <= x)
    return;
  if (x <= left && right <= y) {
    tree[v] += d;
    return;
  }
  int mid = (left + right) / 2;
  add(2 * v + 1, left, mid, x, y, d);
  add(2 * v + 2, mid, right, x, y, d);
}

const int MAXN = 100'100;
const int K = 17;
vector<int> G[MAXN];
int up[MAXN][K];
int depth[MAXN];
int tin[MAXN];
int tout[MAXN];
vector<int> order;
long long sum[MAXN];

void dfs(int v, int p, int w, vector<long long> &A) {
  sum[v] = sum[p] + A[v];
  tin[v] = order.size();
  order.emplace_back(v);
  up[v][0] = p;
  depth[v] = w;
  for (int u : G[v]) {
    if (u == p)
      continue;
    dfs(u, v, w + 1, A);
  }
  tout[v] = order.size();
}

int la(int v, int d) {
  int k = K - 1;
  int pw = 1 << k;
  while (k >= 0) {
    if (d >= pw) {
      v = up[v][k];
      d -= pw;
    }
    --k;
    pw >>= 1;
  }
  return v;
}

int lca(int v, int u) {
  if (depth[v] > depth[u])
    v = la(v, depth[v] - depth[u]);
  else
    u = la(u, depth[u] - depth[v]);
  if (v == u)
    return v;
  int k = K - 1;
  while (k >= 0) {
    if (up[v][k] != up[u][k]) {
      v = up[v][k];
      u = up[u][k];
    }
    --k;
  }
  return up[v][0];
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

  int n, q;
  cin >> n >> q;
  vector<long long> A(n);
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
    A[i] = abs(A[i]);
  }
  for (int i = 1; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    G[a - 1].emplace_back(b - 1);
    G[b - 1].emplace_back(a - 1);
  }
  dfs(0, 0, 0, A);
  for (int j = 1; j < K; ++j) {
    for (int i = 0; i < n; ++i)
      up[i][j] = up[up[i][j - 1]][j - 1];
  }
  vector<long long> base(n);
  for (int i = 0; i < n; ++i)
    base[i] = sum[order[i]];
  build(0, 0, n, base);
  while (q--) {
    int t, a, b;
    cin >> t >> a >> b;
    if (t == 1) {
      --a;
      b = abs(b);
      add(0, 0, n, tin[a], tout[a], b - A[a]);
      A[a] = b;
    } else {
      --a;
      --b;
      if (a == b) {
        cout << 0 << '\n';
        continue;
      }
      int c = lca(a, b);
      long long ans = get(0, 0, n, tin[a]) + get(0, 0, n, tin[b]) - 2 * get(0, 0, n, tin[c]);
      ans = 2 * (ans + A[c]) - A[a] - A[b];
      cout << ans << '\n';
    }
  }
  return 0;
}