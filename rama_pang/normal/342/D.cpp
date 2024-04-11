#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, M = 3;
  cin >> N;
  vector<string> A(N, string(M, '?'));
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      cin >> A[j][i];
    }
  }

  vector<vector<vector<int>>> trans(1 << M, vector<vector<int>>(1 << M));

  for (int cur = 0; cur < (1 << M); cur++) {
    for (int bad = 0; bad < (1 << M); bad++) {
      bool can = true;
      for (int i = 0; i < M; i++) {
        if (!((cur >> i) & 1) && ((bad >> i) & 1)) {
          can = false;
          break;
        }
      }
      if (!can) {
        continue;
      }
      int nxt = bad;
      for (int i = 0; i < M; i++) {
        if (!((cur >> i) & 1)) {
          nxt |= 1 << i;
        }
      }
      trans[cur][bad].emplace_back(nxt);
      if (!(nxt & 1) && !(nxt & 2)) {
        trans[cur][bad].emplace_back(nxt + 3);
      }
      if (!(nxt & 2) && !(nxt & 4)) {
        trans[cur][bad].emplace_back(nxt + 6);
      }
    }
  }

  const int MOD = 1e9 + 7;
  const auto Count = [&]() -> int {
    vector<int> dp((1 << M), 0);
    dp.back() = 1;
    for (int i = 0; i < N; i++) {
      static vector<int> ndp; ndp.assign((1 << M), 0);
      int bad = 0;
      for (int j = 0; j < M; j++) {
        if (A[i][j] == 'X') {
          bad |= 1 << j;
        }
      }
      for (int cur = 0; cur < (1 << M); cur++) {
        for (auto nxt : trans[cur][bad]) {
          ndp[nxt] += dp[cur];
          ndp[nxt] -= (ndp[nxt] >= MOD) * MOD;
        }
      }
      swap(dp, ndp);
    }
    return dp.back();
  };

  int x, y;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (A[i][j] == 'O') {
        x = i, y = j;
      }
    }
  }

  int ans = 0;
  for (int mask = 1; mask < (1 << 4); mask++) {
    int can = 1;
    vector<pair<int, int>> toggle;
    toggle.emplace_back(x, y);
    for (int d = 0; d < 4; d++) {
      if ((mask >> d) & 1) {
        if (d == 0) {
          if (x >= 2 && A[x - 1][y] == '.' && A[x - 2][y] == '.') {
            toggle.emplace_back(x - 1, y);
            toggle.emplace_back(x - 2, y);
          } else {
            can = 0;
          }
        } else if (d == 1) {
          if (y >= 2 && A[x][y - 1] == '.' && A[x][y - 2] == '.') {
            toggle.emplace_back(x, y - 1);
            toggle.emplace_back(x, y - 2);
          } else {
            can = 0;
          }
        } else if (d == 2) {
          if (x + 2 < N && A[x + 1][y] == '.' && A[x + 2][y] == '.') {
            toggle.emplace_back(x + 1, y);
            toggle.emplace_back(x + 2, y);
          } else {
            can = 0;
          }
        } else if (d == 3) {
          if (y + 2 < M && A[x][y + 1] == '.' && A[x][y + 2] == '.') {
            toggle.emplace_back(x, y + 1);
            toggle.emplace_back(x, y + 2);
          } else {
            can = 0;
          }
        }
      }
    }
    if (!can) {
      continue;
    }
    for (auto j : toggle) {
      A[j.first][j.second] = 'X';
    }
    if (__builtin_popcount(mask) & 1) {
      ans += Count();
    } else {
      ans -= Count();
    }
    ans = ((ans % MOD) + MOD) % MOD;
    for (auto j : toggle) {
      A[j.first][j.second] = '.';
    }
  }

  cout << ans << '\n';
  return 0;
}