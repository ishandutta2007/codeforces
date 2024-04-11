#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007, N = 110;

int n, b, k, x;

struct matrix {
  int a[N][N];

  matrix(int dia = 0) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        a[i][j] = 0;
        if (i == j) {
          a[i][j] = dia;
        }
      }
    }
  }
};

int cnt[20];

inline int add(int u, int v) {
  u += v;
  if (u >= MOD) {
    u -= MOD;
  }
  return u;
}

inline int mul(int u, int v) {
  return (long long) u * v % MOD;
}

matrix matrix_mul(const matrix &u, const matrix &v) {
  matrix res(0);
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < x; j++) {
      for (int k = 0; k < x; k++) {
        res.a[i][j] = add(res.a[i][j], mul(u.a[i][k], v.a[k][j]));
      }
    }
  }
  return res;
}

matrix matrix_Power(matrix u, int v) {
  matrix res(1);
  while (v) {
    if (v & 1) {
      res = matrix_mul(res, u);
    }
    u = matrix_mul(u, u);
    v >>= 1;
  }
  return res;
}

int main() {
  scanf("%d %d %d %d", &n, &b, &k, &x);
  for (int i = 1; i <= n; i++) {
    int u;
    scanf("%d", &u);
    cnt[u]++;
  }
  matrix base(0);
  base.a[0][0] = 1;
  matrix a(0);
  for (int i = 0; i < x; i++) {
    for (int j = 1; j <= 9; j++) {
      int next = (i * 10 + j) % x;
      a.a[i][next] += cnt[j];
    }
  }
  a = matrix_Power(a, b);
  cout << matrix_mul(base, a).a[0][k] << endl;
  return 0;
}