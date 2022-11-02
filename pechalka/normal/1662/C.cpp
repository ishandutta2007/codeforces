#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <string>
#include <vector>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

const int MOD = 998244353;

int add(int a, int b) {
  if (a + b < MOD)
    return a + b;
  return a + b - MOD;
}

void mul(const vector<vector<int>> &A, const vector<vector<int>> &B, vector<vector<int>> &C) {
  int n = A.size();
  int m = A[0].size();
  int k = B[0].size();
  C.resize(n);
  for (int i = 0; i < n; ++i) {
    C[i].resize(k);
    for (int j = 0; j < k; ++j) {
      C[i][j] = 0;
      for (int l = 0; l < m; ++l)
        C[i][j] = add(C[i][j], A[i][l] * 1ll * B[l][j] % MOD);
    }
  }
}

void pw(vector<vector<int>> A, vector<vector<int>> &ans, int m) {
  int n = A.size();
  ans.resize(n);
  for (int i = 0; i < n; ++i) {
    ans[i] = vector<int>(n, 0);
    ans[i][i] = 1;
  }
  vector<vector<int>> tmp;
  while (m) {
    if (m & 1) {
      mul(A, ans, tmp);
      swap(ans, tmp);
    }
    m >>= 1;
    mul(A, A, tmp);
    swap(A, tmp);
  }
}

int main() {
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#endif

  int n, m, k;
  cin >> n >> m >> k;
  if (k <= 2) {
    cout << 0 << '\n';
    return 0;
  }
  vector<vector<int>> G(n, vector<int>(n, 0));
  vector<int> deg(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    G[a][b] = G[b][a] = 1;
    ++deg[a];
    ++deg[b];
  }
  vector<vector<int>> dp(n, vector<int>(2 * n, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j)
      dp[i][j] = G[i][j];
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (j == i)
        continue;
      int cur = 0;
      for (int l = 0; l < n; ++l)
        cur += G[i][l] * G[l][j];
      dp[i][n + j] = cur;
    }
  }
  vector<vector<int>> A(2 * n, vector<int>(2 * n, 0));
  for (int i = 0; i < n; ++i)
    A[n + i][i] = 1;
  for (int i = 0; i < n; ++i) {
    if (deg[i])
      A[i][n + i] = add(MOD - deg[i], 1);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j)
      A[n + i][n + j] = G[i][j];
  }
  vector<vector<int>> B;
  pw(A, B, k - 2);
  vector<vector<int>> ans;
  mul(dp, B, ans);
  int res = 0;
  for (int i = 0; i < n; ++i)
    res = add(res, ans[i][n + i]);
  cout << res << '\n';
  return 0;
}