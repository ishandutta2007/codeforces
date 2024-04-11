#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, S, D;
  cin >> N >> S >> D;
  vector<lint> H(N);
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 60; j++) {
      if (rnd() & 1) {
        H[i] += 1ll << j;
      }
    }
  }

  vector<lint> A(S);
  for (int i = 0; i < S; i++) {
    int k;
    cin >> k;
    while (k--) {
      int a;
      cin >> a;
      a--;
      A[i] ^= H[a];
    }
  }

  const int BLOCK = 20;

  vector<pair<lint, int>> brute;
  for (int mask = 0; mask < (1 << min(BLOCK, S)); mask++) {
    lint cur = 0;
    for (int i = 0; i < min(BLOCK, S); i++) {
      if (mask & (1 << i)) {
        cur ^= A[i];
      }
    }
    brute.emplace_back(cur, __builtin_popcount(mask));
  }
  sort(begin(brute), end(brute));

  for (int i = 0; i < D; i++) {
    lint query = 0;
    int k;
    cin >> k;
    while (k--) {
      int a;
      cin >> a;
      a--;
      query ^= H[a];
    }
    int ans = -1;
    for (int mask = 0; mask < (1 << (S - min(BLOCK, S))); mask++) {
      lint cur = query;
      for (int i = 0; i < S - min(BLOCK, S); i++) {
        if (mask & (1 << i)) {
          cur ^= A[S - i -1];
        }
      }
      int lb = lower_bound(begin(brute), end(brute), make_pair(cur, -1)) - begin(brute);
      if (lb != (int) brute.size() && brute[lb].first == cur) {
        int cost = brute[lb].second + __builtin_popcount(mask);
        if (ans == -1 || ans > cost) {
          ans = cost;
        }
      }
    }
    cout << ans << "\n";
  }
  return 0;
}