#ifdef LOCAL
#include <iostream>
#include <vector>
#include <cmath>
#else
#include <bits/stdc++.h>
#endif
using namespace std;
long long query(long long x, long long a, long long b)
{
  long long lcm = a*b/__gcd(a,b);
  long long ans = x / lcm * (lcm - b);
  x %= lcm;
  ans += max(0LL,x-b+1);
  return ans;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while(T--)
  {
    int a,b,Q;
    cin >> a >> b >> Q;
    if(a > b) swap(a,b);
    while(Q--)
    {
      long long l,r;
      cin >> l >> r;
      cout << query(r,a,b) - query(l-1,a,b) << '\n';
    }
  }
  return 0;
}