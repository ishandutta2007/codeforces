#include <bits/stdc++.h>
using namespace std;
int main()
{
  int T;
  cin >> T;
  while(T--)
  {
    long long a,n,n_copy;
    cin >> a >> n;
    long long g = __gcd(a,n);
    n /= g;
    n_copy = n;
    long long sq = sqrt(n+0.5);
    vector<long long> p;
    for(int i = 2; i <= sq; i++)
    {
      if(n % i) continue;
      while(n % i == 0) n /= i;
      p.push_back(i);
    }
    if(n > 1) p.push_back(n);
    long long ans = n_copy;
    for(auto x:p)
    {
      ans = ans / x * (x-1);
    }
    cout << ans << '\n';
  }
  return 0;
}