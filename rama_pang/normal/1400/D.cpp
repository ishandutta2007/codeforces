#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<int>> cnt(n, vector<int>(n, 0));
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i]--;
    }
    long long ans = 0;
    for (int j = n - 1; j >= 0; j--) {
      for (int i = j - 1; i >= 0; i--) {
        ans += cnt[a[i]][a[j]];
      }
      for (int i = j + 1; i < n; i++) {
        cnt[a[j]][a[i]] += 1;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}