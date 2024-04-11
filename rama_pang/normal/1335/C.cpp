#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n), cnt(n);
    for (auto &i : a) cin >> i;
    for (auto i : a) cnt[i - 1]++;
    int mx = -1;
    for (int i = 0; i < n; i++) {
      if (mx == -1 || cnt[mx] < cnt[i]) mx = i;
    }
    int distinct = 0;
    for (int i = 0; i < n; i++) if (i != mx) {
      if (cnt[i] > 0) distinct++;
    }
    int ans = min(cnt[mx], distinct);
    distinct = 0;
    for (int i = 0; i < n; i++) {
      if (cnt[i] > 0) distinct++;
    }
    ans = max(ans, min(cnt[mx] - 1, distinct));
    cout << ans << "\n";    
  }

}