#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int mod = 998244353, N = 200005;
int n, f[N][2];
vector<int> to[N];
void dfs(int i) {
  if (!to[i].size()) {
    f[i][0] = f[i][1] = 1;
    return;
  }
  f[i][0] = 1;
  int x = 0, y = 0;
  for (int j : to[i]) {
    dfs(j);
    f[i][1] = (1ll * f[i][1] * f[j][1] + 1ll * f[i][1] * f[j][0] + 1ll * f[i][0] * f[j][1]) % mod;
    y = (1ll * y * (f[j][0] + f[j][1]) + 1ll * x * f[j][1]) % mod, x = (1ll * x * f[j][0] + 1ll * f[i][0] * f[j][1]) % mod;
    f[i][0] = 1ll * f[i][0] * f[j][0] % mod;
  }
  f[i][0] = (f[i][0] + y) % mod;
}
int main() {
  cin >> n;
  for (int i = 2; i <= n; i++) {
    int x;
    cin >> x;
    to[x].push_back(i);
  }
  dfs(1);
  cout << f[1][0];
}