#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
const int MOD = 1000000007;

int n;
vector <int> a[N], pre[N], suf[N];
int f[N], g[N], res[N];

void dfs(int u, int p) {
  f[u] = 1;
  for (int i = 0; i < a[u].size(); i++) {
    int v = a[u][i];
    if (v == p) {
      continue;
    }
    dfs(v, u);
    f[u] = 1ll * f[u] * (f[v] + 1) % MOD;
  }
  pre[u].push_back(1);
  for (int i = 1; i < a[u].size(); i++) {
    int v = a[u][i - 1];
    if (v == p) {
      pre[u].push_back(pre[u].back());
    } else {
      int x = pre[u].back();
      x = 1ll * x * (f[v] + 1) % MOD;
      pre[u].push_back(x);
    }
  }
  suf[u].push_back(1);
  for (int i = a[u].size() - 1; i; i--) {
    int v = a[u][i];
    if (v == p) {
      suf[u].push_back(suf[u].back());
    } else {
      int x = suf[u].back();
      x = 1ll * x * (f[v] + 1) % MOD;
      suf[u].push_back(x);
    }
  }
  reverse(suf[u].begin(), suf[u].end());
}

void redfs(int u, int p, int pos) {
  if (u == 1) {
    g[u] = 1;
  } else {
    g[u] = 1ll * pre[p][pos] * suf[p][pos]  % MOD;
    g[u] = 1ll * g[u] * g[p] % MOD;
    g[u] = (g[u] + 1) % MOD;
  }
  res[u] = 1ll * f[u] * g[u] % MOD;
  for (int i = 0; i < a[u].size(); i++) {
    int v = a[u][i];
    if (v == p) {
      continue;
    }
    redfs(v, u, i);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 2; i <= n; i++) {
    int p;
    cin >> p;
    a[i].push_back(p);
    a[p].push_back(i);
  }
  dfs(1, 0);
  redfs(1, 0, 0);
  for (int i = 1; i <= n; i++) {
    cout << res[i] << " ";
  }
  return 0;
}