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
    for (auto &i : a) cin >> i;

    vector<int> freq(n + 1);
    vector<int> can(n + 1);

    for (int i = 0; i < n; i++) {
      freq[a[i]]++;
      int sum = a[i];
      for (int j = i + 1; j < n; j++) {
        sum += a[j];
        if (sum > n) break;
        can[sum] = 1;
      }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
      if (can[i]) ans += freq[i];
    }

    cout << ans << "\n";
  }
}