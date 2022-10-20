#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
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
    for(int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    int mx = 0, mn = 2e9;
    for(int i = 1; i < n; i++)
    {
      if(a[i] == -1 || a[i-1] == -1)
      {
        int x = a[i] + a[i-1] + 1;
        if(x < 0) continue;
        mx = max(mx, x);
        mn = min(mn, x);
      }
    }
    int mid = (mx + mn) / 2;
    for(int i = 0; i < n; i++) if(a[i] == -1) a[i] = mid;
    int res = 0;
    for(int i = 1; i < n; i++)
      res = max(res, abs(a[i] - a[i-1]));
    cout << res << " " << mid << '\n';
  }
  return 0;
}