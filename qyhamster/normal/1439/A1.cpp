#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define pii pair<int,int>
const int maxn = 110;
char c[maxn][maxn];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while(T--)
  {
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) cin >> c[i][j];
    vector<pii> ans;
    for(int i = 0; i < n-1; i++)
    for(int j = 0; j < m-1; j++)
    {
      if(c[i][j] == '1')
      {
        ans.push_back({i,j});
        ans.push_back({i,j+1});
        ans.push_back({i+1,j});
        ans.push_back({i,j});
        ans.push_back({i,j+1});
        ans.push_back({i+1,j+1});
        ans.push_back({i,j});
        ans.push_back({i+1,j});
        ans.push_back({i+1,j+1});
      }
      c[i][j] = '0';
    }
    for(int j = 0; j < m-1; j++)
    {
      if(c[n-1][j] == '1')
      {
        int i = n-1;
        ans.push_back({i,j});
        ans.push_back({i,j+1});
        ans.push_back({i-1,j});
        ans.push_back({i,j});
        ans.push_back({i,j+1});
        ans.push_back({i-1,j+1});
        ans.push_back({i,j});
        ans.push_back({i-1,j});
        ans.push_back({i-1,j+1});
      }
      c[n-1][j] = '0';
    }
    for(int i = 0; i < n-1; i++)
    {
      if(c[i][m-1] == '1')
      {
        int j = m-1;
        ans.push_back({i,j});
        ans.push_back({i,j-1});
        ans.push_back({i+1,j});
        ans.push_back({i,j});
        ans.push_back({i,j-1});
        ans.push_back({i+1,j-1});
        ans.push_back({i,j});
        ans.push_back({i+1,j});
        ans.push_back({i+1,j-1});
      }
      c[i][m-1] = '0';
    }
    if(c[n-1][m-1] == '1')
    {
      int i = n-1, j = m-1;
      ans.push_back({i,j});
      ans.push_back({i,j-1});
      ans.push_back({i-1,j});
      ans.push_back({i,j});
      ans.push_back({i,j-1});
      ans.push_back({i-1,j-1});
      ans.push_back({i,j});
      ans.push_back({i-1,j});
      ans.push_back({i-1,j-1});
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