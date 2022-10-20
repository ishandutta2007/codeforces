#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int nxt[maxn][26];
int main()
{
  int T;
  cin >> T;
  while(T--)
  {
    string s,t;
    cin >> s >> t;
    int n = s.length();
    string p = "#" + s + s;
    int a[26];
    for(int j = 0; j < 26; j++) a[j] = -1;
    for(int i = n*2; i > 0; i--)
    {
      if(i <= n)
      {
        for(int j = 0; j < 26; j++)
          nxt[i][j] = a[j];
      }
      a[p[i] - 'a'] = i>n?i-n:i;
    }
    for(int j = 0; j < 26; j++)
      nxt[0][j] = a[j];
    int last = 0;
    int ans = 1;
    for(int i = 0; i < t.length(); i++)
    {
      int x = nxt[last][t[i]-'a'];
      if(x == -1)
      {
        ans = -1;
        break;
      }
      if(x <= last) ans++;
      last = x;
    }
    cout << ans << '\n';
  }
  return 0;
}