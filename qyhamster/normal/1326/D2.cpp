#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
const long long P = 1e9 + 7;
const long long Q = 998244353;
long long hs[maxn][2],rev[maxn][2],p[maxn],q[maxn];
int n;
string s;
bool is_palindrome(int l,int r)
{
  long long u1 = (hs[r][0] - hs[l-1][0] * p[r-l+1]) % P;
  long long u2 = (hs[r][1] - hs[l-1][1] * q[r-l+1]) % Q;
  long long v1 = (rev[n+1-l][0] - rev[n-r][0] * p[r-l+1]) % P;
  long long v2 = (rev[n+1-l][1] - rev[n-r][1] * q[r-l+1]) % Q;
  if(u1 < 0) u1 += P;
  if(u2 < 0) u2 += Q;
  if(v1 < 0) v1 += P;
  if(v2 < 0) v2 += Q;
  if(u1 == v1 && u2 == v2) return true;
  return false;
}
void build_hs()
{
  hs[0][0] = hs[0][1] = rev[0][0] = rev[0][1] = 0;
  for(int i = 1; i <= n; i++)
  {
    hs[i][0] = hs[i-1][0] * 890501 + s[i];
    hs[i][1] = hs[i-1][1] * 131 + s[i];
    hs[i][0] %= P;
    hs[i][1] %= Q;
    rev[i][0] = rev[i-1][0] * 890501 + s[n+1-i];
    rev[i][1] = rev[i-1][1] * 131 + s[n+1-i];
    rev[i][0] %= P;
    rev[i][1] %= Q;
  }
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  p[0] = q[0] = 1;
  for(int i = 1; i < maxn; i++)
  {
    p[i] = p[i-1] * 890501 % P;
    q[i] = q[i-1] * 131 % Q;
  }
  while(T--)
  {
    cin >> s;
    n = s.length();
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
    build_hs();
    int ans1 = min(n, match_len*2 + 1);
    for(int i = match_len+1; i <= n - match_len; i++)
    {
      if(is_palindrome(match_len+1, i)) ans1 = max(ans1, match_len + i);
    }

    for(int i = 1; i <= n/2; i++) swap(s[i], s[n+1-i]);

    build_hs();
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