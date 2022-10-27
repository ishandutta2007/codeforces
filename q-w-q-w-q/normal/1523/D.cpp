#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#include <random>
using namespace std;
typedef long long ll;
const int mod = 998244353;
int n, m, p;
ll a[200005];
int sum[1 << 15];
int cnt;
int ans1;
ll ans2, val[1 << 15], qwq[15];
char s[61];
inline ll lb(ll x) { return x & (-x); }
inline int power(int a, int n) {
  int tp = 1;
  while (n) {
    if (n & 1) tp = 1ll * tp * a % mod;
    a = 1ll * a * a % mod, n >>= 1;
  }
  return tp;
}
inline void fmt(int *a, int n) {
  for (int l = 1; l < n; l <<= 1)
    for (int i = 0; i < n; i += l)
      for (int j = 0; j < l; j++, i++)
        a[i] += a[i | l];
}
int main() {
  cin >> n >> m >> p;
  int gu;
  for (int i = 1; i <= n; i++) {
    scanf("%s", s);
    for (int j = 0; j < m; j++)
      if (s[j] == '1') a[i] |= 1ll << j;
    gu ^= a[i] % mod * power(gu, 1ll * i * (i - 1) / 2 % (mod - 1));
  }
  mt19937 rnd(gu ^ time(0));
  for (int t = 1; t <= 30; t++) {
    int x = rnd() % n + 1;
    memset(sum, 0, sizeof sum);
    cnt = 0;
    ll tp = a[x];
    while (tp) val[1 << cnt] = lb(tp), qwq[cnt++] = lb(tp), tp -= lb(tp);
    for (int i = 1; i <= n; i++) {
      tp = a[i] & a[x];
      int s = 0;
      while (tp) {
        int pos = lower_bound(qwq, qwq + cnt, lb(tp)) - qwq;
        s |= 1 << pos, tp -= lb(tp);
      }
      sum[s]++;
    }
    fmt(sum, 1 << cnt);
    for (int i = 1; i < (1 << cnt); i++)
      if (sum[i] * 2 >= n && __builtin_popcount(i) > ans1) {
        ans1 = __builtin_popcount(i), ans2 = 0;
        for (int j = i; j; j -= lb(j)) ans2 |= val[lb(j)];
      }
  }
  for (int i = 0; i < m; i++, ans2 >>= 1) cout << (ans2 & 1);
}