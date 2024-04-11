#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < (n + 1) / 2; i++) {
    cin >> a[i];
  }
  long long x;
  cin >> x;
  for (int i = (n + 1) / 2; i < n; i++) {
    a[i] = x;
  }

  long long sum = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i];
  }

  if (sum > 0) {
    cout << n << "\n";
    return 0;
  }
  if (x > 0) {
    cout << -1 << "\n";
    return 0;
  }

  // sum <= 0 && x <= 0
  int ans = -1;

  vector<long long> b;
  sum = 0;
  for (int i = 0; i < (n + 1) / 2; i++) {
    sum += a[i];
  }
  b.emplace_back(sum);
  for (int i = (n + 1) / 2, j = 0; i < n; i++, j++) {
    sum -= a[j];
    sum += a[i];
    b.emplace_back(sum);
  }

  multiset<long long> s;
  for (auto i : b) {
    s.emplace(i);
  }
  
  long long lazy = 0;
  while (!b.empty()) {
    if (*begin(s) + lazy > 0) {
      ans = n - int(b.size()) + 1;
    }
    lazy += x;
    s.erase(s.find(b.back()));
    b.pop_back();
  }

  cout << ans << "\n";
  return 0;
}