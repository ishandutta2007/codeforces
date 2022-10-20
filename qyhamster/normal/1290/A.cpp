#include <bits/stdc++.h>
using namespace std;
const int maxn = 3510;
int a[maxn];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while(T--)
  {
    int n,m,k;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    k = min(k, m-1);
    m -= k;
    int res = 0;
    for(int i = 0; i <= k; i++)
    {
      int mn = 2e9;
      for(int j = 0; j < m; j++)
      {
        mn = min(mn, max(a[i+j], a[i+n-k-(m-j)]));
      }
      res = max(res, mn);
    }
    cout << res << '\n';
  }
  return 0;
}