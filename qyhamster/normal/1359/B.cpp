#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
string s[510];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while(T--)
  {
    int n,m,x,y;
    cin >> n >> m >> x >> y;
    for(int i = 0; i < n; i++) cin >> s[i];
    int ans = 0;
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      ans += (s[i][j]=='.');
    if(x * 2 <= y)
    {
      cout << ans * x << endl;
      continue;
    }
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < m-1; j++)
      {
        if(s[i][j] == s[i][j+1] && s[i][j] == '.')
        {
          cnt++;
          j++;
        }
      }
    }
    cout << (ans-cnt*2) * x + cnt * y << endl;
  }
  return 0;
}