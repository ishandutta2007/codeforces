#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10005;

int N, M;
string S, T;
int dp[MAXN][MAXN];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> S >> T;
  N = S.size();
  M = T.size();

  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= M; j++) {
      dp[i][j] = MAXN;
    }
  }

  vector<int> nxt(N, -1);
  for (int i = 0; i < N; i++) {
    if (S[i] == '.') {
      continue;
    }
    for (int j = i, bal = 0; j < N; j++) {
      if (S[j] != '.') {
        bal++;
      } else {
        bal--;
      }
      if (bal == 0) {
        nxt[i] = j + 1;
        break;
      }
    }
  }

  dp[0][0] = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= M; j++) {
      if (j < M && S[i] == T[j]) {
        dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
      }
      dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
      if (nxt[i] != -1) {
        dp[nxt[i]][j] = min(dp[nxt[i]][j], dp[i][j]);
      }
    }
  }

  cout << dp[N][M] << "\n";
  return 0;
}