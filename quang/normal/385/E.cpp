#include <bits/stdc++.h>

using namespace std;

typedef vector<int> v;
typedef vector<v> vv;

int n, sx, sy, dx, dy;
long long t;

vv qmul(const vv &a, const vv &b) {
  vv res(a.size(), v(b[0].size(), 0));
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < b[0].size(); j++) {
      for (int k = 0; k < b.size(); k++) {
        res[i][j] = (1ll * a[i][k] * b[k][j] + res[i][j]) % n;
      }
    }
  }
  return res;
}

vv qpow(vv a, long long u) {
  vv res(a.size(), v(a.size(), 0));
  for (int i = 0; i < a.size(); i++) {
    res[i][i] = 1;
  }
  while (u) {
    if (u & 1) {
      res = qmul(res, a);
    }
    a = qmul(a, a);
    u >>= 1;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(0);
#ifdef Doflamingo
  freopen("input", "r", stdin);
#endif // Doflamingo
  cin >> n >> sx >> sy >> dx >> dy >> t;
  dx %= n, dy %= n;
  dx = (dx + n) % n;
  dy = (dy + n) % n;
  sx--, sy--;
  vv A(1, v(6));
  A[0][0] = sx, A[0][1] = sy, A[0][2] = dx, A[0][3] = dy, A[0][4] = 0, A[0][5] = 1;
  vv B(6, v(6, 0));
  B[0][0] = B[5][0] = B[5][1] = B[5][2] = B[5][3] = B[1][1] = 2;
  B[0][1] = B[0][2] = B[0][3] = B[1][0] = B[1][2] = B[1][3] = B[2][0] = B[2][2] = B[3][1] = B[3][3] = B[4][2] = B[4][3] = B[4][4] = B[5][4] = B[5][5] = B[4][0] = B[4][1] = 1;
  vv res = qmul(A, qpow(B, t));
  cout << res[0][0] + 1 << " " << res[0][1] + 1 << endl;
  return 0;
}