#include <bits/stdc++.h>
using namespace std;
using lint = long long;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    set<int> freq;
    for (auto i : a) freq.emplace(i);
    if (freq.size() > k) {
      cout << -1 << "\n";
      continue;
    }
    vector<int> rep;
    for (int i = 1; i <= n; i++) {
      if (freq.size() < k) freq.emplace(i);
    }
    for (auto i : freq) rep.emplace_back(i);
    cout << rep.size() * n << "\n";
    for (int i = 0; i < n; i++) {
      for (auto j : rep) {
        cout << j << " ";
      }
    }
    cout << "\n";
  }

}