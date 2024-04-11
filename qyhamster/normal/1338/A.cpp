#include <bits/stdc++.h>
using namespace std;
const int maxn =  1e5 + 5;
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
    int mx = a[0], ans = 0;
    for(int i = 1; i < n; i++)
    {
      int x = mx - a[i], cnt = 0;
      while(x > 0)
      {
        x /= 2;
        cnt++;
      }
      ans = max(ans,cnt);
      mx = max(mx,a[i]);
    }
    cout << ans << '\n';
  }
  return 0;
}