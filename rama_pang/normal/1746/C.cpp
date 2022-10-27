#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  set<int> s;
  vector<int> ans(n + 1);
  for (int i = 1; i <= n; i++) s.emplace(i);
  for (int i = 1; i < n; i++) {
    int d = a[i - 1] - a[i];
    if (d <= 0) continue;
    auto it = s.lower_bound(d);
    ans[*it] = i + 1;
    s.erase(it);
  }
  for (auto i : s) ans[i] = 1;
  for (int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
}