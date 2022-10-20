#include <bits/stdc++.h>

using namespace std;

const int N = 6010;

int n;
int x[N], y[N];
int cnt[16];
int num[4][16];

long long c3(int n) {
  return 1ll * n * (n - 1) * (n - 2) / 6;
}

long long c2(int n) {
  return 1ll * n * (n - 1) / 2;
}

int Get(int u1, int u2, int v1, int v2) {
  return ((u1 * v2) % 4 - (u2 * v1) % 4 + 4) % 4;
}

int GCD(int u1, int u2, int v1, int v2) {
  int x = (u1 - v1 + 4) % 4;
  int y = (u2 - v2 + 4) % 4;
  if (x % 2 == 1 || y % 2 == 1) return 1;
  if (x == 0 && y == 0) return 0;
  return 2;
}

bool Check(int u, int v, int t) {
  int u1 = (u / 4) % 4, u2 = u % 4;
  int v1 = (v / 4) % 4, v2 = v % 4;
  int t1 = (t / 4) % 4, t2 = t % 4;
  int res = 0;
  res = (res + Get(u1, u2, v1, v2)) % 4;
  res = (res + Get(v1, v2, t1, t2)) % 4;
  res = (res + Get(t1, t2, u1, u2)) % 4;
  if (res % 2) return 0;
  int now = 0;
  int foo = GCD(u1, u2, v1, v2);
  if (foo % 2) return 0;
  now = (now + foo) % 4;
  foo = GCD(v1, v2, t1, t2);
  if (foo % 2) return 0;
  now = (now + foo) % 4;
  foo = GCD(t1, t2, u1, u2);
  if (foo % 2) return 0;
  now = (now + foo) % 4;
  return res == now;
}

bool Check(int foo, int bar, int v, int t, int u) {
  int u1 = (u / 4) % 4, u2 = u % 4;
  int v1 = (v / 4) % 4, v2 = v % 4;
  int t1 = (t / 4) % 4, t2 = t % 4;
  int res = 0;
  res = (res + Get(u1, u2, v1, v2)) % 4;
  res = (res + Get(v1, v2, t1, t2)) % 4;
  res = (res + Get(t1, t2, u1, u2)) % 4;
  if (res % 2) return 0;
  int now = (foo + bar) % 4;
  if (res == now) return GCD(v1, v2, t1, t2) == 0;
  return GCD(v1, v2, t1, t2) == 2;
}

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
    cnt[(x[i] % 4) * 4 + (y[i] % 4)]++;
  }
  long long res = 0;
  for (int i = 0; i < 16; i++) {
    for (int j = i; j < 16; j++) {
      for (int k = j; k < 16; k++) {
        if (Check(i, j, k)) {
          if (i == j && j == k) {
            res += c3(cnt[i]);
          } else if (i == j) {
            res += c2(cnt[i]) * cnt[k];
          } else if (j == k) {
            res += c2(cnt[j]) * cnt[i];
          } else {
            res += 1ll * cnt[i] * cnt[j] * cnt[k];
          }
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    memset(num, 0, sizeof num);
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      int g = __gcd(abs(x[i] - x[j]), abs(y[i] - y[j])) % 4;
      num[g][(x[j] % 4) * 4 + (y[j] % 4)]++;
    }
    for (int ii = 1; ii <= 3; ii += 2) {
      for (int j = ii; j <= 3; j += 2) {
        for (int k = 0; k < 16; k++) {
          for (int l = 0; l < 16; l++) {
            if (ii == j && l < k) continue;
            if (Check(ii, j, k, l, (x[i] % 4) * 4 + (y[i] % 4))) {
              if (ii == j && k == l) res += c2(num[ii][k]);
              else res += 1ll * num[ii][k] * num[j][l];
            }
          }
        }
      }
    }
  }
  cout << res << endl;
  return 0;
}