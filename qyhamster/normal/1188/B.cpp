#include <iostream>
#include <map>
using namespace std;
const int maxn = 300005;
int a[maxn];
map<long long, int> res;
long long MOD,n,k;
long long cal(long long x)
{
  long long y = x * x % MOD;
  y = y * y % MOD;
  y = (y - k * x) % MOD;
  y = (y % MOD + MOD) % MOD;
  return y;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> MOD >> k;
  long long ans = 0;
  for(int i = 0; i < n; i++)
  {
    cin >> a[i];
    long long x = cal(a[i]);
    ans += res[x];
    res[x] += 1;
  }
  cout << ans << endl;
  return 0;
}