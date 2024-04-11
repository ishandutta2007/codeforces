#include <bits/stdc++.h>
using namespace std;
using lint = long long;

void Main() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  set<long long> s;
  const auto Dfs = [&](const auto &self, vector<int> &v) {
    if (v.empty()) {
      return;
    }
    long long sum = 0;
    for (auto i : v) {
      sum += i;
    }
    s.emplace(sum);
    int mn = *min_element(begin(v), end(v));
    int mx = *max_element(begin(v), end(v));
    int mid = (mn + mx) / 2;
    vector<int> l, r;
    for (auto i : v) {
      if (i <= mid) {
        l.emplace_back(i); 
      } else {
        r.emplace_back(i);
      }
    }
    v.clear();
    v.shrink_to_fit();
    if (l.empty() || r.empty()) {
      return;
    }
    self(self, l);
    self(self, r);
  };
  Dfs(Dfs, a);
  for (int i = 0; i < q; i++) {
    int c;
    cin >> c;
    if (s.count(c)) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
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