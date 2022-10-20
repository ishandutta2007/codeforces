#ifdef LOCAL
#include <iostream>
#include <vector>
#include <queue>
#else
#include <bits/stdc++.h>
#endif
#define pii pair<int,int>
using namespace std;
const int maxn = 10010;
int d[maxn],dis[maxn][1005];
bool vis[maxn][1005];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  for(int i = 0; i < m; i++) cin >> d[i];
  sort(d,d+m);
  int g,r;
  cin >> g >> r;
  if(n <= g)
  {
    cout << n << endl;
    exit(0);
  }
  memset(dis,0x3f3f3f3f,sizeof(dis));
  dis[0][0] = 0;
  vis[0][0] = 1;
  queue<pii> q,tq;
  q.push({0,0});
  long long ans = 1e18;
  while(!q.empty() || !tq.empty())
  {
    if(q.empty())
    {
      while(!tq.empty())
      {
        q.push(tq.front());
        tq.pop();
      }
      if(q.empty()) break;
    }
    int x = q.front().first, y = q.front().second;
    q.pop();
    if(d[x] + g-y >= n)
    {
      ans = min(ans, (long long)dis[x][y] * (g+r) + y + n-d[x]);
    }
    if(x != 0)
    {
      int t = y+d[x]-d[x-1];
      if(t <= g && !vis[x-1][t])
      {
        if(t == g)
        {
          if(!vis[x-1][0])
          {
            dis[x-1][0] = dis[x][y]+1;
            vis[x-1][0] = 1;
            tq.push({x-1,0});
          }
        }
        else
        {
          dis[x-1][t] = dis[x][y];
          vis[x-1][t] = 1;
          q.push({x-1,t});
        }
      }
    }
    if(x != m-1)
    {
      int t = y+d[x+1]-d[x];
      if(t <= g && !vis[x+1][t])
      {
        if(t == g)
        {
          if(vis[x+1][0]) continue;
          dis[x+1][0] = dis[x][y]+1;
          vis[x+1][0] = 1;
          tq.push({x+1,0});
        }
        else
        {
          dis[x+1][t] = dis[x][y];
          vis[x+1][t] = 1;
          q.push({x+1,t});
        }
      }
    }
  }
  if(ans > 1e17) ans = -1;
  cout << ans << '\n';
  return 0;
}