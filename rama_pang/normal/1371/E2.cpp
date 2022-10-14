#include <bits/stdc++.h>
using namespace std;
using lint = long long;

bool Check(int n, int p, const vector<int> &a, int x, int t) {
  vector<int> state(n);
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
      return false;
    }
  }
  if (!can) {
    return false;
  }
  if (t == 0) {
    return true;
  }
  bool divis = false;
  for (int i = 0; i < n; i++) {
    if ((pref[i] - i) % p == 0) {
      divis = true;
    }
  }
  return !divis;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n, p;
  cin >> n >> p;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(begin(a), end(a));
  int lo = 0, hi = a[n - 1];

  {
    int l = 0, r = a[n - 1];
    while (l < r) {
      int m = (l + r) / 2;
      if (Check(n, p, a, m, 0)) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    lo = l;
  }
  {
    int l = lo - 1, r = a[n - 1];
    while (l < r) {
      int m = (l + r + 1) / 2;
      if (Check(n, p, a, m, 1)) {
        l = m;
      } else {
        r = m - 1;
      }
    }
    hi = l;
  }
  
  vector<int> ans;
  for (int i = lo; i <= hi; i++) {
    ans.emplace_back(i);
  }
  cout << ans.size() << "\n";
  for (auto i : ans) {
    cout << i << " ";
  }
  cout << "\n";
  return 0;
}