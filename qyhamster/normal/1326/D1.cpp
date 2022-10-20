#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int MOD = 998244353;
long long a[maxn],inv[maxn];
int t[maxn];
string s;
bool is_palindrome(int l,int r)
{
  for(int i = l; i <= r; i++)
  {
    if(s[i] != s[r+l-i]) return false;
  }
  return true;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while(T--)
  {
    cin >> s;
    int n = s.length();
    s = "#" + s;
    int match_len = 0;
    for(int j = 1; j <= n/2; j++)
    {
      if(s[j] == s[n+1-j])
      {
        match_len = j;
      }
      else break;
    }
    int ans1 = min(n, match_len*2 + 1);
    for(int i = match_len+1; i <= n - match_len; i++)
    {
      if(is_palindrome(match_len+1, i)) ans1 = max(ans1, match_len + i);
    }
    for(int i = 1; i <= n/2; i++) swap(s[i], s[n+1-i]);
    int ans2 = min(n, match_len*2 + 1);
    for(int i = match_len+1; i <= n - match_len; i++)
    {
      if(is_palindrome(match_len+1, i)) ans2 = max(ans2, match_len + i);
    }
    if(ans1 > ans2)
    {
      for(int i = 1; i <= n/2; i++) swap(s[i], s[n+1-i]);
    }
    ans1 = max(ans1,ans2);
    for(int i = 1; i <= ans1 - match_len; i++) cout << s[i];
    for(int i = n - match_len + 1; i <= n; i++) cout << s[i];
    cout << '\n';
  }
  return 0;
}