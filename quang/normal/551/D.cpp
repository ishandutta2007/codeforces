#include <bits/stdc++.h>

using namespace std;

typedef vector<vector <int> > vt;

long long n, k;
int l, m;

vt qmul(const vt &a, const vt &b) {
  vt res(a.size(), vector <int> (b[0].size(), 0));
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < b[0].size(); j++) {
      for (int k = 0; k < b.size(); k++) {
        res[i][j] = (1ll * a[i][k] * b[k][j] + res[i][j]) % m;
      }
    }
  }
  return res;
}

vt qpow(vt a, long long u) {
  vt res(a.size(), vector <int> (a.size(), 0));
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
  cin >> n >> k >> l >> m;
  if (k >= (1ll << l) && l < 63) {
    cout << 0 << endl;
    return 0;
  }
  vt a(1, vector <int> (4));
  a[0][0] = 2;
  a[0][1] = 1;
  a[0][2] = 0;
  a[0][3] = 1;
  vt b(4, vector <int> (4, 0));
  b[0][0] = b[0][1] = b[1][0] = b[1][3] = 1;
  b[2][2] = b[2][3] = b[3][2] = b[3][3] = 1;
  vt res = qmul(a, qpow(b, n - 2));
  int ways0 = (res[0][0] + res[0][1]) % m;
  int ways1 = (res[0][2] + res[0][3]) % m;
  int ans = 1 % m;
  for (int i = 0; i < l; i++) {
    if (k & (1ll << i)) {
      ans = (1ll * ans * ways1) % m;
    } else {
      ans = (1ll * ans * ways0)  % m;
    }
  }
  cout << ans << endl;
  return 0;
}