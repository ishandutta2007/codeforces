#include <bits/stdc++.h>
using namespace std;

void Main() {
  using lint = long long;

  lint n;
  cin >> n;
  vector<pair<lint, lint>> a;
  for (lint i = 2; i * i <= n; i++) {
    lint cnt = 0;
    while (n % i == 0) {
      n /= i;
      cnt += 1;
    }
    if (cnt > 0) {
      a.emplace_back(i, cnt);
    }
  }
  if (n > 1) {
    a.emplace_back(n, 1);
  }
  lint k = 0;
  for (auto i : a) {
    k = max(k, i.second);
  }
  vector<lint> ans(k, 1);
  for (int i = 0; i < (int) a.size(); i++) {
    for (int j = 0; j < a[i].second; j++) {
      ans[k - j - 1] *= a[i].first;
    }
  }
  cout << k << '\n';
  for (auto i : ans) {
    cout << i << ' ';
  }
  cout << '\n';
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