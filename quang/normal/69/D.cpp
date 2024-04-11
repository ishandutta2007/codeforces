#include <bits/stdc++.h>

using namespace std;

const int N = 410;

int x, y, n, d;
int dp[N][N], u[N], v[N];

bool dfs(int x, int y) {
  if (x * x + y * y > d) {
    return 1;
  }
  if (dp[x + 200][y + 200]) {
    return (dp[x + 200][y + 200] == 1);
  }
  for (int i = 1; i <= n; i++) {
    if (!dfs(x + u[i], y + v[i])) {
      return dp[x + 200][y + 200] = 1;
    }
  }
  dp[x + 200][y + 200] = -1;
  return 0;
}

int main() {
  ios_base::sync_with_stdio(0);
  #ifdef Doflamingo
 // freopen("input.txt", "r", stdin);
  #endif // Doflamingo
  cin >> x >> y >> n >> d;
  d *= d;
  for (int i = 1; i <= n; i++) {
    cin >> u[i] >> v[i];
  }
  cout << (dfs(x, y) ? "Anton" : "Dasha") << endl;
  return 0;
}