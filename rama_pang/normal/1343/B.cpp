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
    if ((n / 2) % 2 == 1) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    vector<int> ans;
    for (int i = 0, cnt = 2; i < n / 4; i++, cnt += 8) {
      ans.emplace_back(cnt);
      ans.emplace_back(cnt + 2);
    }
    for (int i = 0, cnt = 1; i < n / 2; i++, cnt += 4) {
      ans.emplace_back(cnt);
    }

    for (int i = 0; i < n; i++) {
      cout << ans[i] << " \n"[i == n - 1];
    }
  }

}