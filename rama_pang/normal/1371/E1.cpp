#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n, p;
  cin >> n >> p;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> ans;
  for (int x = 1; x <= 2000; x++) {
    static vector<int> state(n);
    for (int i = 0; i < n; i++) {
      state[i] = x + i;
    }
    static vector<int> pref(n);
    pref.assign(n, 0);
    bool can = true;
    for (int i = 0; i < n; i++) {
      int where = lower_bound(begin(state), end(state), a[i]) - begin(state);
      if (where == n) {
        can = false;
        break;
      }
      pref[where]++;
    }
    for (int i = 1; i < n; i++) {
      pref[i] += pref[i - 1];
    }
    for (int i = 0; i < n; i++) {
      if (pref[i] <= i) {
        can = false;
      }
    }
    if (!can) {
      continue;
    }
    for (int i = n - 1; i > 0; i--) {
      pref[i] -= pref[i - 1];
    }
    bool divis = false;
    for (int i = 0; i < n; i++) {
      if (i > 0) {
        pref[i] += pref[i - 1];
      }
      if (pref[i] % p == 0) {
        divis = true;
      }
      if (i + 1 < n) {
        pref[i + 1] -= 1;
      }
    }
    if (!divis) {
      ans.emplace_back(x);
    }
  }
  cout << ans.size() << "\n";
  for (auto i : ans) {
    cout << i << " ";
  }
  cout << "\n";
  return 0;
}