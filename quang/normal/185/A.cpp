#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

long long n;

struct matrix {
  int a[2][2];
  matrix(int dia = 0) {
    memset(a, 0, sizeof a);
    a[0][0] = a[1][1] = dia;
  }
};

matrix Mul(const matrix &u, const matrix &v) {
  matrix res;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        res.a[i][j] = (1ll * u.a[i][k] * v.a[k][j] + res.a[i][j]) % MOD;
      }
    }
  }
  return res;
}

matrix Pow(matrix u, long long v) {
  matrix res(1);
  while (v) {
    if (v & 1) {
      res = Mul(res, u);
    }
    u = Mul(u, u);
    v >>= 1;
  }
  return res;
}

int main() {
  cin >> n;
  matrix base;
  base.a[0][0] = base.a[1][1] = 3;
  base.a[0][1] = base.a[1][0] = 1;
  matrix A;
  A.a[0][0] = 1;
  matrix res = Mul(A, Pow(base, n));
  cout << res.a[0][0];
  return 0;
}