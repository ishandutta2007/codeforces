#include <bits/stdc++.h>
using namespace std;
long long a[200100];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while(T--)
  {
    long long n,p,k,ans = 0;
    cin >> n >> p >> k;
    for(int i = 0; i <= n; i++) a[i] = 0;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a,a+n);
    vector<int> bag;
    for(int i = k-1; i < n; i+=k)
    {
      if(p >= a[i])
      {
        p -= a[i];
        bag.push_back(i);
        ans += k;
      }
      else break;
    }
    long long s = 0;
    for(int i = 0; i < k; i++)
    {
      int ok = 1;
      for(int j = 0; j < bag.size(); j++)
      {
        p -= (a[bag[j]+1] - a[bag[j]]);
        bag[j]++;
        if(bag[j] >= n) ok = 0;
      }
      p -= a[i];
      if(p < 0) ok = 0;
      if(ok) ans++;
    }
    ans = min(ans, n);
    cout << ans << '\n';
  }
  return 0;
}