#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 1005, mod = 998244353;
int fa[N << 1], op[N << 1];
int u[N << 1];
char s[N];

int get(int x, int n) {
  if (x < n / 2)
    return x;
  return n - 1 - x;
}

int find(int x) {
  if (x == fa[x])
    return x;
  int y = fa[x], z = find(y);
  op[x] ^= op[y], fa[x] = z;
  return z;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> s;
  int n = strlen(s);
  reverse(s, s + n);
  if (s[0] == '1') {
    cout << 0;
    return 0;
  }
  s[0] = '0';

  int ans = 0;
  for (int l = 1; l < n; l++) {
    memset(fa, 0, sizeof fa);
    memset(op, 0, sizeof op);
    memset(u, -1, sizeof u);
    for (int i = 0; i <= 2 * n; i++)
      fa[i] = i;

    bool ok = 1;
    for (int i = 0; i < l; i++) {
      if (s[i] == '?')
        continue;
      int t1 = get(i, n), t2 = get(i, l);
      int x = find(t1), y = find(n + t2);
      if (s[i] == '0') {
        if (x == y) {
          if (op[t1] != op[n + t2])
            ok = 0;
        } else {
          fa[y] = x;
          op[y] = op[t1] ^ op[n + t2];
        }
      } else {
        if (x == y) {
          if (op[t1] == op[n + t2])
            ok = 0;
        } else {
          fa[y] = x;
          op[y] = op[t1] ^ op[n + t2] ^ 1;
        }
      }
    }

    if (!ok)
      continue;
    for (int i = l; i < n; i++) {
      if (s[i] == '?')
        continue;
      int x = get(i, n), y = find(x);
      int z = s[i] - '0';
      if (u[y] == -1)
        u[y] = z ^ op[x];
      else if (u[y] != (z ^ op[x]))
        ok = 0;
    }

    if (!ok)
      continue;

    int tp = 1;
    for (int i = 0; i < n; i++) {
      int x = get(i, n);
      if (x == i && find(x) == x && u[x] == -1)
        tp = 1ll * tp * 2 % mod;
    }
    for (int i = 0; i < l; i++) {
      int x = get(i, l);
      if (x == i && find(n + x) == n + x && u[n + x] == -1)
        tp = 1ll * tp * 2 % mod;
    }

    ans = (ans + tp) % mod;
  }

  cout << ans;
}