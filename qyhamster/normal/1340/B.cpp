#ifdef LOCAL
#include <iostream>
#include <vector>
#include <queue>
#else
#include <bits/stdc++.h>
#endif
using namespace std;
const int maxn = 2010;
bool dp[maxn][maxn];
string s[maxn];
string d[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011" };
int get_dis(string a, string b)
{
  int cnt = 0;
  for(int i = 0; i < 7; i++)
  {
    if(a[i] == b[i]) continue;
    if(a[i] == '1' && b[i] == '0') return -1;
    cnt++;
  }
  return cnt;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,k;
  cin >> n >> k;
  for(int i = 0; i < n; i++) cin >> s[i];
  dp[n][0] = 1;
  for(int l = n-1; l >= 0; l--)
  {
    for(int i = 0; i < 10; i++)
    {
      int val = get_dis(s[l], d[i]);
      if(val == -1) continue;
      for(int j = val; j <= k; j++) if(dp[l+1][j-val]) dp[l][j] = 1;
    }
  }
  if(dp[0][k] == false)
  {
    cout << -1 << endl;
    exit(0);
  }
  for(int l = 0; l < n; l++)
  {
    for(int i = 9; i >= 0; i--)
    {
      int val = get_dis(s[l], d[i]);
      if(val == -1) continue;
      if(dp[l+1][k-val])
      {
        cout << i;
        k -= val;
        break;
      }
    }
  }
  cout << endl;
  return 0;
}