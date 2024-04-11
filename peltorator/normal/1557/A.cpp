#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  long long mx = -1e18;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    long long val;
    cin >> val;
    mx = max(mx, val);
    sum += val;
  }
  cout << fixed << setprecision(30);
  cout << (long double)mx + (long double)(sum - mx) / (long double)(n - 1) << '\n';
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}