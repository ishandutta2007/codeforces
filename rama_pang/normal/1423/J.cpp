#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T;
  cin >> T;

  const int MOD = 1e9 + 7;
  const auto Add = [&](int &a, int b) -> void {
    a += b;
    if (a >= MOD) {
      a -= MOD;
    }
  };

  const int BLOCK = 12;
  vector<array<array<int, 8>, 8>> base(2);
  vector<array<array<int, 8>, 8>> trans(1 << BLOCK);

  for (int carry = 0; carry < 8; carry++) {
    for (int add = 0; add < 8; add++) {
      if ((carry + add) & 1) {
        base[1][carry][(carry + add) / 2] = 1;
      } else {
        base[0][carry][(carry + add) / 2] = 1;
      }
    }
  }

  for (int val = 0; val < (1 << BLOCK); val++) {
    for (int i = 0; i < 8; i++) {
      trans[val][i][i] = 1;
    }
  }

  for (int val = 0; val < (1 << BLOCK); val++) {
    for (int b = 0; b < BLOCK; b++) {
      array<array<int, 8>, 8> nt;
      for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
          nt[i][j] = 0;
          for (int k = 0; k < 8; k++) {
            Add(nt[i][j], 1ll * trans[val][i][k] * base[(val >> b) & 1][k][j] % MOD);
          }
        }
      }
      trans[val] = nt;
    }
  }

  array<int, 8> dp;
  array<int, 8> ndp;
  const auto Solve = [&](long long x) -> int {
    fill(begin(dp), end(dp), 0);
    dp[0] = 1;
    int rep = 0;
    while (x > 0) {
      fill(begin(ndp), end(ndp), 0);
      const auto &t = trans[x % (1 << BLOCK)];
      for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
          Add(ndp[j], 1ll * dp[i] * t[i][j] % MOD);
        }
      }
      x /= (1 << BLOCK);
      dp = ndp;
    }
    return dp[0];
  };

  for (int i = 0; i < T; i++) {
    long long n;
    cin >> n;
    cout << Solve(n) << "\n";
  }

  cerr << double(clock()) / CLOCKS_PER_SEC << " time\n";
  return 0;
}