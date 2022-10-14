#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int n, m, k;
int a[505][505];

int INF = (1 << 18) - 1;


int BobAlgo() {
  int dp[505][505] = {};
  dp[0][1] = a[1][1];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dp[i][j] = max((dp[i - 1][j] & a[i][j]), (dp[i][j - 1] & a[i][j]));
    }
  }
  return dp[n][m];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> k;

  n = 3, m = 3;
  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
      a[i][j] = INF;
    }
  }

  a[2][2] = a[3][3] = k;
  a[1][3] = a[3][1] = INF - k;
  

  cout << n << " " << m << "\n";
  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
      cout << a[i][j] << " \n"[j == 3];
    }
  }
}