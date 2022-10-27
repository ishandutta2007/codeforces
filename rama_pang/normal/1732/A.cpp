#include <bits/stdc++.h>
using namespace std;

using lint = long long;

void Main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = n;
  int g = a[0];
  for (auto i : a) g = gcd(g, i);
  for (int mask = 0; mask < (1 << 2); mask++) {
    int cost = 0, curg = 0;
    for (int i = max(0, n - 2); i < n; i++) {
      if ((mask >> (i - (n - 2))) & 1) {
        cost += n - i;
        curg = gcd(curg, i + 1);
        if (cost >= ans) break;
      }
    }
    if (gcd(g, curg) == 1 && cost < ans) {
      ans = cost;
    }
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