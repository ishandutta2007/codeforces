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
    long long n,d;
    cin >> n >> d;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a,a+n);
    long long ans = max(2LL, (d-1) / a[n-1] + 1);
    for(int i = 0; i < n; i++) if(a[i] == d) ans = 1;
    cout << ans << '\n';
  }
  return 0;
}