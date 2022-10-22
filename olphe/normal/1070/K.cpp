#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

signed main() {
  ll n, k;
  cin >> n >> k;
  vector<int> a(n);
  for(int i=0; i<n; ++i) cin >> a[i];

  ll sum = 0;
  for(int i=0; i<n; ++i) sum += a[i];

  if(sum%k != 0) {
    cout << "No" << endl;
    return 0;
  }

  sum /= k;
  ll now = 0, prev = -1;
  vector<ll> v;
  for(int i=0; i<n; ++i) {
    now += a[i];
    if(now == sum) {
      v.push_back(i - prev);
      prev = i;
      now = 0;
    } else if(now > sum) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  for(int i=0; i<v.size(); ++i) {
    cout << v[i];
    if(i != n-1) cout << " ";
  }
  cout << endl;

  return 0;
}