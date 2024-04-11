#include<bits/stdc++.h>

using namespace std;

vector<int> factors(int n) {
  vector<int> ans;
  int m = n;
  for(int i = 2; i * i <= n; ++i) {
    while(m % i == 0) ans.push_back(i), m /= i;
  }
  if(m > 1) ans.push_back(m);
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n; cin >> n;
  vector<pair<int, int>> a(n);

  for(auto &p : a) cin >> p.first >> p.second;

  vector<int> cur = factors(a[0].first), cur2 = factors(a[0].second);

  for(int x : cur) {
    int ans = 0;
    for(auto &p : a) {
      ans += (p.first % x == 0 || p.second % x == 0);
    }
    if(ans == n) {
      cout << x << endl;
      return 0;
    }
  }

  for(int x : cur2) {
    int ans = 0;
    for(auto &p : a) {
      ans += (p.first % x == 0 || p.second % x == 0);
    }
    if(ans == n) {
      cout << x << endl;
      return 0;
    }
  }

  cout << -1;

  return 0;
}