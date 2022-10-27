#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 200005, mod = 1e9 + 7;
int n, f[N], g[N], a[N], h[N];
pair<int, int> v[N];

int add(int x, int y) { return x + y < mod ? x + y : x + y - mod; }

namespace bits {
int s1[N], s2[N];

void gu(int x, int v1, int v2) {
  while (x <= n)
    s1[x] = add(s1[x], v1), s2[x] = add(s2[x], v2), x += x & (-x);
}

void query(int x, int &a, int &b) {
  while (x) {
    a = add(a, s1[x]);
    b = add(b, s2[x]);
    x &= x - 1;
  }
}

void clear() {
  memset(s1, 0, (n + 1) << 2);
  memset(s2, 0, (n + 1) << 2);
}
} // namespace bits

namespace bits2 {
int s[N];

void gu(int x, int v) {
  while (x)
    s[x] = add(s[x], v), x &= x - 1;
}

int query(int x) {
  int sum = 0;
  while (x <= n)
    sum = add(sum, s[x]), x += x & (-x);
  return sum;
}

void clear(int x) {
  while (x)
    s[x] = 0, x &= x - 1;
}
} // namespace bits2

void uupd(int i) {
  int s1 = 0, s2 = 0;
  bits::query(i, s1, s2);
  s1 = add(s1, 1), s2 = add(s2, s1);
  f[i] = s1, g[i] = s2;
  bits::gu(i, s1, s2);
}

void upd(int l, int r) {
  for (int i = l; i <= r; i++) {
    int x = -v[i].second;
    int s1 = 0, s2 = 0;
    bits::query(x, s1, s2);
    s1 = add(s1, 1), s2 = add(s2, s1);
    bits::gu(x, s1, s2);
  }
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> v[i].first, v[i].second = -i;
  sort(v + 1, v + n + 1);
  for (int i = 1; i <= n; i++)
    a[-v[i].second] = i;

  for (int i = 1; i <= n; i++) {
    int s1 = 0, s2 = 0;
    bits::query(a[i], s1, s2);
    s1 = add(s1, 1), s2 = add(s2, s1);
    f[i] = s1, g[i] = s2;
    bits::gu(a[i], s1, s2);
  }

  bits::clear();

  int ans = 0;
  for (int i = n, lt = 0; lt != n; i--) {
    if (a[i] < lt)
      continue;

    upd(lt + 1, a[i]);
    if (a[i] == n) {
      for (int j = i - 1; j; j--)
        ans = add(ans, g[j]);
    } else {
      int p = 0;
      for (int j = i - 1;; j--)
        if (a[j] > a[i]) {
          p = j;
          break;
        } else
          ans = add(ans, g[j]);
      bits2::gu(p, 1);
      h[p] = 1;
      for (int q = a[p] - 1; q > a[i]; q--) {
        int x = -v[q].second;
        h[x] = bits2::query(x);
        bits2::gu(x, h[x]);
      }
      for (int q = a[p]; q > a[i]; q--)
        bits2::clear(-v[q].second);

      for (int q = a[i] + 1; q <= a[p]; q++) {
        int x = -v[q].second;
        int s1 = 0, s2 = 0;
        bits::query(x, s1, s2);
        ans = (ans + 1ll * s2 * h[x]) % mod;
      }
    }

    lt = a[i];
  }

  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    solve();
    bits::clear();
  }
}