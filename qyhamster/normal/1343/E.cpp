#ifdef LOCAL
#include <iostream>
#include <vector>
#include <queue>
#else
#include <bits/stdc++.h>
#endif
using namespace std;
const int maxn = 4e5 + 5;
vector<int> e[maxn];
bool vis[maxn];
int d[3][maxn];
long long sum[maxn];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while(T--)
  {
    int n,m,a,b,c;
    cin >> n >> m >> a >> b >> c;
    for(int i = 1; i <= m; i++) cin >> sum[i];
    sort(sum+1,sum+m+1);
    for(int i = 1; i <= m; i++) sum[i] += sum[i-1];
    for(int i = 1; i <= n; i++) e[i].clear();
    for(int i = 0; i < m; i++)
    {
      int u,v;
      cin >> u >> v;
      e[u].push_back(v);
      e[v].push_back(u);
    }
    for(int l = 0; l < 3; l++)
    {
      queue<int> q;
      for(int i = 0; i <= n; i++) d[l][i] = vis[i] = 0;
      int kw;
      if(l == 0)
      {
        kw = a;
      }
      if(l == 1) kw = b;
      if(l == 2) kw = c;
      q.push(kw);
      vis[kw] = 1;
      while(!q.empty())
      {
        int x = q.front();
        q.pop();
        for(auto k:e[x])
        {
          if(vis[k]) continue;
          d[l][k] = d[l][x]+1;
          vis[k] = 1;
          q.push(k);
        }
      }
    }
    long long ans = 1e18;
    for(int i = 1; i <= n; i++)
    {
      if(d[0][i] + d[2][i] + d[1][i] > m) continue;
      ans = min(ans, sum[d[1][i]]*2 + sum[d[0][i]+d[1][i]+d[2][i]]-sum[d[1][i]]);
    }
    cout << ans << endl;
  }
  return 0;
}