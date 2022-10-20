#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int maxn = 1e3 + 5;
int a[maxn][maxn], dis[maxn][maxn][41];
int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
bool vis[maxn][maxn];
vector<pii> member[42];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m,k;
  cin >> n >> m >> k;
  for(int i = 1; i <= n; i++)
  {
    for(int j = 1; j <= m; j++)
    {
      cin >> a[i][j];
      member[a[i][j]].push_back({i,j});
    }
  }
  memset(dis,0x3f,sizeof(dis));
  for(int l = 1; l <= k; l++)
  {
    queue<pii> q;
    memset(vis,0,sizeof(vis));
    for(int i = 0; i <= n+1; i++) vis[i][0] = vis[i][m+1] = 1;
    for(int j = 0; j <= m+1; j++) vis[0][j] = vis[n+1][j] = 1;
    for(int i = 1; i <= n; i++)
    {
      for(int j = 1; j <= m; j++)
      {
        if(a[i][j] == l)
        {
          dis[i][j][l] = 0;
          vis[i][j] = 1;
          q.push({i,j});
        }
      }
    }
    int color[42] = {0};
    while(!q.empty())
    {
      int x = q.front().first, y = q.front().second;
      q.pop();
      if(color[a[x][y]] == 0)
      {
        color[a[x][y]] = 1;
        for(auto cood:member[a[x][y]])
        {
          if(vis[cood.first][cood.second]) continue;
          vis[cood.first][cood.second] = 1;
          dis[cood.first][cood.second][l] = dis[x][y][l] + 1;
          q.push({cood.first,cood.second});
        }
      }
      for(int i = 0; i < 4; i++)
      {
        int u = x + dx[i], v = y + dy[i];
        if(vis[u][v]) continue;
        vis[u][v] = 1;
        dis[u][v][l] = dis[x][y][l] + 1;
        q.push({u,v});
      }
    }
  }
  int Q;
  cin >> Q;
  while(Q--)
  {
    int u,v,x,y;
    cin >> u >> v >> x >> y;
    int ans = abs(u - x) + abs(v - y);
    for(int i = 1; i <= k; i++)
    {
      ans = min(ans, dis[x][y][i] + dis[u][v][i] + 1);
    }
    cout << ans << '\n';
  }
  return 0;
}