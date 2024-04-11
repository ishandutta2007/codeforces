#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int a[maxn];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while(T--)
  {
    int n,d;
    cin >> n >> d;
    for(int i = 0; i < n; i++) cin >> a[i];
    int ans = a[0];
    for(int i = 1; i < n; i++)
    {
      while(a[i] > 0 && d >= i)
      {
        d -= i;
        a[i]--;
        ans++;
      }
      if(d < i) break;
    }
    cout << ans << '\n';
  }
  return 0;
}