#include <bits/stdc++.h>
using namespace std;

const int N = 102;

int n;
double C, T;
pair<int, int> problems[N];
int a[N], p[N];

double dp[N][N][N*10];
double p9[N];
/*
double f(int x, int y, int score) {
  if (score < 0) return 1e12;
  if (y == 0) return score == 0 ? 0 : 1e12;
  if (x == n) return 1e12;
  if (vis[x][y][score]) return dp[x][y][score];
  vis[x][y][score] = true;
  
  double ret = f(x+1, y, score);
  ret = min(ret, f(x+1, y-1, score-problems[x].second) + problems[x].first*p9[y]);
  
  return dp[x][y][score] = ret;
}
*/

double eval(double t, int k, double solve) {
  return t + k*10 + solve/(C*t + 1);
}

double find(int k, double solve) {
  double t = (sqrt(solve*C) - 1) / C;
  if (t < 0) return eval(0, k, solve);
  return eval(t, k, solve);
  
  double l = 0, r = T;
  
  for (int i=0; i<30; i++) {
    double mid1 = (r - l) / 3 + l;
    double mid2 = (r - l) / 3 * 2 + l;
    
    if (eval(mid1, k, solve) < eval(mid2, k, solve)) {
      r = mid2;
    } else l = mid1;
  }
  
  // cerr << l << " " << (sqrt(C*solve) - 1) / C << endl;
  return eval(l, k, solve);
}

int solve() {
  scanf("%d", &n);
  scanf("%lf %lf", &C, &T);
  for (int i=0; i<n; i++) {
    scanf("%d %d", &problems[i].first, &problems[i].second);
  }
  sort(problems, problems + n);
  
  for (int j=0; j<=n; j++) for (int k=0; k<=n*10; k++) dp[n][j][k] = 1e12;
  
  dp[n][0][0] = 0;
  for (int i=n-1; i>=0; i--) {
    for (int j=0; j<=n; j++) {
      for (int k=0; k<=n*10; k++) {
        dp[i][j][k] = dp[i+1][j][k];
        if (j > 0 && k >= problems[i].second) dp[i][j][k] = min(dp[i][j][k], dp[i+1][j-1][k-problems[i].second] + problems[i].first*p9[j]);
      }
    }
  }
    
  for (int score=n*10; score>0; --score) {
    for (int k=n; k>0; --k) {
        // cerr << f(0, k, score) << " " << find(k, f(0, k, score)) << endl;
      if (find(k, dp[0][k][score]) <= T) {
        return 0 * printf("%d\n", score);
      }
    }
  }
  
  printf("0\n");
  return 0;
}

int main() {
  for (int i=0; i<N; i++) p9[i] = 1.0 / pow(0.9, i);
  
  int tc;
  scanf("%d", &tc);
  while (tc--) solve();
  
  return 0;
}