#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int mod = 1e9 + 7;
int n, x, y, ans;
vector<int> to[201];
int sz[201], fa[201], d[201], iv[201];
int f[201][201];
inline void dfs(int i) {
  sz[i] = 1;
  for (int j : to[i])
    if (j != fa[i]) {
      d[j] = d[i] + 1, fa[j] = i;
      dfs(j), sz[i] += sz[j];
    }
}
int main() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> x >> y;
    to[x].push_back(y), to[y].push_back(x);
  }
  iv[1] = 1;
  for (int i = 2; i <= n; i++) {
    int j = mod / i + 1;
    iv[i] = 1ll * iv[i * j - mod] * j % mod;
  }
  for (int i = 0; i <= n; i++) f[0][i] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      f[i][j] = 1ll * (f[i - 1][j] + f[i][j - 1]) * iv[2] % mod;
  for (int i = 1; i < n; i++) {
    fa[i] = 0, d[i] = 0, dfs(i);
    for (int j = i + 1; j <= n; j++)
      for (int x = j, lt = 0; x != i; lt = x, x = fa[x])
        ans = (ans + 1ll * (sz[x] - sz[lt]) * iv[n] % mod * f[d[j] - d[x]][d[x]]) % mod;
  }
  cout << ans;
}