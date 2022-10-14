#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  int N;
  cin >> N;

  vector<lint> ans(N, 0);
  auto Query = [&](vector<int> a) {
    cout << "? " << a.size() << " ";
    for (auto i : a) cout << i + 1 << " ";
    cout << endl;

    lint x;
    cin >> x;

    set<int> s(begin(a), end(a));
    for (int i = 0; i < N; i++) {
      if (s.count(i) == 0) {
        ans[i] |= x;
      }
    }

    return x;
  };

  const int Q = 13;
  vector<vector<int>> ask(Q);
  for (int mask = 0, i = 0; mask < (1 << Q); mask++) {
    if (__builtin_popcount(mask) == Q / 2) {
      for (int j = 0; j < Q; j++) {
        if (mask & (1 << j)) {
          ask[j].emplace_back(i);
        }
      }
      i++;
      if (i == N) break;
    }
  }
  for (int i = 0; i < Q; i++) {
    if (!ask[i].empty()) {
      Query(ask[i]);
    }
  }

  cout << "! ";
  for (auto i : ans) cout << i << " ";
  cout << endl;
  return 0;
}