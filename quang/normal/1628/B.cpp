#include <bits/stdc++.h>

using namespace std;

void Solve(int test) {
  int n;
  cin >> n;
  vector<string> a(n);
  for (auto &u : a) {
    cin >> u;
  }
  set<string> s;
  set<string> first2;
  for (const auto &u : a) {
    s.insert(u);
    auto foo = u;
    reverse(foo.begin(), foo.end());
    if (s.count(foo)) {
      cout << "YES\n";
      return;
    }
    if (u.size() == 3) {
      auto bar = u.substr(0, 2);
      first2.insert(bar);
    }
    if (u.size() == 2) {
      if (first2.count(foo)) {
        cout << "YES\n";
        return;
      }
    }
    if (u.size() == 3) {
      auto bar = u.substr(1, 2);
      reverse(bar.begin(), bar.end());
      if (s.count(bar)) {
        cout << "YES\n";
        return;
      }
    }
  }
  cout << "NO\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) Solve(test);
  return 0;
}