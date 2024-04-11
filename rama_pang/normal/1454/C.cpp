#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, vector<int>> f;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    f[a[i]].emplace_back(i);
  }

  int ans = n;
  for (auto [_, v] : f) {
    int cnt = 0;
    if (v.front() > 0) {
      cnt += 1;
    }
    if (v.back() + 1 < n) {
      cnt += 1;
    }
    for (int i = 0; i + 1 < (int) v.size(); i++) {
      if (v[i] + 1 < v[i + 1]) {
        cnt += 1;
      }
    }
    ans = min(ans, cnt);
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