#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5 + 5;

// if S[i] == a
//   dp[i][0] = 1 + dp[i - 1][0]
//   dp[i][1] = min(dp[i - 1][0], dp[i - 1][1])
//   dp[i][2] = dp[i - 1][2]
// [1, inf, inf]
// [0, 0, inf]
// [0, 0, 0]


// if S[i] == b
//   dp[i][0] = dp[i - 1][0]
//   dp[i][1] = min(dp[i - 1][0], dp[i - 1][1] + 1)
//   dp[i][2] = min(dp[i - 1][1], dp[i - 1][2])
// [0, inf, inf]
// [0, 1, inf]
// [0, 0, 0]

// if S[i] == c
//   dp[i][0] = dp[i - 1][0]
//   dp[i][1] = dp[i - 1][1]
//   dp[i][2] = min(dp[i - 1][1], dp[i - 1][2] + 1)
// [0, inf, inf]
// [0, 0, inf]
// [0, 0, 1]

struct Matrix {
 public:
  int M[3][3];
  Matrix() {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        M[i][j] = 1e9;
      }
      M[i][i] = 0;
    }
  }
  Matrix(int c) {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (i < j) {
          M[i][j] = 1e9;
        } else {
          M[i][j] = 0;
        }
      }
    }
    M[c][c] += 1;
  }
  friend Matrix Merge(Matrix a, Matrix b) {
    Matrix c;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        c.M[i][j] = 1e9;
        for (int k = 0; k < 3; k++) {
          c.M[i][j] = min(c.M[i][j], a.M[i][k] + b.M[k][j]);
        }
      }
    }
    return c;
  };
};

Matrix seg[4 * MAX];

void Main() {
  int N, Q;
  cin >> N >> Q;
  int sz = 1;
  while (sz < N) sz *= 2;
  string S;
  cin >> S;
  for (int i = 0; i < N; i++) {
    seg[sz + i] = Matrix(S[i] - 'a');
  }
  for (int i = sz - 1; i >= 0; i--) {
    seg[i] = Merge(seg[i * 2 + 1], seg[i * 2]);
  }
  while (Q--) {
    int i;
    char x;
    cin >> i >> x;
    i--;
    S[i] = x;
    seg[sz + i] = Matrix(S[i] - 'a');
    int p = sz + i;
    for (p /= 2; p > 0; p /= 2) {
      seg[p] = Merge(seg[p * 2 + 1], seg[p * 2]);
    }
    int ans = 1e9;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        ans = min(ans, seg[1].M[i][j]);
      }
    }
    cout << ans << '\n';
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  // cin >> T;
  while (T--) Main();  
}