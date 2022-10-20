#ifdef LOCAL
#include <iostream>
#include <vector>
#else
#include <bits/stdc++.h>
#endif
using namespace std;
const int maxn = 3e5 + 5;
int a[maxn];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while(T--)
  {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    int sign = 1;
    if(a[0] < 0) sign = -1;
    int mx = a[0];
    long long ans = 0;
    for(int i = 0; i < n; i++)
    {
      if(sign * a[i] > 0)
      {
        mx = max(mx,a[i]);
      }
      else
      {
          ans += mx;
          mx = a[i];
        sign = -sign;
      }
    }
    ans += mx;
    cout << ans << '\n';
  }
  return 0;
}