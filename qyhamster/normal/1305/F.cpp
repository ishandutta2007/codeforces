#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn*3];
set<int> d;
int pollard_rho(int n)
{
    int a0 = 2;
    int c = rand() % n + 1;
    int x = a0, y = a0;
    int m = 1, k = 2;
    int sq = (sqrt(sqrt(n)+1) + 2) * 8;
    for(int i = 1; i <= sq; i++)
    {
        x = (x * x + c) % n;
        int d = __gcd(abs(x - y), n);
        if (d > 1 && d <= n) return d;
        if (++m == k) y = x, k <<= 1;
    }
    return n;
}
void get_divisor(int x)
{
  if(x <= 1) return;
  int t = pollard_rho(x);
  if(t == x)
  {
    d.insert(x);
    return;
  }
  get_divisor(t);
  get_divisor(x/t);
}
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  srand(time(nullptr));
  int n;
  cin >> n;
  for(int i = 0; i < n; i++)
  {
    cin >> a[i];
    a[i+n] = a[i] - 1;
    a[i+n+n] = a[i] + 1;
  }
  for(int i = 0; i < 200; i++)
  {
    int idx = (long long)rand() * (long long)rand() % (n*3);
    get_divisor(a[idx]);
  }
  int ans = n;
  for(auto k:d)
  {
    int tmp = 0;
    for(int i = 0; i < n; i++)
    {
      if(a[i] > k) tmp += min(k - a[i]%k, a[i]%k);
      else tmp += k - a[i];
    }
    ans = min(ans,tmp);
  }
  cout << ans << endl;
  return 0;
}