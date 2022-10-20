#include <bits/stdc++.h>
using namespace std;
int main()
{
  int T;
  cin >> T;
  while(T--)
  {
    long long n,m;
    cin >> n >> m;
    long long ans = n * (n+1) / 2;
    long long k = n - m, c = k / (m+1);
    ans -= c * (c+1) / 2 * (m+1);
    k -= c * (m+1);
    ans -= (c+1) * k;
    cout << ans << '\n';
  }
  return 0;
}