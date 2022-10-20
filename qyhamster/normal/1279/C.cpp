#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn],rev[maxn],b[maxn];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while(T--)
  {
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
      cin >> a[i];
      rev[a[i]] = i;
    }
    long long mx = 0, ans = 0;
    for(int i = 0; i < m; i++)
    {
      cin >> b[i];
      if(rev[b[i]] > mx)
      {
        mx = rev[b[i]];
        ans += (mx-i)*2 - 1;
      }
      else ans++;
    }
    cout << ans << '\n';
  }
  return 0;
}