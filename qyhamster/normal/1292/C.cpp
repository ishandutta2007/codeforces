#ifdef LOCAL
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <map>
#else
#include <bits/stdc++.h>
#endif
#define pii pair<long long,long long>
using namespace std;
typedef unsigned long long uint64;
const int maxn = 3e3 + 5;
vector<int> e[maxn];
int u[maxn],v[maxn],fa[maxn][13],sz[maxn],dpt[maxn],in[maxn],n;
long long dp[maxn][maxn];
void dfs(int x,int src)
{
  sz[x] = 1;
  for(auto k:e[x])
  {
    if(k == src) continue;
    fa[k][0] = x;
    dpt[k] = dpt[x] + 1;
    dfs(k,x);
    sz[x] += sz[k];
  }
}
int get_sz(int x,int y)
{
  if(fa[x][0] == y) return sz[x];
  return n - sz[y];
}
int get_nxt(int x, int y)
{
  int deft = fa[x][0];
  for(int j = 11; j >= 0; j--)
  {
    if(dpt[y] - (1<<j) > dpt[x]) y = fa[y][j];
  }
  if(fa[y][0] == x) return y;
  return deft;
}
long long get_dp(int x,int y)
{
  if(dp[x][y]) return dp[x][y];
  long long res = 0;
  int u = get_nxt(x,y), v = get_nxt(y,x);
  res = max(res, get_dp(u,y));
  res = max(res, get_dp(x,v));
  res += (long long)get_sz(x,u) * (long long)get_sz(y,v);
  dp[x][y] = dp[y][x] = res;
  return res;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for(int i = 0; i < n-1; i++)
  {
    cin >> u[i] >> v[i];
    e[u[i]].push_back(v[i]);
    e[v[i]].push_back(u[i]);
  }
  dfs(1,-1);
  for(int j = 1; j < 13; j++)
  for(int i = 1; i <= n; i++) fa[i][j] = fa[fa[i][j-1]][j-1];
  for(int i = 0; i < n-1; i++)
  {
    dp[u[i]][v[i]] = dp[v[i]][u[i]] = get_sz(u[i],v[i]) * get_sz(v[i],u[i]);
  }
  long long ans = 0;
  for(int i = 1; i <= n; i++)
  for(int j = i+1; j <= n; j++)
  {
    if(i == j) continue;
    ans = max(ans, get_dp(i,j));
  }
  cout << ans << endl;
  return 0;
}