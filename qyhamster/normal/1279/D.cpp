#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
const int MOD = 998244353;
long long c[maxn];
vector<int> e[maxn];
long long power_mod(long long a, long long n)
{
  long long base = a, result = 1;
  while(n)
  {
    if(n&1) result = result * base % MOD;
    base = base * base % MOD;
    n /= 2;
  }
  return result;
}
long long inverse(long long n)
{
  return power_mod(n, MOD-2);
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  long long invn = inverse(n);
  for(int i = 0; i < n; i++)
  {
    int k;
    cin >> k;
    for(int j = 0; j < k; j++)
    {
      int x;
      cin >> x;
      e[i].push_back(x);
      c[x]++;
    }
  }
  long long ans = 0;
  for(int i = 0; i < n; i++)
  {
    if(e[i].size() == 0) continue;
    long long base = invn * inverse(e[i].size()) % MOD;
    base = base * invn % MOD;
    for(int j = 0; j < e[i].size(); j++)
    {
      ans += base * c[e[i][j]] % MOD;
    }
  }
  ans %= MOD;
  cout << ans << '\n';
  return 0;
}