#include <bits/stdc++.h>
using namespace std;

struct Frac {
 public:
  long long x = 0, y = 1;

};

void Main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  const int MAX = 2e5 + 5;
  vector<int> occ(MAX * 24);
  const auto Solve = [&](int L, int tr) {
    vector<int> cntM(MAX);
    for (int i = 0; i < n; i++) {
      cntM[a[i]] += min(b[i], L);
    }
    for (int i = 0; i < MAX; i++) {
      occ[cntM[i]] += 1;
    }
    pair<pair<int, int>, int> ans = {pair(-1, 1), -1};
    int sz = 0;
    int sum = 0;
    for (int i = MAX * 24 - 1; i >= 0; i--) {
      while (occ[i] > 0) {
        sum += i;
        sz += 1;
        occ[i] -= 1;
        if (sz >= L) {
          if (1ll * ans.first.first * sz < 1ll * ans.first.second * sum) {
            ans = {pair(sum, sz), sz};
            // ans = max(ans, {1.0 * sum / sz, sz});
          }
        }
      }
    }
    if (tr) {
      sz = 0;
      sum = 0;
      vector<pair<int, int>> haha;
      for (int i = 0; i < MAX; i++) {
        haha.emplace_back(cntM[i], i);
      }
      sort(begin(haha), end(haha));
      int items = ans.second;
      vector<int> res;
      while (res.size() < items) {
        res.emplace_back(haha.back().second);
        haha.pop_back();
      }
      cout << res.size() << '\n';
      for (auto a : res) cout << a << ' '; cout << '\n';
    }
    return ans.first;
  };
  pair<pair<int, int>, int> ans = {pair(-1, 1), -1};
  for (int k = 1; k <= 21; k++) {
    auto c = Solve(k, 0);
    if (1ll * ans.first.first * c.second < 1ll * c.first * ans.first.second) {
      ans = {c, k};
    }
  }
  // cout << ans.first << '\n';
  Solve(ans.second, 1);
  // choose
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  // cin >> T;
  while (T--) {
    Main();
  }  
}