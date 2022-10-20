#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int MOD = 998244353;
long long a[maxn],inv[maxn];
int t[maxn];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,k;
  cin >> n >> k;
  for(int i = 1; i <= n; i++)
  {
    cin >> a[i];
    inv[a[i]] = i;
  }
  long long ans = 0;
  for(int i = n; i > n-k; i--)
  {
    ans += i;
    t[inv[i]] = 1;
  }
  cout << ans << " ";
  int last = -1;
  long long num = 1;
  for(int i = 1; i <= n; i++)
  {
    if(t[i] == 0) continue;
    if(last != -1)
    {
      num = num * (i-last) % MOD;
    }
    last = i;
  }
  cout << num << endl;
  return 0;
}