#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  string s;
  cin >> s;

  const int mod = 1e9 + 7;
  const auto Add = [&](int a, int b) {
    a += b;
    if (a >= mod) {
      a -= mod;
    }
    return a;
  };

  const auto Mul = [&](int a, int b) {
    return 1ll * a * b % mod;
  };

  const auto Power = [&](int a, int b) {
    int res = 1;
    while (b > 0) {
      if (b & 1) {
        res = Mul(res, a);
      }
      a = Mul(a, a);
      b /= 2;
    }
    return res;
  };

  vector<vector<int>> psum(n, vector<int>(4));
  for (int i = 0; i < n; i++) {
    if (s[i] == '?') {
      psum[i][0]++;
    } else {
      psum[i][s[i] - 'a' + 1]++;
    }
    if (i > 0) {
      for (int j = 0; j < 4; j++) {
        psum[i][j] += psum[i - 1][j];
      }
    }
  }
  const auto sum = [&](int l, int r, int t) {
    return (r >= 0 ? psum[r][t] : 0) - (l > 0 ? psum[l - 1][t] : 0);
  };
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'b' || s[i] == '?') {
      int al = sum(0, i - 1, 1);
      int ml = sum(0, i - 1, 0);
      int cr = sum(i + 1, n - 1, 3);
      int mr = sum(i + 1, n - 1, 0);
      ans = Add(ans, Mul(Mul(al, cr), Power(3, ml + mr)));
      ans = Add(ans, Mul(Mul(al, mr), Power(3, ml + mr - 1)));
      ans = Add(ans, Mul(Mul(ml, cr), Power(3, ml + mr - 1)));
      ans = Add(ans, Mul(Mul(ml, mr), Power(3, ml + mr - 2)));      
    }
  }
  cout << ans << "\n";
  return 0;
}