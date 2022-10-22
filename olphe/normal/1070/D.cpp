#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

signed main() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for(int i=0; i<n; ++i) cin >> a[i];

  ll ret = 0, remain = 0;
  for(int i=0; i<n; ++i) {
    // cout << i << " " << ret << " " << remain << endl;
    // i
    ll tmp = (a[i]+remain)/k;
    // cout << tmp << endl;
    ret += tmp;
    // i-1
    ll add = 0;
    if(remain > tmp*k) {
      ret += (remain-tmp*k+k-1) / k;
      add += k - (remain - tmp*k) % k;
    }
    remain = max(0LL, a[i] - max(0LL, tmp*k - remain) - add) % k; 
  }
  ret += (remain + k - 1) / k;
  cout << ret << endl;

  return 0;
}