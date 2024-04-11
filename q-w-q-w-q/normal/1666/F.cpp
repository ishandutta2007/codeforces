#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 5005, mod = 998244353;
int n, a[N], f[N][N >> 1];
int s[N], sum[N], c[N][N];
int g[N];

int add(int x, int y) { return x + y < mod ? x + y : x + y - mod; }

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 0; i <= n; i++) {
    c[i][0] = c[i][i] = 1;
    for (int j = 1; j < i; j++)
      c[i][j] = add(c[i - 1][j], c[i - 1][j - 1]);
  }

  if (n == 2) {
    if (a[1] == a[2])
      cout << 0 << '\n';
    else
      cout << 1 << '\n';
    return;
  }

  int cnt = 0;
  for (int i = n; i; i--)
    if (a[i] == a[i + 1])
      s[cnt]++;
    else
      s[++cnt] = 1;
  for (int i = 1; i <= cnt; i++)
    sum[i] = sum[i - 1] + s[i];
  g[cnt + 1] = 1;
  for (int i = cnt; i; i--)
    g[i] = 1ll * g[i + 1] * c[n - sum[i - 1]][s[i]] % mod;

  f[0][0] = 1;
  int ans = 0;
  for (int i = 1; i <= cnt; i++) {
    for (int j = 1; j < i && j <= n / 2; j++) {
      int r = j - 1 - (sum[i - 1] - j);
      if (r < 0)
        continue;
      f[i][j] = 1ll * f[i - 1][j] * c[r][s[i]] % mod;
    }
    for (int j = 0; j < i && j < n / 2; j++) {
      if (j == 0) {
        if (s[i] > 1)
          continue;
        f[i][1] = add(f[i][1], f[i - 1][0]);
        continue;
      }
      int r = j - 1 - (sum[i - 1] - j);
      if (r < 0)
        continue;
      int x = 1ll * f[i - 1][j] * c[r][s[i] - 1] % mod;
      f[i][j + 1] = add(f[i][j + 1], x);
      if (j == n / 2 - 1)
        ans = (ans + 1ll * x * g[i + 1]) % mod;
    }
  }
  cout << ans << '\n';
}

void clear() {
  for (int i = 1; i <= n; i++)
    memset(f[i], 0, sizeof f[i]);
  memset(s, 0, sizeof s), memset(sum, 0, sizeof sum);
  memset(a, 0, sizeof a);
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    solve();
    clear();
  }
}