#include <bits/stdc++.h>
using namespace std;
int d[4] = {0,1,1,-2};
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while(T--)
  {
    long long n;
    cin >> n;
    long long x = (n-1)/3+1, base = 1, num = 0;
    while(x > base)
    {
      x -= base;
      base = base * 4;
      num++;
    }
    long long ans = 0, p = x-1, q = p, r = 0;
    for(int j = 0; j < num; j++)
    {
      long long t = p/(1LL<<(j*2));
      t %= 4;
      q += (1LL<<(j*2)) * d[t];
    }
    p += (1LL<<(num*2));
    q += (1LL<<(num*2+1));
    r = p^q;
    if(n%3 == 1) cout << p << '\n';
    if(n%3 == 2) cout << q << '\n';
    if(n%3 == 0) cout << r << '\n';
  }
  return 0;
}