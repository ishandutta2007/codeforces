#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 2123;
const int MOD = 1e9 + 7;
const int i2 = 5e8 + 4;

int n, m, q;
ll f[maxn][maxn], g[maxn];
int u[maxn], v[maxn], w[maxn];
vector<int> G[maxn];

inline ll calc(int i, ll x) {
  return (x - m) * w[i] + g[i];
}

int main() {
  scanf("%d%d%d", &n, &m, &q);
  FOR(i, 1, m) {
    scanf("%d%d%d", u + i, v + i, w + i);
    G[u[i]].eb(i);
    G[v[i]].eb(i);
  }
  reset(f, 0xc0);
  f[1][0] = 0;
  ll ans = 0;
  FOR(j, 1, m) {
    ll mx = -1e18;
    FOR(i, 1, n) {
      for (auto idx : G[i]) {
        int k = i ^ u[idx] ^ v[idx];
        chkmax(f[i][j], f[k][j - 1] + w[idx]);
      }
      chkmax(mx, f[i][j]);
    }
    ans = (ans + mx) % MOD;
  }
  FOR(i, 1, m) g[i] = max(f[u[i]][m], f[v[i]][m]);
  ll till = m + 1;
  while (till <= q) {
    int best = -1;
    ll mx = -1e18;
    FOR(i, 1, m) if (mx < calc(i, till)) {
      mx = calc(i, till);
      best = i;
    }
    ll l = till;
    till = q + 1;
    FOR(i, 1, m) if (w[i] > w[best]) {
      ll x = (g[best] - g[i]) / (w[i] - w[best]) + m + 1;
      chkmin(till, x);
    }
    ans = ans + (calc(best, l) + calc(best, till - 1)) % MOD * (till - l) % MOD * i2 % MOD;
    if (ans >= MOD) ans -= MOD;
  }
  printf("%lld", ans);
}