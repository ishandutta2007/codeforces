#include<bits/stdc++.h>

using namespace std;

const int MAXN = 300030;
const int mod = 998244353;

int add(int x, int y) {
  x += y;
  if(x >= mod) x -= mod;
  if(x < 0) x += mod;
  return x;
}

int sub(int x, int y) {
  x -= y;
  if(x >= mod) x -= mod;
  if(x < 0) x += mod;
  return x;
}

int mult(int x, int y) {
  return 1LL * x * y % mod;
}

int binpow(int x, int y) {
  int ret = 1;
  for(; y > 0; x = mult(x, x), y >>= 1) {
    if(y & 1) ret = mult(ret, x);
  }
  return ret;
}

int inverse_modulo(int x) {
  return binpow(x, mod - 2);
}

int n;
int f[MAXN][3];
vector<int> g[MAXN];

void dfs_solve(int v, int p) {
  if(p != -1) g[v].erase(find(g[v].begin(), g[v].end(), p));

  if(g[v].empty()) {
    f[v][0] = 1;
    f[v][1] = 1;
    return;
  }

  f[v][0] = f[v][1] = 1;

  for(int s : g[v]) {
    dfs_solve(s, v);
  }

  int all = 1;

  for(int s : g[v]) {
    f[v][0] = mult(f[v][0], add(f[s][0], f[s][2] % mod));
    f[v][1] = mult(f[v][1], add(f[s][0], 2 * f[s][2] % mod));
    all = mult(all, add(f[s][0], f[s][2] * 2 % mod));
  }

  for(int s : g[v]) {
    int calc = f[s][1];
    int rall = mult(all, inverse_modulo(add(f[s][0], f[s][2] * 2 % mod)));
    f[v][2] = add(f[v][2], mult(calc, rall));
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> n;
  for(int i = 0; i + 1 < n; ++i) {
    int u, v;
    cin >> u >> v;
    g[--u].push_back(--v);
    g[v].push_back(u);
  }

  dfs_solve(0, -1);

  cout << add(f[0][0], f[0][2]) << endl;

  return 0;
}