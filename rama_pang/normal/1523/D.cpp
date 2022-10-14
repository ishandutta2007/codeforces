#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint INF = 1e18;

void Main() {
  int N, M, P;
  cin >> N >> M >> P;
  vector<lint> A(N, 0);
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < M; j++) {
      if (s[j] == '1') {
        A[i] |= 1ll << j;
      }
    }
  }
  // Find a subset of M
  // s.t. there is N/2 items, which 
  // Find a subset of N/2 A[] with maximum bitwise AND popcount

  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
  pair<int, lint> ans = {0, 0};

  for (int rep = 0; rep < 30; rep++) {
    int r = rnd() % N;
    vector<int> ones;
    for (int i = 0; i < M; i++) {
      if ((A[r] >> i) & 1) {
        ones.emplace_back(i);
      }
    }
    int n = ones.size();
    vector<int> cnt(1 << n);
    for (int i = 0; i < N; i++) {
      int mask = 0;
      for (int j = 0; j < n; j++) {
        if ((A[i] >> ones[j]) & 1) {
          mask |= 1 << j;
        }
      }
      cnt[mask] += 1;
    }
    for (int i = 0; i < n; i++) {
      for (int mask = (1 << n) - 1; mask >= 0; mask--) {
        if (!((mask >> i) & 1)) {
          cnt[mask] += cnt[mask | (1 << i)];
        }
      }
    }
    for (int mask = 0; mask < (1 << n); mask++) {
      if (cnt[mask] >= (N + 1) / 2) {
        lint config = 0;
        for (int i = 0; i < n; i++) {
          if ((mask >> i) & 1) {
            config |= 1ll << ones[i];
          }
        }
        ans = max(ans, pair(__builtin_popcount(mask), config));
      }
    }
  }

  for (int i = 0; i < M; i++) {
    if ((ans.second >> i) & 1) {
      cout << 1;
    } else {
      cout << 0;
    }
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  // cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}