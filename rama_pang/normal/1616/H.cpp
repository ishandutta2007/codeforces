#include <bits/stdc++.h>
using namespace std;

using lint = long long;
#define int lint

const int MOD = 998244353;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

void Main() {
  int N, K;
  // N = 15;
  // K = rnd() % (1 << 30);
  cin >> N >> K;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    // A[i] = rnd() % (1 << 30);
    cin >> A[i];
  }

  // int brute = 0;
  // for (int mask = 1; mask < (1 << N); mask++) {
  //   vector<int> cur;
  //   for (int i = 0; i < N; i++) {
  //     if ((mask >> i) & 1) cur.emplace_back(A[i]);
  //   }
  //   int bad = 0;
  //   for (auto i : cur) for (auto j : cur) if ((i ^ j) > K) {
  //     bad = 1;
  //     break;
  //   }
  //   if (!bad) brute += 1;
  // }
  // cout << brute << '\n';


  vector<int> pow2(N + 1);
  pow2[0] = 1;
  for (int i = 1; i <= N; i++) pow2[i] = 2 * pow2[i - 1] % MOD;
  const auto MIS = [&](const auto &self, int bit, vector<int> lft, vector<int> rgt) -> int {
    if (lft.empty() || rgt.empty() || bit < 0) return pow2[lft.size() + rgt.size()];
    vector<int> lft0, lft1, rgt0, rgt1;
    for (auto i : lft) {
      if ((i >> bit) & 1) {
        lft1.emplace_back(i);
      } else {
        lft0.emplace_back(i);
      }
    }
    for (auto i : rgt) {
      if ((i >> bit) & 1) {
        rgt1.emplace_back(i);
      } else {
        rgt0.emplace_back(i);
      }
    }
    const auto Get = [&](int x, int y) {
      return (pow2[x] - 1) * (pow2[y] - 1) % MOD;
    };
    if ((K >> bit) & 1) {
      return (self(self, bit - 1, lft0, rgt1) * self(self, bit - 1, lft1, rgt0)) % MOD;      
    } else {
      return (self(self, bit - 1, lft0, rgt0) + self(self, bit - 1, lft1, rgt1) + Get(lft0.size(), lft1.size()) + Get(rgt0.size(), rgt1.size()) + MOD - 1) % MOD;
    }
  };
  const auto Solve = [&](const auto &self, int bit, vector<int> a) -> int {
    if (a.empty() || bit < 0) return pow2[a.size()];
    vector<int> lft, rgt;
    for (auto i : a) {
      if ((i >> bit) & 1) {
        lft.emplace_back(i);
      } else {
        rgt.emplace_back(i);
      }
    }
    if ((K >> bit) & 1) {
      return MIS(MIS, bit - 1, lft, rgt);
    } else {
      return (self(self, bit - 1, lft) + self(self, bit - 1, rgt) + MOD - 1) % MOD;
    }
  };
  cout << (Solve(Solve, 30, A) + MOD - 1) % MOD << '\n';
}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  // cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}