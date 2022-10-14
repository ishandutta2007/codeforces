#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n + 2);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    vector<int> pref(n + 2);
    vector<int> suff(n + 2);
    auto b = a;
    for (int i = 1; i <= n; i++) {
      if (pref[i - 1] == -1) {
        pref[i] = -1;
        continue;
      }
      int mn = min(b[i], b[i - 1]);
      b[i] -= mn;
      b[i - 1] -= mn;
      pref[i] = b[i];
      if (b[i - 1] != 0) {
        pref[i] = -1;
      }
    }
    b = a;
    for (int i = n; i >= 1; i--) {
      if (suff[i + 1] == -1) {
        suff[i] = -1;
        continue;
      }
      int mn = min(b[i], b[i + 1]);
      b[i] -= mn;
      b[i + 1] -= mn;
      suff[i] = b[i];
      if (b[i + 1] != 0) {
        suff[i] = -1;
      }
    }
    bool can = pref[n] == 0;
    vector<int> c(4);
    for (int i = 1; i < n; i++) {
      if (pref[i - 1] == -1 || suff[i + 2] == -1) {
        continue;
      }
      c[0] = pref[i - 1];
      c[1] = a[i + 1];
      c[2] = a[i];
      c[3] = suff[i + 2];
      for (int j = 1; j < 4; j++) {
        int mn = min(c[j], c[j - 1]);
        c[j] -= mn;
        c[j - 1] -= mn;
      }
      if (c[0] + c[1] + c[2] + c[3] == 0) {
        can = true;
      }
    }
    if (can) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}