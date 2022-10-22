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
const int root = 212, mod = 998244353, N = 2e7 + 2, L = 20;

vector <vector <int>> g;
vector <int> col;

void dfs(int v, int p, int ban){
  int cur = 1;
  for (auto u: g[v]){
    if (u == p) continue;
    while (cur == col[v] or cur == ban) cur++;
    col[u] = cur;
    dfs(u, v, col[v]);
    cur++;
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(6);
  int n; cin >> n;
  g.resize(n + 1);
  col.resize(n + 1);
  col[1] = 1;
  for (int i= 0, u, v; i < n - 1; ++i){
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 1, -1);
  int ans = 0;
  for (auto &x: col) ans = max(ans, x);
  cout << ans << '\n';
  for (int i = 1; i <= n; ++i)
    cout << col[i] << ' ';
  cout << '\n';
}