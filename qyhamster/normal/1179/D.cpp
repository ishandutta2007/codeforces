#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define pll pair<long long, long long>
using namespace std;
const int maxn = 500010;
vector<int> e[maxn];
int fa[maxn],siz[maxn];
long long dp[maxn],n,ans=1e18;
vector<pll> line;
long long Cn_2(long long x)
{
  return x * (x-1) / 2;
}
double inter(pll u, pll v)
{
  return (double)(u.second - v.second)/(double)(v.first - u.first);
}
void pre_dfs(int x)
{
  siz[x] = 1;
  for(auto k:e[x])
  {
    if(k == fa[x]) continue;
    fa[k] = x;
    pre_dfs(k);
    siz[x] += siz[k];
  }
}
int bs(int l,int r, double x)
{
  if(l == r)return l;
  int m = (l+r)/2;
  if(m+1 == line.size())return bs(l,m,x);
  if(inter(line[m],line[m+1]) > x) return bs(l,m,x);
  return bs(m+1,r,x);
}
void dfs(int x)
{
  dp[x] = 1e18;
  if(x != 1 && e[x].size() == 1)
  {
    dp[x] = 0;
    return;
  }
  vector<pll> v;
  for(auto k:e[x])
  {
    if(k == fa[x])continue;
    dfs(k);
    dp[x] = min(dp[x], Cn_2(siz[x] - siz[k]) + dp[k]);
    ans = min(ans, Cn_2(n - siz[k]) + dp[k]);
    v.push_back(make_pair(siz[k], dp[k] - siz[k] * (n * 2 - 1 - siz[k]) / 2));
  }
  sort(v.begin(),v.end());
  reverse(v.begin(),v.end());
  line.clear();
  if(v.size()) line.push_back(v[0]);
  for(int i = 1; i < v.size(); i++)
  {
    int ln = bs(0, (int)line.size() - 1, v[i].first);
    ans = min(ans, line[ln].first * v[i].first + line[ln].second + v[i].second + Cn_2(n));
    while(line.size() >= 2)
    {
      int sz = line.size();
      if(inter(line[sz-1],line[sz-2]) >= inter(line[sz-2],v[i]) - 1e-8)
        line.pop_back();
      else break;
    }
    while(line.size() && line[(int)line.size()-1].first == v[i].first) line.pop_back();
    line.push_back(v[i]);
  }
}
int main()
{
  cin >> n;
  for(int i = 1; i < n; i++)
  {
    int u,v;
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  pre_dfs(1);
  dfs(1);
  //for(int i = 0; i <= n; i++) cout << i << " " << dp[i] << endl;
  cout << 2 * Cn_2(n) - ans << endl;
}