#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <queue>
using namespace std;
const int maxn = 1000000;
const int MOD = 1000000007;
#define int long long
int c[62], a[maxn];
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while(T--)
  {
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 0; i < 62; i++) c[i] = 0;
    for(int i = 1; i <= n; i++)
    {
      cin >> a[i];
      int x = a[i], pos = 0;
      while(x)
      {
        c[pos] += (x&1);
        x >>= 1;
        pos++;
      }
    }
    for(int i = 1; i <= n; i++)
    {
      int AND = 0, OR = 0;
      for(int j = 0; j < 62; j++)
      {
        if((1LL<<j) & a[i])
        {
          AND += c[j] * ((1LL << j) % MOD);
          OR += n * ((1LL << j) % MOD);
        }
        else
        {
          OR += c[j] * ((1LL << j) % MOD);
        }
        AND %= MOD;
        OR %= MOD;
      }
      ans += AND * OR;
      ans %= MOD;
    }
    cout << ans << '\n';
  }
}