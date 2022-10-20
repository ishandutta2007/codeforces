#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define pii pair<int,int>
const int maxn = 110;
char c[maxn][maxn];
int n,m;
void opr(vector<pii> &ans, int x, int y)
{
  ans.push_back({x,y});
  c[x][y] ^= 1;
  int u = x+1, v = y+1;
  if(x == n-1) u = x-1;
  if(y == m-1) v = y-1;
  ans.push_back({u,y});
  c[u][y] ^= 1;
  ans.push_back({x,v});
  c[x][v] ^= 1;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while(T--)
  {
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) cin >> c[i][j];
    vector<pii> ans;
    for(int i = 0; i < n-2; i++)
    for(int j = 0; j < m; j++)
    {
      if(c[i][j] == '1')
      {
        if(j != m-1)
        {
          ans.push_back({i,j});
          ans.push_back({i+1,j});
          ans.push_back({i+1,j+1});
          c[i][j] ^= 1;
          c[i+1][j] ^= 1;
          c[i+1][j+1] ^= 1;
        }
        else
        {
          ans.push_back({i,j});
          ans.push_back({i+1,j});
          ans.push_back({i+1,j-1});
          c[i][j] ^= 1;
          c[i+1][j] ^= 1;
          c[i+1][j-1] ^= 1;
        }
      }
    }
    for(int j = 0; j < m-2; j++)
    {
      if(c[n-1][j] == '1')
      {
        ans.push_back({n-1,j});
        ans.push_back({n-1,j+1});
        ans.push_back({n-2,j+1});
        c[n-1][j] ^= 1;
        c[n-1][j+1] ^= 1;
        c[n-2][j+1] ^= 1;
      }
      if(c[n-2][j] == '1')
      {
        ans.push_back({n-2,j});
        ans.push_back({n-2,j+1});
        ans.push_back({n-1,j+1});
        c[n-2][j] ^= 1;
        c[n-1][j+1] ^= 1;
        c[n-2][j+1] ^= 1;
      }
    }
    int cnt = 0;
    if(c[n-1][m-1] == '1') cnt++;
    if(c[n-1][m-2] == '1') cnt++;
    if(c[n-2][m-1] == '1') cnt++;
    if(c[n-2][m-2] == '1') cnt++;
    if(cnt == 4)
    {
      ans.push_back({n-2,m-2});
      ans.push_back({n-2,m-1});
      ans.push_back({n-1,m-2});
      c[n-2][m-2] ^= 1;
      c[n-2][m-1] ^= 1;
      c[n-1][m-2] ^= 1;
      cnt = 1;
    }
    if(cnt == 1)
    {
      int x = 0, y = 0;
      for(int i = n-2; i < n; i++)
      {
        for(int j = m-2; j < m; j++)
          if(c[i][j] == '1')
          {
            x = i;
            y = j;
          }
      }
      opr(ans,x,y);
      cnt = 2;
    }
    if(cnt == 3)
    {
      if(c[n-2][m-2] == '0') opr(ans,n-1,m-1);
      else if(c[n-2][m-1] == '0') opr(ans,n-1,m-2);
      else if(c[n-1][m-2] == '0') opr(ans,n-2,m-1);
      else opr(ans,n-2,m-2);
      cnt = 0;
    }
    if(cnt == 2)
    {
      char target = '0';
      if(c[n-2][m-2] == '1' && c[n-1][m-1] == '1') target = '1';
      if(c[n-1][m-2] == '1' && c[n-2][m-1] == '1') target = '1';
      vector<pii> op;
      for(int i = n-2; i < n; i++)
      {
        for(int j = m-2; j < m; j++)
          if(c[i][j] == target)
          {
            op.push_back({i,j});
          }
      }
      for(auto p:op)
      {
        opr(ans,p.first,p.second);
      }
    }
    cout << ans.size() / 3 << '\n';
    for(int i = 0; i < ans.size(); i++)
    {
      cout << ans[i].first+1 << " " << ans[i].second+1 << ' ';
      i++;
      cout << ans[i].first+1 << " " << ans[i].second+1 << ' ';
      i++;
      cout << ans[i].first+1 << " " << ans[i].second+1 << '\n';
    }
  }
  return 0;
}