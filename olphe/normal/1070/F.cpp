#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;
  vector<vector<ll>> a(4);
  for(int i=0; i<n; ++i) {
    ll t;
    string s;
    cin >> s >> t;
    if(s == "00") a[0].push_back(t);
    else if(s == "01") a[1].push_back(t);
    else if(s == "10") a[2].push_back(t);
    else a[3].push_back(t);
  }
  
  sort(a[1].begin(), a[1].end(), greater<>());
  sort(a[2].begin(), a[2].end(), greater<>());
  sort(a[3].begin(), a[3].end(), greater<>());

  // for(auto i: a[1]) cout << i << " ";
  // cout << endl;
  // for(auto i: a[2]) cout << i << " ";
  // cout << endl;
  // for(auto i: a[3]) cout << i << " ";
  // cout << endl;

  ll ret = 0, num = a[3].size();
  for(auto i: a[3]) ret += i;

  // cout << ret << " " << num << endl;

  ll mi = min(a[1].size(), a[2].size());
  for(int i=0; i<mi; ++i) {
    ret += a[1][i];
    ret += a[2][i];
  }
  for(int i=mi; i<a[1].size(); ++i) a[0].push_back(a[1][i]);
  for(int i=mi; i<a[2].size(); ++i) a[0].push_back(a[2][i]);

  // cout << ret << endl;

  sort(a[0].begin(), a[0].end(), greater<>());
  // for(auto i: a[0]) cout << i << " ";
  // cout << endl;
  // cout << min((ll)a[0].size(), num) << endl;
  for(int i=0; i<min((ll)a[0].size(), num); ++i) {
    ret += a[0][i];
  }
  cout << ret << endl;

  return 0;
}