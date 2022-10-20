#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
vector <int> a[N];
int val[N];
long long res = 0;
long long d[N], l[N];

long long lcm(long long u, long long v) {
  return u * v / __gcd(u, v);
}

void dfs(int u, int p) {
  l[u] = 1;
  if (a[u].size() == 1 && u != 1) {
    d[u] = val[u];
    return;
  }
  d[u] = (1ll << 62);
  int cnt = 0;
  for (int i = 0; i < a[u].size(); i++) {
    int v = a[u][i];
    if (v == p) {
      continue;
    }
    cnt++;
    dfs(v, u);
    if (d[v] == 0) {
      d[u] = 0;
      return;
    }
    l[u] = lcm(l[u], l[v]);
  }
  for (int i = 0; i < a[u].size(); i++) {
    int v = a[u][i];
    if (v == p) {
      continue;
    }
    d[u] = min(d[u], (d[v] / l[u]) * l[u]);
  }
  d[u] *= cnt;
  l[u] *= cnt;
}

int main() {
  ios_base::sync_with_stdio(0);
  #ifdef Doflamingo
  freopen("input", "r", stdin);
  #endif // Doflamingo
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> val[i];
    res += val[i];
  }
  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    a[u].push_back(v);
    a[v].push_back(u);
  }
  dfs(1, 0);
  cout << res - d[1] << endl;
  return 0;
}