#include <iostream>
using namespace std;
const int maxn = 200100;
const long long inv100 = 828542813;
const int MOD = 998244353;
int a[maxn];
long long pow(long long a, long long n)
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
int main()
{
  int n;
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> a[i];
  long long win = 1, rnd = 1, res = 0;
  for(int i = 0; i < n; i++)
  {
    win = win * a[i] % MOD;
    win = win * inv100 % MOD;
    if(i != n-1) rnd = rnd + win;
  }
  rnd = (rnd % MOD + MOD) % MOD;
  res += rnd * pow(win, MOD-2) % MOD;
  cout << res << endl;
  return 0;
}