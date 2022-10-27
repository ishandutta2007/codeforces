#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 100005, mod = 998244353;
int a[N], mp[N];

int add(int x, int y) { return x + y < mod ? x + y : x + y - mod; }

int solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  int ans = 0, f[1000] = {0};
  f[1] = 1;
  for (int i = n - 1; i; i--) {
    int g[1000] = {0};
    g[1] = 1;
    for (int l = 1, r, cnt = 0; l <= a[i]; l = r + 1) {
      r = a[i] / (a[i] / l);
      mp[r] = ++cnt;
    }

    for (int l = 1, r, cnt = 0; l <= a[i + 1]; l = r + 1) {
      r = a[i + 1] / (a[i + 1] / l);
      cnt++;
      int x = a[i + 1] / r;
      int y = (a[i] - 1) / x + 1;
      ans = (ans + 1ll * (y - 1) * i % mod * f[cnt]) % mod;
      y = mp[a[i] / (a[i] / y)];
      g[y] = add(g[y], f[cnt]);
    }

    memcpy(f, g, sizeof g);
  }

  return ans;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--)
    cout << solve() << '\n';
}