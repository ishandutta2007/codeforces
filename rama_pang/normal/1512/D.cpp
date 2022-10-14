#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n;
  cin >> n;
  vector<int> a(n + 2);
  multiset<int> s;
  long long sum = 0;
  for (int i = 0; i < n + 2; i++) {
    cin >> a[i];
    sum += a[i];
    s.emplace(a[i]);
  }
  for (int i = 0; i < n + 2; i++) {
    s.erase(s.find(a[i]));
    int mx = *prev(end(s));
    if (sum - a[i] - mx == mx) {
      for (auto j : s) {
        if (j == mx) {
          mx = -1;
          continue;
        }
        cout << j << ' ';
      }
      cout << '\n';
      return;
    }
    s.emplace(a[i]);
  }
  cout << -1 << '\n';
  return;
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