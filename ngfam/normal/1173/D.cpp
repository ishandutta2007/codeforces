#include <bits/stdc++.h>

using namespace std;

const int N = 200020;
const long long mod = 998244353;

int n;
long long f[N];
long long fact[N];
vector < int > g[N];

void dfs(int v, int p = -1) {
  f[v] = 1;
  for(int s : g[v]) if(s != p) {
    dfs(s, v);
    f[v] = f[v] * f[s] % mod;
  }

  int sz = g[v].size() - 1;
  f[v] = f[v] * fact[sz] % mod;
  f[v] = f[v] * (sz + 1) % mod;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  cin >> n;
  for(int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u); 
  }

  fact[0] = 1;
  for(int i = 1; i < N; ++i) {
    fact[i] = fact[i - 1] * i % mod;
  }

  dfs(1);
  cout << f[1] * n % mod;

  return 0;
}