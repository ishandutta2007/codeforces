#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 1e6 + 5;
const int MOD = 998244353;
long long fact[maxn],inv[maxn];
long long pw(long long a, long long n)
{
  long long base = a, res = 1;
  while(n)
  {
    if(n&1) res = res * base % MOD;
    base = base * base % MOD;
    n /= 2;
  }
  return res;
}
int C(int n,int k)
{
  if(n < k) return 0;
  return fact[n] * inv[k] % MOD * inv[n-k] % MOD;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  fact[0] = inv[0] = 1;
  for(int i = 1; i < maxn; i++)
  {
    fact[i] = fact[i-1] * i % MOD;
    inv[i] = pw(fact[i], MOD-2);
  }
  int n,k;
  cin >> n >> k;
  long long ans = 0;
  for(int i = 1; i <= n; i++)
  {
    ans += C(n/i-1, k-1);
  }
  ans %= MOD;
  cout << ans << endl;
  return 0;
}