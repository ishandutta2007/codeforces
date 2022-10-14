#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  
  int m, n;
  cin >> m >> n;

  vector<pair<lint, int>> a(n), b(n);
  for (auto &i : a) cin >> i.first;
  for (auto &i : b) cin >> i.first;
  for (int i = 0; i < n; i++) {
    a[i].second = b[i].second = i;
  }

  sort(begin(a), end(a));
  sort(begin(b), end(b));

  for (int i = 0; i < 2 * n; i++) {
    a.emplace_back(a[i]);
  }
  for (int i = 0; i < n; i++) {
    a[i].first -= m;
  }
  for (int i = 2 * n; i < 3 * n; i++) {
    a[i].first += m;
  }

  auto trial = [&](int x) {
    lint res = 0;
    for (int i = 0; i < n; i++) {
      res += abs(b[i].first - a[i + x].first);
    }
    return res;
  };

  int lo = 0, hi = 2 * n;
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (trial(mid) < trial(mid + 1)) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }

  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    ans[a[i + lo].second] = b[i].second;
  }

  cout << trial(lo) << "\n";
  for (int i = 0; i < n; i++) {
    cout << ans[i] + 1 << " \n"[i == n - 1];
  }
}