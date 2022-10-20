#ifdef LOCAL
#include <iostream>
#include <vector>
#include <queue>
#else
#include <bits/stdc++.h>
#endif
using namespace std;
#define pii pair<int,int>
const int maxn = 2e5 + 5;
const int MOD = 998244353;
long long fact[maxn];
long long pw(long long a, long long n)
{
  long long base = a, ans = 1;
  while(n)
  {
    if(n&1) ans = ans * base % MOD;
    base = base * base % MOD;
    n /= 2;
  }
  return ans;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,k;
  cin >> n >> k;
  long long ans = 1;
  if(k == 0)
  {
    for(int i = 1; i <= n; i++) ans = ans * i % MOD;
    cout << ans << endl;
    exit(0);
  }
  if(k >= n)
  {
    cout << 0 << endl;
    exit(0);
  }
  ans = 0;
  fact[0] = 1;
  for(int i = 1; i < maxn; i++) fact[i] = fact[i-1] * i % MOD;
  for(int i = 0; i < n-k; i++)
  {
    if(i&1) ans -= pw(n-k-i,n) * fact[n-k] % MOD * pw(fact[i], MOD-2) % MOD * pw(fact[n-k-i],MOD-2) % MOD;
    else ans += pw(n-k-i,n) * fact[n-k] % MOD * pw(fact[i], MOD-2) % MOD * pw(fact[n-k-i],MOD-2) % MOD;
  }
  ans %= MOD;
  ans = ans * fact[n] % MOD * pw(fact[n-k],MOD-2) % MOD * pw(fact[k], MOD-2) % MOD;
  ans = ans * 2 % MOD;
  if(ans < 0) ans += MOD;
  cout << ans << endl;
  return 0;
}