#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn];
int main()
{
  int T;
  cin >> T;
  while(T--)
  {
    int n,x;
    cin >> n >> x;
    string s;
    cin >> s;
    if(s[0] == '0') a[0] = 1;
    else a[0] = -1;
    for(int i = 1; i < n; i++)
    {
      a[i] = a[i-1] + (s[i] == '0')*2 - 1;
    }
    if(a[n-1] == 0)
    {
      int ok = 0;
      for(int i = 0; i < n; i++) if(a[i] == x) ok = 1;
      if(ok) cout << -1 << '\n';
      else cout << 0 << '\n';
      continue;
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
      if((x - a[i]) % a[n-1] == 0 && (long long)(x-a[i])*a[n-1] >= 0) ans++;
    }
    if(x == 0) ans++;
    cout << ans << '\n';
  }
  return 0;
}