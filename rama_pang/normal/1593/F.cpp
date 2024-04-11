#include <bits/stdc++.h>
using namespace std;

void Main() {
  int N, A, B;
  cin >> N >> A >> B;
  string S;
  cin >> S;
  vector<vector<vector<vector<pair<int, int>>>>> dp(N + 1, vector<vector<vector<pair<int, int>>>>(A + 1, vector<vector<pair<int, int>>>(B + 1, vector<pair<int, int>>(N + N + 1, pair(0, -1)))));

  dp[0][A][B][N].first = 1;
  for (int pos = 0; pos < N; pos++) {
    int d = S[pos] - '0';
    for (int a = 0; a <= A; a++) {
      for (int b = 0; b <= B; b++) {
        for (int n = -N + 1; n <= N - 1; n++) if (dp[pos][a][b][N + n].first) {
          dp[pos + 1][(a * 10 + d) % A][b][N + n + 1] = max(dp[pos + 1][(a * 10 + d) % A][b][N + n + 1], pair(dp[pos][a][b][N + n].first, a * 10000 + b * 100 + 0));
          dp[pos + 1][a][(b * 10 + d) % B][N + n - 1] = max(dp[pos + 1][a][(b * 10 + d) % B][N + n - 1], pair(dp[pos][a][b][N + n].first, a * 10000 + b * 100 + 1));
        }
      }
    }
  }
  int n = -1;
  for (int d = 0; d <= N; d++) {
    if (dp[N][0][0][N - d].first) {
      n = N - d;
      break;
    }
    if (dp[N][0][0][N + d].first) {
      n = N + d;
      break;
    }   
  }
  if (n == -1) {
    cout << -1 << '\n';
    return;
  }
  int a = 0, b = 0;
  string ans;
  for (int pos = N - 1; pos >= 0; pos--) {
    int t = dp[pos + 1][a][b][n].second;
    ans.push_back(t % 100 == 0 ? 'R' : 'B');
    a = t / 10000;
    b = (t % 10000) / 100;
    n -= t % 100 == 0 ? 1 : -1;
  }
  reverse(begin(ans), end(ans));
  cout << ans << '\n';
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