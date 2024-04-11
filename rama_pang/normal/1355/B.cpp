#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    vector<int> cnt(n + 1);
    for (int i = 0; i < n; i++) {
      cnt[a[i]]++;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      cnt[i] += cnt[i - 1];
      ans += cnt[i] / i;
      cnt[i] %= i;
    }
    cout << ans << "\n";
  }
}