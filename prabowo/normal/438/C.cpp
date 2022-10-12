#include <bits/stdc++.h>
using namespace std;

const int N = 205;
const int MOD = 1000000007;

using Point = pair<int, int>;

int n;
Point points[N];

long long area[N][N];

long long cross(Point p, Point q, Point r) {
  return 1LL * (q.first - p.first) * (r.second - q.second) - 1LL * (q.second - p.second) * (r.first - q.first); 
}

int dp[N][N];
int f(int l, int r) {
  if (r - l == 1) return 1;
  if (~dp[l][r]) return dp[l][r];

  int ret = 0;
  for (int k = l + 1; k < r; ++k) {
    long long triangle = abs(cross(points[l], points[k], points[r]));
    if (triangle == 0) continue;
    if (triangle + area[l][k] + area[k][r] + area[r][l] > area[0][n - 1]) continue;
    ret = (1LL * f(l, k) * f(k, r) + ret) % MOD;
    // cerr << l << " " << k << " " << r << " " << ret << endl;
  }
  return dp[l][r] = ret;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &points[i].first, &points[i].second);
  }

  for (int i = 0; i < n; ++i) {
    area[i][i] = 0;
    for (int j = 1; j < n; ++j) {
      area[i][(i + j) % n] = area[i][(i + j - 1) % n] + cross(points[i], points[(i + j - 1) % n], points[(i + j) % n]);
    }
    for (int j = 0; j < n; ++j) area[i][j] = abs(area[i][j]);
  }

  memset(dp, -1, sizeof dp);
  printf("%d\n", f(0, n - 1));
  return 0;
}