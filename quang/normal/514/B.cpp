#include <bits/stdc++.h>

#define Task "B"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

int n, X, Y;
int x[1010], y[1010];
int dd[1010];

bool Check(int u, int v) {
  if (x[u] * x[v] == 0) {
    return (x[u] == 0 && x[v] == 0);
  }
  if (y[u] * y[v] == 0) {
    return (y[u] == 0 && y[v] == 0);
  }
  double u1 = 1.0 * x[u] / (1.0 * y[u]);
  double v1 = 1.0 * x[v] / (1.0 * y[v]);
  return (abs(u1 - v1) < 0.00000000001);
}

int main() {
  ios_base::sync_with_stdio(0);
  //fi, fo;
  cin >> n >> X >> Y;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
    x[i] -= X;
    y[i] -= Y;
  }
  int res = 0;
  for (int i = 1; i <= n; i++) {
    if (!dd[i]) {
      dd[i] = 1;
      res++;
      for (int j = i + 1; j <= n; j++) {
        if (Check(i, j)) {
          dd[j] = 1;
        }
      }
    }
  }
  cout << res;
  return 0;
}