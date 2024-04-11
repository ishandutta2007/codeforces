#include <bits/stdc++.h>
using namespace std;
int a[20][20];
vector<long long> dp[20010][15];
vector<int> e[15];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for(int i = 0; i < n; i++)
  for(int j = 0; j < n; j++)
  {
    char c;
    cin >> c;
    a[i][j] = c - '0';
  }
  for(int i = 1; i < (1<<n); i++)
  {
    int x = i,cnt = 0;
    while(x)
    {
      cnt++;
      x -= (x&(-x));
    }
    e[cnt].push_back(i);
    for(int k = 0; k < n; k++)
      dp[i][k].resize(1<<(cnt-1));
  }
  for(int i = 0; i < n; i++) dp[(1<<i)][i][0] = 1;
  for(int j = 1; j < n; j++)
  {
    for(auto i:e[j])
    {
      for(int k = 0; k < n; k++)
      {
        if((i&(1<<k)) == 0) continue;
        for(int l = 0; l < n; l++)
        {
          if(i&(1<<l)) continue;
          for(int p = 0; p < (1<<(j-1)); p++)
          {
            dp[i|(1<<l)][l][(p<<1)+(a[l][k])] += dp[i][k][p];
          }
        }
      }
    }
  }
  for(int p = 0; p < (1<<(n-1)); p++)
  {
    long long ans = 0;
    for(int k = 0; k < n; k++)
      ans += dp[(1<<n)-1][k][p];
    cout << ans << " ";
  }
  return 0;
}