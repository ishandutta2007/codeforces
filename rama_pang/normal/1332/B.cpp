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
    vector<int> a(n);
    for (auto &i : a) {
      cin >> i;
    }
    vector<int> ans(n, -1);
    int m = 0;
    for (int i = 2; i <= 1000; i++) {
      bool plus = false;
      for (int j = 0; j < n; j++) {
        if (ans[j] != -1) continue;
        if (a[j] % i == 0) {
          if (!plus) m++, plus = true;
          ans[j] = m;
        }
      }
    }

    cout << m << "\n";
    for (int i = 0; i < n; i++) {
      cout << ans[i] << " \n"[i == n - 1];
    }
  }

}