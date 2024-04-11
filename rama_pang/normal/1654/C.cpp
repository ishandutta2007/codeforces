#include <bits/stdc++.h>
using namespace std;

using lint = long long;
#define int lint

void Main() {
  int n;
  cin >> n;
  lint sum = 0;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }

  multiset<int> in;
  for (int i = 0; i < n; i++) in.emplace(a[i]);

  map<lint, int> mp;
  mp[sum] = 1;
  while (!mp.empty()) {
    auto it = prev(end(mp));
    lint occ = it->second;
    lint val = it->first;
    mp.erase(it);

    while (occ > 0 && in.find(val) != end(in)) {
      in.erase(in.find(val));
      occ -= 1;
    }
    if (occ > 0 && val > 1) {
      lint lo = val / 2;
      lint hi = (val + 1) / 2;
      mp[lo] += occ;
      mp[hi] += occ;
    }
  }
  if (in.empty()) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}