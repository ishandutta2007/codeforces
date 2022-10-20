#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn],sum[maxn][26];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  int n = s.length();
  s = "#" + s;
  a[n] = n+1;
  for(int i = n-1; i > 0; i--)
  {
    if(s[i] != s[i+1]) a[i] = i+1;
    else a[i] = a[i+1];
  }
  for(int i = 1; i <= n; i++)
  {
    sum[i][s[i]-'a']++;
  }
  for(int i = 1; i <= n; i++)
  {
    for(int j = 0; j < 26; j++) sum[i][j] += sum[i-1][j];
  }
  int T;
  cin >> T;
  while(T--)
  {
    int l,r;
    cin >> l >> r;
    if(l == r)
    {
      cout << "Yes" << '\n';
      continue;
    }
    if(a[l] > r)
    {
      cout << "No" << '\n';
    }
    else
    {
      if(s[l] != s[r])
      {
        cout << "Yes" << '\n';
        continue;
      }
      else
      {
        int cnt = 0;
        for(int j = 0; j < 26; j++)
        {
          if(sum[r][j] != sum[l-1][j]) cnt++;
        }
        if(cnt == 2) cout << "No" << '\n';
        else cout << "Yes" << '\n';
      }
    }
  }
  return 0;
}