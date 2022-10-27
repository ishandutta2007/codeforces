#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
const int N = 205;
int n, t, k;
ll a[N], b[N], c[N], sa[N], sb[N];
ll f0[N][N], g0[N][N], f[N][N], g[N][N];
int main() {
  cin >> n >> t >> k;
  for (int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];
  n++, a[n] = b[n] = k, c[n] = 1ll << 60;
  for (int i = 1; i <= n; i++) sa[i] = sa[i - 1] + a[i], sb[i] = sb[i - 1] + b[i];
  memset(f0, 0x3f, sizeof f0), memset(g0, 0x3f, sizeof g0);
  memset(f0[0], 0, sizeof f0[0]), memset(g0[0], 0, sizeof g0[0]);
  for (int i = 1; i <= n; i++) f0[i][0] = g0[i][0] = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= t; j++) {
      if (b[i] * j <= c[i]) {
        f0[i][j] = min(f0[i][j], f0[i - 1][j]);
        ll res = sb[i - 1] * j - f0[i - 1][j] * k;
        if (res >= 0) {
          ll x = res > 0 ? (res - 1) / k + 1 : 0;
          if (x * k <= res + b[i] * j) g0[i][j] = min(g0[i][j], f0[i - 1][j] + x);
        }
      }
      for (int t = 1; t < j; t++) {
        ll res = sb[i] * t - g0[i][t] * k;
        if (res < 0) continue;
        ll tp = res + (j - t) * b[i] - c[i];
        ll x = tp > 0 ? (tp - 1) / k + 1 : 0;
        if (x * k > res) continue;
        f0[i][j] = min(f0[i][j], g0[i][t] + x + f0[i - 1][j - t]);
        res = res - x * k + (j - t) * b[i];
        tp = sb[i - 1] * (j - t) - f0[i - 1][j - t] * k;
        if (tp < 0) continue;
        ll y = (tp - 1) / k + 1;
        if (y * k <= tp + res) g0[i][j] = min(g0[i][j], g0[i][t] + x + f0[i - 1][j - t] + y);
      }
    }
  memset(f, 0x3f, sizeof f), memset(g, 0x3f, sizeof g);
  memset(f[0], 0, sizeof f[0]), memset(g[0], 0, sizeof g[0]);
  for (int i = 1; i <= n; i++) {
    f[i][0] = 0;
    ll x = sa[i - 1] > 0 ? (sa[i - 1] - 1) / k + 1 : 0;
    if (x * k <= sa[i]) g[i][0] = x;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= t; j++) {
      if (a[i] + b[i] * j <= c[i]) {
        f[i][j] = min(f[i][j], f[i - 1][j]);
        ll res = sa[i - 1] + sb[i - 1] * j - f[i - 1][j] * k;
        if (res >= 0) {
          ll x = res > 0 ? (res - 1) / k + 1 : 0;
          if (x * k <= res + a[i] + b[i] * j) g[i][j] = min(g[i][j], f[i - 1][j] + x);
        }
      }
      for (int t = 0; t < j; t++) {
        ll res = sa[i] + sb[i] * t - g[i][t] * k;
        if (res < 0) continue;
        ll tp = res + (j - t) * b[i] - c[i];
        ll x = tp > 0 ? (tp - 1) / k + 1 : 0;
        if (x * k > res) continue;
        f[i][j] = min(f[i][j], g[i][t] + x + f0[i - 1][j - t]);
        res = res - x * k + (j - t) * b[i];
        tp = sb[i - 1] * (j - t) - f0[i - 1][j - t] * k;
        if (tp < 0) continue;
        ll y = (tp - 1) / k + 1;
        if (y * k <= tp + res) g[i][j] = min(g[i][j], g[i][t] + x + f0[i - 1][j - t] + y);
      }
    }
  cout << f[n][t];
}