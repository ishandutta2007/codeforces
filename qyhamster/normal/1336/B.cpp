#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
set<long long> u,v,w;
long long cal(long long M, long long N, long long P)
{
  return ((M - N) * (M - N) + (P - N) * (P - N) + (M - P) * (M - P));
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while(T--)
  {
    u.clear();
    v.clear();
    w.clear();
    int p,q,r;
    cin >> p >> q >> r;
    long long x, ans = 4e18;
    for(int i = 0; i < p; i++)
    {
      cin >> x;
      u.insert(x);
    }
    for(int i = 0; i < q; i++)
    {
      cin >> x;
      v.insert(x);
    }
    for(int i = 0; i < r; i++)
    {
      cin >> x;
      w.insert(x);
    }
    for(auto k:u)
    {
      if(v.upper_bound(k) != v.begin() && w.lower_bound(k) != w.end())
      {
        ans = min(ans, cal(k, *(prev(v.upper_bound(k))), *w.lower_bound(k)));
      }
      if(w.upper_bound(k) != w.begin() && v.lower_bound(k) != v.end())
      {
        ans = min(ans, cal(k, *(prev(w.upper_bound(k))), *v.lower_bound(k)));
      }
    }
    for(auto k:v)
    {
      if(u.upper_bound(k) != u.begin() && w.lower_bound(k) != w.end())
      {
        ans = min(ans, cal(k, *(prev(u.upper_bound(k))), *w.lower_bound(k)));
      }
      if(w.upper_bound(k) != w.begin() && u.lower_bound(k) != u.end())
      {
        ans = min(ans, cal(k, *(prev(w.upper_bound(k))), *u.lower_bound(k)));
      }
    }
    for(auto k:w)
    {
      if(v.upper_bound(k) != v.begin() && u.lower_bound(k) != u.end())
      {
        ans = min(ans, cal(k, *(prev(v.upper_bound(k))), *u.lower_bound(k)));
      }
      if(u.upper_bound(k) != u.begin() && v.lower_bound(k) != v.end())
      {
        ans = min(ans, cal(k, *(prev(u.upper_bound(k))), *v.lower_bound(k)));
      }
    }
    cout << ans << '\n';
  }
  return 0;
}