#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int mod = 1e9 + 7;

int n;
int depth[N];
long long a[N];
vector < int > g[N];
vector < pair < long long, int > > st[N];

long long ans = 0;

void dfs(int u, int p) {
  depth[u] = depth[p] + 1;
  st[u].push_back(make_pair(a[u], depth[u]));
  for(auto w : st[p]) {
    w.first = gcd(w.first, a[u]);
    if(w.first == st[u].back().first) continue;
    st[u].push_back(w);
  }

  for(int i = 0; i + 1 < st[u].size(); ++i) {
    ans += 1LL * (st[u][i].second - st[u][i + 1].second) * st[u][i].first;
    ans %= mod;
  }
  ans += 1LL * st[u].back().first * st[u].back().second;
  ans %= mod;

  for(auto &v : g[u]) if(v != p) dfs(v, u);
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> n;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  for(int i = 1; i < n; ++i) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  dfs(1, 0);

  cout << ans << endl;

  return 0;
}