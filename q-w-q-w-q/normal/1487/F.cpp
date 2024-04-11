#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 5155;
int n;
char str[N];
int t[N], f[10 * N][2], h[10 * N][2];

int reduce(int x) {
  x %= 10;
  return x < 0 ? x + 10 : x;
}

int dv(int x) {
  if (x >= 0)
    return x / 10;
  x = -x;
  return -((x - 1) / 10 + 1);
}

int dfs(int i, int lt, int g) {
  if (i >= n && lt == 0 && g == 0)
    return 0;
  if (i > n + 5)
    return 1 << 30;
  if (abs(g) > 5 * (n + 10 - i))
    return 1 << 30;
  if (i >= 10)
    return f[5 * N + g][1 + lt];
  int x = reduce(t[i] - lt);
  while (x - 10 >= -5 - (i == 1))
    x -= 10;
  int ans = 1 << 30;
  while (x <= 5 + (i == 1))
    ans = min(ans, abs(x) * i + dfs(i + 1, dv(x + lt), g + x)), x += 10;
  return ans;
}

void solve() {
  cin >> str, n = strlen(str);
  reverse(str, str + n);
  for (int i = 0; i != n; i++)
    t[i] = (str[i] - '0') * 9;
  for (int i = 0; i != n; i++)
    t[i + 1] += t[i] / 10, t[i] %= 10;
  while (t[n])
    t[n + 1] += t[n] / 10, t[n] %= 10, n++;

  f[5 * N][1] = 0;
  for (int e = n + 4; e >= 10; e--) {
    memset(h, 0x3f, sizeof h);
    for (int g = -5 * (n + 10 - e); g <= 5 * (n + 10 - e); g++)
      for (int lt = -1; lt <= 0; lt++) {
        int x = reduce(t[e] - lt);
        if (x - 10 >= -5)
          x -= 10;
        h[5 * N + g][1 + lt] = abs(x) * e + f[5 * N + g + x][1 + dv(lt + x)];
        x += 10;
        if (x <= 5)
          h[5 * N + g][1 + lt] = min(h[5 * N + g][1 + lt], abs(x) * e + f[5 * N + g + x][1 + dv(lt + x)]);
      }
    if (e >= n)
      h[5 * N][1] = 0;
    memcpy(f, h, sizeof h);
  }

  int ans = 1 << 30;
  for (int i = -5 * n - 50; i <= 5 * n + 50; i++)
    if (reduce(i) == t[0])
      ans = min(ans, dfs(1, dv(i), i));
  cout << ans << '\n';
}

void clear() {
  memset(t, 0, sizeof t);
  memset(f, 0x3f, sizeof f);
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int t = 1;
  while (t--) {
    clear();
    solve();
  }
}