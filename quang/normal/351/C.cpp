#include <bits/stdc++.h>

using namespace std;

typedef vector <long long> vi;
typedef vector <vi> vvi;

int n, m;
long long a[50], b[50];

vvi Mul(const vvi a, const vvi b) {
  vvi res(a.size(), vi(a.size(), 1e15));
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < a.size(); j++) {
      for (int k = 0; k < a.size(); k++) {
        res[i][j] = min(res[i][j], a[i][k] + b[k][j]);
      }
    }
  }
  return res;
}

vvi Pow(vvi u, int v) {
  vvi res(u.size(), vi(u.size(), 1e15));
  for (int i = 0; i < u.size(); i++) {
    res[i][i] = 0;
  }
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
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  vvi A(n * 2 + 1, vi(n * 2 + 1, 1e15));
  for (int i = 0; i < A.size(); i++) {
    A[i][i] = 0;
  }
  for (int x = 0; x < n; x++) {
    vvi B = A;
    for (int i = 0; i < A.size(); i++) {
      for (int j = 0; j < A.size(); j++) {
        B[i][j] = 1e15;
      }
    }
    for (int i = 0; i < A.size(); i++) {
      for (int j = 0; j < A.size(); j++) {
        if (j) {
          B[i][j] = min(B[i][j], A[i][j - 1] + a[x]);
        }
        if (j < A.size() - 1) {
          B[i][j] = min(B[i][j], A[i][j + 1] + b[x]);
        }
      }
    }
    A = B;
  }
  /*for (auto x : A) {
    for (int y : x) {
      cout << y << " ";
    }
    cout << endl;
  }*/
  cout << Pow(A, m)[0][0] << endl;
  return 0;
}