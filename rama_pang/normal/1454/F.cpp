#include <bits/stdc++.h>
using namespace std;

void Main() {
  using lint = long long;

  int n;
  cin >> n;
  map<int, vector<int>> occpref;
  map<int, vector<int>> occsuff;
  vector<int> a(n);
  vector<int> mn(2 * n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mn[i + n] = a[i];
  }
  for (int i = n - 1; i > 0; i--) {
    mn[i] = min(mn[i * 2], mn[i * 2 + 1]);
  }
  const auto Query = [&](int l, int r) {
    int res = 1e9 + 10;
    for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
      if (l & 1) res = min(res, mn[l++]);
      if (r & 1) res = min(res, mn[--r]);
    }
    return res;
  };
  vector<int> pref = a;
  vector<int> suff = a;
  for (int i = 1; i < n; i++) {
    pref[i] = max(pref[i], pref[i - 1]);
  }
  for (int i = n - 2; i >= 0; i--) {
    suff[i] = max(suff[i], suff[i + 1]);
  }
  vector<int> ans;
  vector<int> vals;
  for (int i = 0; i < n; i++) {
    vals.emplace_back(pref[i]);
    vals.emplace_back(suff[i]);
    occpref[pref[i]].emplace_back(i);
    occsuff[suff[i]].emplace_back(i);
  }
  sort(begin(vals), end(vals));
  vals.resize(unique(begin(vals), end(vals)) - begin(vals));
  for (auto val : vals) {
    int jid = 0;
    for (auto i : occpref[val]) if (ans.empty()) {
      while (jid < (int) occsuff[val].size() && occsuff[val][jid] <= i) {
        jid += 1;
      }
      if (jid == (int) occsuff[val].size()) {
        break;
      }
      int lo = jid;
      int hi = (int) occsuff[val].size() - 1;
      while (lo <= hi) {
        int md = (lo + hi) / 2;
        int j = occsuff[val][md];
        if (i + 1 <= j - 1) {
          int q = Query(i + 1, j - 1);
          if (q == val) {
            ans = {i + 1, j - i - 1, n - j};
            break;
          } else if (q > val) {
            lo = md + 1;
          } else if (q < val) {
            hi = md - 1;
          }
        } else {
          lo = md + 1;
        }
      }
    }
  }
  if (ans.empty()) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}