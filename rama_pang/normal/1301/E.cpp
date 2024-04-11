#include <bits/stdc++.h>
using namespace std;

using doub = double;
using lint = long long;

#define alL(x) begin(x), end(x)
#define sz(x) (int) x.size()



const int MAX = 505;
const int BIT = 10;

char C[MAX][MAX]; // input
int P[4][MAX][MAX]; // prefix sum of input
int Sparse[BIT][BIT][MAX][MAX]; // sparse table of maximum square starting(top left) from (i, j)
int LOG2[MAX];
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
 
  int N, M, Q;
  cin >> N >> M >> Q;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      cin >> C[i][j];
      if (C[i][j] == 'R') {
        P[0][i][j] = 1;
      } else if (C[i][j] == 'G') {
        P[1][i][j] = 1;
      } else if (C[i][j] == 'Y') {
        P[2][i][j] = 1;
      } else {
        P[3][i][j] = 1;
      }
      for (int k = 0; k < 4; k++) {
        P[k][i][j] = P[k][i][j] + P[k][i][j - 1] + P[k][i - 1][j] - P[k][i - 1][j - 1];
      }
    }
  }

  auto get = [&](int k, int i1, int j1, int i2, int j2) {
    return P[k][i2][j2] - P[k][i1 - 1][j2] - P[k][i2][j1 - 1] + P[k][i1 - 1][j1 - 1];
  };

  auto isLogo = [&](int i, int j, int d) {
    int mini = d * d;
    if (i + d <= N && j + d <= M) {
      bool yes = true;
      yes &= (get(0, i - d + 1, j - d + 1, i, j) == mini);
      yes &= (get(1, i - d + 1, j + 1, i, j + d) == mini);
      yes &= (get(2, i + 1, j - d + 1, i + d, j) == mini);
      yes &= (get(3, i + 1, j + 1, i + d, j + d) == mini);
      
      return yes;
    }
    return false;
  };

  // cout << "INITIAL\n";
  for (int i = 1; i<= N; i++) {
    for (int j = 1; j <= M; j++) {
      for (int l = 0, r = max(N, M), m = (l + r) / 2; l <= r; m = (l + r) / 2) {
        if (isLogo(i, j, m)) {
          Sparse[0][0][i][j] = m;
          l = m + 1;
        } else {
          r = m - 1;
        }
      }
      // cout << Sparse[0][0][i][j] << " ";
    } 
    // cout << "\n";
  }


  LOG2[1] = 0;
  for (int i = 2; i < MAX; i++) {
    LOG2[i] = LOG2[i / 2] + 1;
  }

  for (int k = 1; k < BIT; k++) {
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= M; j++) {
        if (i + (1 << (k - 1)) <= N) {
          Sparse[k][0][i][j] = max(Sparse[k - 1][0][i][j], Sparse[k - 1][0][i + (1 << (k - 1))][j]);
        } else {
          Sparse[k][0][i][j] = Sparse[k - 1][0][i][j];
        }
      }
    }
  }
 
  for (int l = 1; l < BIT; l++) {
    for (int k = 0; k < BIT; k++) {
      for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
          if (j + (1 << (l - 1)) <= M) {
            Sparse[k][l][i][j] = max(Sparse[k][l - 1][i][j], Sparse[k][l - 1][i][j + (1 << (l - 1))]);
          } else {
            Sparse[k][l][i][j] = Sparse[k][l - 1][i][j];
          }
        }
      }
    }
  }
  
  auto rmq = [&](int i1, int j1, int i2, int j2) { // range maximum query
    if (i1 > i2 || j1 > j2) return 0;
    i2 = min(i2, N);
    j2 = min(j2, M);
    int logr = LOG2[i2 - i1 + 1];
    int logc = LOG2[j2 - j1 + 1];
    return max({
      Sparse[logr][logc][i1]                  [j1],
      Sparse[logr][logc][i2 - (1 << logr) + 1][j1],
      Sparse[logr][logc][i1]                  [j2 - (1 << logc) + 1],
      Sparse[logr][logc][i2 - (1 << logr) + 1][j2 - (1 << logc) + 1]
    });
  };


  for (int qi = 0; qi < Q; qi++) {
    int x[2], y[2];
    for (int i = 0; i < 2; i++) {
      cin >> x[i] >> y[i];
    }
    int ans = 0;
    for (int l = 1, r = max(N, M), mid = (l + r) / 2; l <= r; mid = (l + r) / 2) {
      if (rmq(x[0] + mid - 1, y[0] + mid - 1, x[1] - mid, y[1] - mid) >= mid) {
        ans = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }

    ans *= 2;
    ans *= ans;
 
    cout << ans << "\n";
  }
  return 0;
}