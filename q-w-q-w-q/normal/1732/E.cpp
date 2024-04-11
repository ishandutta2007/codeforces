// LUOGU_RID: 91280335
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long i64;

const int N = 50505, B = 8;
int n, q;
int a[N], b[N];
int lazy[N >> B];
int v[N];
bool ok[N];
i64 dp[N >> B][N], mn[N >> B];

int gcd(int n, int m) { return !m ? n : gcd(m, n % m); }
i64 f(int n, int m) {
  int d = gcd(n, m);
  return 1ll * n * m / (1ll * d * d);
}

void cover(int b, int x, int y, int z) {
  int l = b << B, r = (b + 1) << B;
  if (lazy[b]) {
    for (int i = l; i != r && i != n; i++)
      a[i] = lazy[b];
    lazy[b] = 0;
  }
  for (int i = max(l, x); i != y && i != r && i != n; i++)
    a[i] = z;
  mn[b] = 1ll << 60;
  for (int i = l; i != r && i != n; i++)
    mn[b] = min(mn[b], f(a[i], ::b[i]));
}

i64 query(int b, int x, int y) {
  int l = b << B, r = (b + 1) << B;
  i64 ans = 1ll << 60;
  if (lazy[b]) {
    for (int i = l; i != r && i != n; i++)
      a[i] = lazy[b];
    lazy[b] = 0;
  }
  for (int i = max(x, l); i != r && i != y && i != n; i++)
    ans = min(ans, f(a[i], ::b[i]));
  return ans;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> n >> q;
  memset(mn, 0x3f, sizeof mn);
  memset(dp, 0x3f, sizeof dp);
  for (int i = 0; i != n; i++)
    cin >> a[i];
  for (int i = 0; i != n; i++)
    cin >> b[i], mn[i >> B] = min(mn[i >> B], f(a[i], b[i]));

  for (int i = 0; (i << B) < n; i++) {
    int l = i << B, r = (i + 1) << B;
    for (int j = l; j != r && j != n; j++)
      ok[b[j]] = 1;
    for (int k = 1; k <= 50000; k++) {
      for (int j = 1; k * j <= 50000; j++)
        if (ok[k * j]) {
          for (int l = 1; l * k <= 50000; l++)
            dp[i][l * k] = min(dp[i][l * k], 1ll * l * j);
          break;
        }
    }
    memset(ok, 0, sizeof ok);
  }


  while (q--) {
    int op, l, r;
    cin >> op >> l >> r, l--;
    if (op == 1) {
      int x;
      cin >> x;
      for (int i = l; i != r; i++)
        a[i] = x;
      cover(l >> B, l, r, x);
      if ((r >> B) != (l >> B))
        cover(r >> B, l, r, x);
      for (int i = (l >> B) + 1; i < (r >> B); i++)
        lazy[i] = x, mn[i] = dp[i][x];
    } else {
      i64 ans = query(l >> B, l, r);
      if ((r >> B) != (l >> B))
        ans = min(ans, query(r >> B, l, r));
      for (int i = (l >> B) + 1; i < (r >> B); i++)
        ans = min(ans, mn[i]);
      cout << ans << '\n';
    }
  }
}