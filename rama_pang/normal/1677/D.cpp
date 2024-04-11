#include <bits/stdc++.h>
using namespace std;

using lint = long long;

void Main() {
  const int MOD = 998244353;
  const auto Brute = [&](int n, int k, vector<int> b) {
    int ret = 0;
    vector<int> ord(n);
    iota(begin(ord), end(ord), 0);
    do {
      auto p = ord;
      for (int r = 0; r < k; r++) {
        for (int i = 0; i + 1 < n; i++) {
          if (p[i] > p[i + 1]) {
            swap(p[i], p[i + 1]);
          }
        }
      }
      vector<int> a(n);
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
          if (p[i] < p[j]) a[i] += 1;
        }
      }
      int bad = 0;
      for (int i = 0; i < n; i++) {
        if (b[i] == -1) continue;
        if (a[i] != b[i]) bad = 1;
      }
      if (!bad) ret += 1;
    } while (next_permutation(begin(ord), end(ord)));
    return ret;
  };
  const auto CalcBrute = [&](int n, int k, vector<int> a) {
    int ret = 0;
    vector<int> ord(n);
    iota(begin(ord), end(ord), 0);
    do {
      auto p = ord;
      for (int r = 0; r < k; r++) {
        for (int i = 0; i + 1 < n; i++) {
          if (p[i] > p[i + 1]) {
            swap(p[i], p[i + 1]);
          }
        }
      }
      if (p == a) ret += 1;
    } while (next_permutation(begin(ord), end(ord)));
    return ret;
  };
  const auto Calc = [&](int n, int k, vector<int> a) {
    for (int i = n - k; i < n; i++) {
      if (a[i] != i) {
        return 0;
      }
    }
    int g = -1;
    int ret = 1;
    for (int i = 0; i + 1 < n - k; i++) {
      if (a[i] > a[i + 1]) {
        g = i;
      }
    }
    for (int i = 1; i <= k; i++) {
      ret = 1ll * ret * i % MOD;
    }
    int mx = -1;
    for (int i = 0; i < n - k; i++) {
      if (mx < a[i]) {
        mx = a[i];
        ret = 1ll * ret * (k + 1) % MOD;
      }
    }
    return ret;

    // 2
    // 2 or 3
    // (2 or 3) or (3 or 4)
    //
  };
  int n, k;
  cin >> n >> k;
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  for (int i = n - k; i < n; i++) {
    if (b[i] == -1) b[i] = 0;
    if (b[i] != 0) {
      cout << "0\n";
      return;
    }
  }
  lint base = 1;
  for (int i = 1; i <= k; i++) {
    base = 1ll * base * i % MOD;
  }
  lint ans = 0;
  lint mul = k + 1;
  lint add = 0;
  vector<lint> ls;
  for (int i = 0; i < n - k; i++) {
    if (i == 0) b[i] = 0;
    if (b[i] == 0) {
      add += 1;
    }
    if (b[i] == -1) {
      ls.emplace_back(i);
    }
  }
  // (k + 1)^zero for all possibilty of choosing zero
  lint ddd = 1;
  for (auto c : ls) {
    ddd = 1ll * ddd * (c + k + 1) % MOD;
  }
  ans = ddd;
  // for (int c = 0; c <= ls.size(); c++) {
  //   lint ways = 1;
  //   // sum(mul(subsequence size |ls| - c over ls))
  //   ans += ways * ddd;
  //   ddd = 1ll * ddd * mul % MOD;
  // }
  while (add--) base = 1ll * base * mul % MOD;
  cout << 1ll * ans * base % MOD << '\n';
  // cout << Brute(n, k, b) << '\n';
  // vector<int> a(n);
  // iota(begin(a), end(a), 0);
  // do {
  //   assert(CalcBrute(n, k, a) == Calc(n, k, a));
  // } while (next_permutation(begin(a), end(a)));
  // return;
  // for (int i = 0; i < n; i++) {
  //   cin >> a[i];
  // }
  // cout << CalcBrute(n, k, a) << '\n';
  // cout << Calc(n, k, a) << '\n';
  // return;
  // // 0 1 2 3 4 5 6
  // //
  // for (int i = n - k; i < n; i++) {
  //   if (a[i] != i) {
  //     cout << "0\n";
  //     return;
  //   }
  // }

  // value sequence uniquely identifies final permutation
  // given final permutation, how to find ... exactly k
  // n-k+1, ..., n must occur in last k positions
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