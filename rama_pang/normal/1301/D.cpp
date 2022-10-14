#include <bits/stdc++.h>
using namespace std;

using doub = double;
using lint = long long;

#define alL(x) begin(x), end(x)
#define sz(x) (int) x.size()


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int N, M, K;
  cin >> N >> M >> K;

  vector<pair<int, string>> optimal;
  for (int i = 0; i + 1 < N; i++) {
    optimal.emplace_back(M - 1, "R");
    optimal.emplace_back(M - 1, "L");
    optimal.emplace_back(1, "D");
  }
  optimal.emplace_back(M - 1, "R");
  for (int j = M - 1; j >= 1; j--) {
    optimal.emplace_back(N - 1, "U");
    optimal.emplace_back(N - 1, "D");
    optimal.emplace_back(1, "L");
  }
  optimal.emplace_back(N - 1, "U");

  // cout << "OPTIMAL\n";
  // for (int i = 0; i < optimal.size(); i++) {
  //   for (int j = 0; j < optimal[i].first; j++) {
  //     cout << optimal[i].second;
  //   }
  // }
  // cout << "\n";

  vector<pair<int, string>> ans, tmp;

  for (auto &opt : optimal) {
    if (K == 0) {
      break;
    }
    if (K >= opt.first) {
      K -= opt.first;
      ans.emplace_back(opt);
    } else {
      ans.emplace_back(K, opt.second);
      K = 0;
    }
  }

  for (auto &i : ans) {
    if (i.first > 0) {
      tmp.emplace_back(i);
    }
  }
  ans = tmp;

  if (K > 0) {
    cout << "NO\n";
    return 0;
  }

  cout << "YES\n";
  cout << ans.size() << "\n";
  for (auto &i : ans) {
    cout << i.first << " " << i.second << "\n";
  }


}