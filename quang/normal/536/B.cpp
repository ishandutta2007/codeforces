#include <bits/stdc++.h>

using namespace std;

const int N = 1000010, MOD = 1000000007;

int n, m, len;
int a[N], t[N], dd[N];
string p;

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  cin >> p;
  a[0] = 0;
  for (int i = 1; i <= m; i++) {
    cin >> a[i];
  }
  len = p.size();
  p = 'Q' + p;
  int res = 1;
  int pos = 0;
  for (int i = 2; i <= len; i++) {
    while (pos && p[i] != p[pos + 1]) {
      pos = t[pos];
    }
    pos += (p[i] == p[pos + 1]);
    t[i] = pos;
  }
  pos = t[len];
  while (pos) {
    dd[pos] = 1;
    pos = t[pos];
  }
  int r = 0, cur = 1;
  for (int i = 1; i <= n; i++) {
    if (cur <= m && (i == a[cur])) {
      if (r >= i) {
        if (dd[r - i + 1] == 0) {
          cout << 0;
          return 0;
        }
      }
      r = i + len - 1;
      cur++;
    }
    if (i > r) {
      res = (1ll * res * 26) % MOD;
    }
  }
  cout << res;
  return 0;
}