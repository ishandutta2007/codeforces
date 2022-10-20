#ifdef LOCAL
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#else
#include <bits/stdc++.h>
#endif
#define pii pair<int,int>
using namespace std;
const int maxn = 1e3 + 5;
string s[maxn];
bool iso[maxn][maxn],vis[maxn][maxn];
int st[maxn][maxn];
int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m,Q;
  cin >> n >> m >> Q;
  for(int i = 1; i <= n; i++)
  {
    cin >> s[i];
    s[i] = "#" + s[i] + "#";
  }
  for(int i = 0; i <= m; i++)
  {
    s[0].push_back('#');
    s[n+1].push_back('#');
  }
  for(int i = 1; i <= n; i++)
  for(int j = 1; j <= m; j++)
  {
    st[i][j] = 1e9;
    iso[i][j] = 1;
    for(int k = 0; k < 4; k++)
    {
      int u = i+dx[k], v = j+dy[k];
      if(s[i][j] == s[u][v]) iso[i][j] = 0;
    }
  }
  queue<pii> q;
  for(int i = 1; i <= n; i++)
  for(int j = 1; j <= m; j++)
  {
    if(iso[i][j] == 0)
    {
      q.push({i,j});
      st[i][j] = 0;
      vis[i][j] = 1;
    }
  }
  while(!q.empty())
  {
    int x = q.front().first, y = q.front().second;
    q.pop();
    for(int k = 0; k < 4; k++)
    {
      int u = x+dx[k], v = y+dy[k];
      if(s[u][v] == '#') continue;
      if(vis[u][v]) continue;
      vis[u][v] = 1;
      st[u][v] = st[x][y]+1;
      q.push({u,v});
    }
  }
  while(Q--)
  {
    long long x,y,t;
    cin >> x >> y >> t;
    if(t <= st[x][y] || st[x][y] > 5e8) cout << s[x][y] << '\n';
    else
    {
      if((t-st[x][y])&1) cout << (char)(s[x][y]^1) << '\n';
      else cout << s[x][y] << '\n';
    }
  }
  return 0;
}