#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint MOD = 1e9 + 7;

template<typename T>
void Add(T &a, lint b) {
  a += b;
  a -= (a >= MOD) * MOD;
}

lint Power(lint x, lint y) {
  lint res = 1;
  for (; y; y /= 2, x = 1ll * x * x % MOD) {
    if (y & 1) {
      res = 1ll * res * x % MOD;
    }
  }
  return res;
} 

void Main() {
  int n;
  cin >> n;
  vector<int> ls;
  vector<int> rs;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
    ls.emplace_back(a[i].first);
    rs.emplace_back(a[i].second);
  }
  sort(begin(ls), end(ls));
  sort(begin(rs), end(rs));
  int ans = n;
  for (auto [l, r] : a) {
    int cur = 0;
    cur += lower_bound(begin(rs), end(rs), l) - begin(rs);
    cur += end(ls) - upper_bound(begin(ls), end(ls), r);
    ans = min(ans, cur);
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}