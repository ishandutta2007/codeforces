#include <bits/stdc++.h>
using namespace std;

vector<vector<vector<int>>> trans(4, vector<vector<int>>(4, vector<int>(4)));
vector<vector<vector<int>>> tr0(40, vector<vector<int>>(4, vector<int>(4, 0)));

void Main() {
  int n, m;
  cin >> n >> m;
  map<int, int> state;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    state[y] |= 1 << x;
  }
  vector<int> ndp(4);
  vector<int> dp(4);
  dp[3] = 1;
  
  const auto Transition = [&](int type, int p) {
    if (p == 0) return;
    if (p == 1) {
      const auto &t = trans[type];
      ndp.assign(4, 0);
      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
          ndp[j] |= dp[i] && t[i][j];
        }
      }
      swap(dp, ndp);
    } else {
      assert(type == 0);
      int cur = 0;
      while (p > 0) {
        if (p & 1) {
          const auto &t = tr0[cur];
          ndp.assign(4, 0);
          for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
              ndp[j] |= dp[i] && t[i][j];
            }
          }
          swap(dp, ndp);
        }
        cur += 1;
        p /= 2;
      }
    }
  };

  int last = 0;
  state[n - 1] |= 0;
  for (auto [i, s] : state) {
    if (last + 1 <= i - 1) {
      Transition(0, i - last - 1);
    }
    Transition(s, 1);
    last = i;
  }

  if (dp[0] || dp[3]) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  trans[0][0][0] = 1;
  trans[0][0][3] = 1;
  trans[0][1][2] = 1;
  trans[0][2][1] = 1;
  trans[0][3][0] = 1;
  trans[0][3][3] = 1;

  trans[1][0][1] = 1;
  trans[1][1][3] = 1;
  trans[1][3][1] = 1;

  trans[2][0][2] = 1;
  trans[2][2][3] = 1;
  trans[2][3][2] = 1;
  
  trans[3][0][3] = 1;
  trans[3][3][3] = 1;

  tr0[0] = trans[0];
  for (int j = 1; j < 40; j++) {
    auto &cur = tr0[j];
    auto &las = tr0[j - 1];
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        for (int k = 0; k < 4; k++) {
          cur[i][j] |= las[i][k] && las[k][j];
        }
      }
    }
  }

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}