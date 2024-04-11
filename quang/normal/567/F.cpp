#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int n, k;

vector <pair<int, string> > a[N];
long long dp[N][N];

bool check(int l, int r, int u, int v) {
  for (int i = l; i <= r; i++) {
    for (int j = 0; j < a[i].size(); j++) {
      int x = a[i][j].first;
      string sign = a[i][j].second;
      if (x != u && x != v) {
        continue;
      }
      if (sign == "=" || sign == "<" || sign == "<=") {
        return 0;
      }
    }
  }
  for (int i = 0; i < a[u].size(); i++) {
    int x = a[u][i].first;
    string sign = a[u][i].second;
    if (x == v) {
      if (sign == "<" || sign == ">") {
        return 0;
      }
    }
    if (l <= x && x <= r) {
      if (sign == "=" || sign == ">" || sign == ">=") {
        return 0;
      }
    }
  }
  for (int i = 0; i < a[v].size(); i++) {
    int x = a[v][i].first;
    string sign = a[v][i].second;
    if (x == u) {
      if (sign == "<" || sign == ">") {
        return 0;
      }
    }
    if (l <= x && x <= r) {
      if (sign == "=" || sign == ">" || sign == ">=") {
        return 0;
      }
    }
  }
  return 1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> k;
  for (int i = 1; i <= k; i++) {
    int u, v;
    string x;
    cin >> u >> x >> v;
    a[u].push_back(make_pair(v, x));
  }
  for (int i = 1; i < n * 2; i++) {
    dp[i][i + 1] = check(0, 0, i, i + 1);
  }
  for (int len = 4; len <= n * 2; len += 2) {
    for (int l = 1; l <= n * 2 - len + 1; l++) {
      int r = l + len - 1;
      dp[l][r] = 0;
      if (check(l, r - 2, r - 1, r)) {
        dp[l][r] += dp[l][r - 2];
      }
      if (check(l + 2, r, l, l + 1)) {
        dp[l][r] += dp[l + 2][r];
      }
      if (check(l + 1, r - 1, l, r)) {
        dp[l][r] += dp[l + 1][r - 1];
      }
    }
  }
  cout << dp[1][n * 2] << endl;
  return 0;
}