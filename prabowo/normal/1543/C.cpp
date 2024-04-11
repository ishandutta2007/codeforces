#include <bits/stdc++.h>
using namespace std;
 
double EPS = 1e-7;

double c, m, p, v;

double g(double x, double y) {
  // cerr << x << " " << y << " ";
  double ret = y, mul = 1;
  while (x > 0) {
    mul *= x;
    double diff = min(x, v);
    x -= diff;
    y += diff;
    ret += mul * (1 + y);
  }

  // cerr << ret << endl;

  return ret;
}

int maxC, maxM;
vector<vector<bool>> vis;
vector<vector<double>> dp;
double f(int x, int y) {
  if (vis[x][y]) return dp[x][y];
  vis[x][y] = true;

  double C = c - (maxC - x) * (v / 2);
  double M = m - (maxM - y) * (v / 2);
  double P = 1 - C - M;

  double ret = P;

  // C
  {
    if (x > 2) {
      ret += C * (1 + f(x - 2, y + 1));
    } else {
      ret += C * (1 + g(M + C/2, P + C/2));
    }
  }

  // M
  {
    if (y > 2) {
      ret += M * (1 + f(x + 1, y - 2));
    } else {
      ret += M * (1 + g(C + M/2, P + M/2));
    }
  }

  return dp[x][y] = ret;
}

int solve() {
  scanf("%lf %lf %lf %lf", &c, &m, &p, &v);
  auto toInt = [&](double x) { return int(x * 20000 + EPS); };
  int C = toInt(c), M = toInt(m), P = toInt(p), V = toInt(v);
  maxC = C / (V / 2) + (C % (V / 2) > 0);
  maxM = M / (V / 2) + (M % (V / 2) > 0);

  // cerr << C << " " << M << " " << P << " " << V << endl;
  // cerr << maxC << " " << maxM << endl;

  vis = vector<vector<bool>>(maxC + maxM/2 + 1, vector<bool>(maxM + maxC/2 + 1, false));
  dp = vector<vector<double>>(maxC + maxM/2 + 1, vector<double>(maxM + maxC/2 + 1));

  printf("%.12lf\n", f(maxC, maxM));

  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}