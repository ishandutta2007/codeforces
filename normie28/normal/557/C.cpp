#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, sum = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  map<int, vector<int>> mp;
  map<int, int> mp2;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    mp[a[i]].push_back(t);
    sum += t;
    mp2[a[i]] += t;
  }
  int res = 1e9;
  multiset<int> se;
  for (auto x : mp) {
    int sz = x.second.size();
    int t = 0;
    for (auto v : se) {
      if (sz == 1) break;
      t -= v;
      sz--;
    }
    res = min(res, sum - t - mp2[x.first]);
    for (auto v : x.second) {
      se.insert(-v);
    }
  }
  cout << res << endl;
}