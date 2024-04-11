#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    long long ans = 0;
    long long even = 0, odd = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (i % 2 == 0) {
        ans += a[i];
        a[i] *= -1;
      }
    }
    vector<long long> b, c;
    for (int i = 0; i + 1 < n; i += 2) {
      b.emplace_back(a[i + 1] + a[i]);
    }
    for (int i = 2; i < n; i += 2) {
      c.emplace_back(a[i] + a[i - 1]);
    }
    long long mx = 0;
    long long sum = 0;
    for (auto i : b) {
      sum += i;
      mx = max(mx, sum);
      if (sum < 0) sum = 0;
    }
    sum = 0;
    for (auto i : c) {
      sum += i;
      mx = max(mx, sum);
      if (sum < 0) sum = 0;
    }

    cout << ans + mx << "\n";
  }
}