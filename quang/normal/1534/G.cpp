#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (auto &u : a) {
    cin >> u.first >> u.second;
    u.first += u.second;
  }
  sort(a.begin(), a.end());
  multiset<int> low, high;
  int delta_high = 0;
  int res = 0;
  int last = 0;
  for (auto &[sum, x] : a) {
    if (low.empty()) {
      low.insert(x);
      high.insert(x);
      last = sum;
      continue;
    }
    
    delta_high += sum - last;
    
    if (*low.rbegin() <= x && x <= *high.begin() + delta_high) { // middle
      low.insert(x);
      high.insert(x - delta_high);
    } else if (*low.rbegin() > x) { // low
      res += *low.rbegin() - x;
      low.insert(x);
      low.insert(x);
      auto value = *low.rbegin();
      low.erase(low.find(value));
      high.insert(value - delta_high);
    } else { // high
      res += x - (*high.begin() + delta_high);
      high.insert(x - delta_high);
      high.insert(x - delta_high);
      auto value = *high.begin() + delta_high;
      high.erase(high.begin());
      low.insert(value);
    }

    last = sum;
  }
  cout << res << '\n';
  return 0;
}