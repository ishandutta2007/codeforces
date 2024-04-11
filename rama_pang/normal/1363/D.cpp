#include <bits/stdc++.h>
using namespace std;
using lint = long long;

void Solve() {
  int n, k;
  cin >> n >> k;

  vector<int> all(n);
  iota(begin(all), end(all), 0);

  vector<vector<int>> s(k); // indices
  for (int i = 0; i < k; i++) {
    int c;
    cin >> c;
    while (c--) {
      int a;
      cin >> a;
      a--;
      s[i].emplace_back(a);
    }
    sort(begin(s[i]), end(s[i]));
  }

  auto Ask = [&](vector<int> a) {
    cout << "? " << a.size();
    for (auto i : a) cout << " " << i + 1;
    cout << endl;
    int x;
    cin >> x;
    if (x == -1) {
      assert(false);
      exit(0);
    }
    return x;
  };

  auto Answer = [&](vector<int> a) {
    cout << "!";
    for (auto i : a) cout << " " << i;
    cout << endl;
  };

  auto Merge = [&](vector<int> ids) {
    vector<int> res;
    for (auto i : ids) {
      for (auto j : s[i]) {
        res.emplace_back(j);
      }
    }
    return res;
  };

  if (k == 1) {
    vector<int> ids;
    for (int i = 0; i < n; i++) {
      if (i != s[0][0]) {
        ids.emplace_back(i);
      }
    }
    vector<int> ans(k, Ask(ids));
    return Answer(ans);
  }
  
  int all_mx = Ask(all);
  // passwords is always X X X ... X I X X ... X
  // X = all_mx. We have to find I

  int lo = 0, hi = k - 1;
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    vector<int> ids;
    for (int i = lo; i <= mid; i++) {
      ids.emplace_back(i);
    }
    int q = Ask(Merge(ids));
    if (q == all_mx) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }

  vector<int> ans(k, -1);
  set<int> kk;
  for (int i = 0; i < n; i++) {
    kk.emplace(i);
  }
  for (int i = 0; i < k; i++) {
    if (i != lo) {
      ans[i] = all_mx;
    } else {
      for (auto j : s[i]) {
        kk.erase(j);
      }
    }
  }
  ans[lo] = Ask(vector<int>(begin(kk), end(kk)));
  return Answer(ans);
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    Solve();
    string res;
    cin >> res;
    if (res == "Incorrect") {
      return 0;
    }
  }
}