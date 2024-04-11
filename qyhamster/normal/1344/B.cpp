#ifdef LOCAL
#include <iostream>
#include <vector>
#include <queue>
#else
#include <bits/stdc++.h>
#endif
#define pii pair<int,int>
using namespace std;
const int maxn = 2e5 + 5;
string s[maxn];
int n,m;
bool valid()
{
  for(int i = 0; i < n; i++)
  {
    bool stop = 0;
    for(int j = 1; j < m; j++)
    {
      if(stop)
      {
        if(s[i][j] == '#') return false;
      }
      else if(s[i][j-1] == '#' && s[i][j] == '.') stop = 1;
    }
  }
  for(int j = 0; j < m; j++)
  {
    bool stop = 0;
    for(int i = 1; i < n; i++)
    {
      if(stop)
      {
        if(s[i][j] == '#') return false;
      }
      else if(s[i-1][j] == '#' && s[i][j] == '.') stop = 1;
    }
  }
  bool ver = 0, hor = 0;
  for(int i = 0; i < n; i++)
  {
    bool fnd = 0;
    for(int j = 0; j < m; j++)
    {
      if(s[i][j] == '#') fnd = 1;
    }
    if(!fnd) ver = 1;
  }
  for(int j = 0; j < m; j++)
  {
    bool fnd = 0;
    for(int i = 0; i < n; i++)
    {
      if(s[i][j] == '#') fnd = 1;
    }
    if(!fnd) hor = 1;
  }
  if(ver^hor) return false;
  return true;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> s[i];
  if(!valid())
  {
    cout << -1 << endl;
    exit(0);
  }
  queue<pii> qu;
  int ans = 0;
  int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < m; j++)
    {
      if(s[i][j] == '#')
      {
        s[i][j] = '.';
        qu.push({i,j});
        ans++;
        while(!qu.empty())
        {
          int u = qu.front().first, v = qu.front().second;
          qu.pop();
          for(int j = 0; j < 4; j++)
          {
            int p = u+dx[j], q = v+dy[j];
            if(p < 0 || q < 0 || p >= n || q >= m) continue;
            if(s[p][q] != '#') continue;
            s[p][q] = '.';
            qu.push({p,q});
          }
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}