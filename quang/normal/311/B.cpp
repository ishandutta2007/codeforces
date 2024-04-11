#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const long long inf = (1ll << 60);

int n, m, p;
int d[N], a[N];
long long res = 0;
long long sum[N];
long long dp[2][N];

struct convexhull {
  long long A[N], B[N];
  double C[N];
  int top, bot;

  void init() {
    top = 0;
    bot = 0;
  }

  void add(long long u, long long v) {
    double x = -inf;
    while (top > bot) {
      if (u == A[top - 1]) {
        if (v >= B[top - 1]) {
          return;
        }
        top--;
      } else {
        x = 1.0 * (v - B[top - 1]) / (A[top - 1] - u);
        if (x > C[top - 1]) {
          A[top] = u;
          B[top] = v;
          C[top] = x;
          top++;
          return;
        }
        top--;
      }
    }
    A[top] = u;
    B[top] = v;
    C[top] = -inf;
    top++;
  }

  long long get(long long u) {
    while (bot < top - 1 && C[bot + 1] <= u) {
      bot++;
    }
    return u * A[bot] + B[bot];
  }
} hull;

int main() {
  ios_base::sync_with_stdio(0);
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  cin >> n >> m >> p;
  for (int i = 2; i <= n; i++) {
    cin >> d[i];
    d[i] += d[i - 1];
  }
  for (int i = 1; i <= m; i++) {
    int h, t;
    cin >> h >> t;
    a[i] = t - d[h];
    /*if (a[i] < 0) {
      res -= a[i];
      a[i] = 0;
    }*/
  }
  sort(a + 1, a + m + 1);
  for (int i = 1; i <= m; i++) {
    sum[i] = sum[i - 1] + a[i];
  }
  dp[0][0] = 0;
  for (int i = 1; i <= m; i++) {
    dp[0][i] = inf;
  }
  int cur = 0, next;
  for (int it = 1; it <= p; it++) {
    hull.init();
    hull.add(0, 0);
    next = cur ^ 1;
    for (int i = 1; i <= m; i++) {
      dp[next][i] = hull.get(a[i]) - sum[i] + 1ll * a[i] * i;
      hull.add(-i, dp[cur][i] + sum[i]);
    }
    cur = next;
  }
  cout << res + dp[cur][m] << endl;
  return 0;
}