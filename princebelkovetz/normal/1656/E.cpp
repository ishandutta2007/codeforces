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
const int root = 212, mod = 998244353;

vector <vector <int>> g;
vector <int> col;

void dfs(int v, int p){
  for (auto &u: g[v]){
    if (u == p) continue;
    col[u] = col[v] ^ 1;
    dfs(u, v);
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(6);

  int tt; cin >> tt;
  while (tt--){
    int n; cin >> n;
    g.assign(n + 1, {});
    col.assign(n + 1, {});
    for (int i = 0, u, v; i < n - 1; ++i){
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    dfs(1, 1);

    for (int i = 1; i <= n; ++i)
      cout << (1 - 2 * col[i]) * (int)g[i].size() << ' ';

    cout << '\n';
  }


  return 0;
}