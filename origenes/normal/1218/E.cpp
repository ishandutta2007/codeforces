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

const int MOD = 998244353;

ll pow_mod(ll x, ll k) {
  ll ret = 1;
  while (k) {
    if (k & 1) ret = ret * x % MOD;
    x = x * x % MOD;
    k >>= 1;
  }
  return ret;
}

ll inv(ll a) {
  return pow_mod(a, MOD - 2);
}

namespace NTT {
  const int maxlog = 22;
  const int maxn = 2123456;

  vector<int> w[maxlog], rv[maxlog];
  ll a[maxn], b[maxn];

  void init(ll g = 3) {
    ll wb = pow_mod(g, (MOD - 1) / (1 << maxlog));
    REP(st, maxlog - 1)
    {
      w[st].assign(1 << st, 1);
      ll bw = pow_mod(wb, 1 << maxlog - st - 1), cw = 1;
      REP(k, 1 << st)
      {
        w[st][k] = cw;
        cw = cw * bw % MOD;
      }
    }
    REP(st, maxlog)
    {
      rv[st].assign(1 << st, 0);
      if (!st) {
        rv[st][0] = 0;
        continue;
      }
      int h = 1 << st - 1;
      REP(k, 1 << st)
      rv[st][k] = (rv[st - 1][k & (h - 1)] << 1) | (k >= h);
    }
  }

  void ntt(ll *a, int n, bool inv = false) {
    int ln = 0;
    while ((1 << ln) < n) ln++;
    assert((1 << ln) < maxn);
    n = (1 << ln);
    REP(i, n)
    {
      int ni = rv[ln][i];
      if (i < ni) swap(a[i], a[ni]);
    }
    for (int st = 0; (1 << st) < n; st++) {
      int len = (1 << st);
      for (int k = 0; k < n; k += (len << 1)) {
        for (int pos = k; pos < k + len; pos++) {
          ll l = a[pos], r = a[pos + len] * w[st][pos - k] % MOD;
          a[pos] = l + r;
          if (a[pos] >= MOD) a[pos] -= MOD;
          a[pos + len] = l - r;
          if (a[pos + len] < 0) a[pos + len] += MOD;
        }
      }
    }
    if (inv) {
      ll den = ::inv(n);
      REP(i, n)
      a[i] = a[i] * den % MOD;
      reverse(a + 1, a + n);
    }
  }

  vector <ll> mul(const vector <ll> &u, const vector <ll> &v) {
    int len = 1;
    while (len < u.size() + v.size()) len <<= 1;
    REP(i, len)
    {
      a[i] = i < u.size() ? u[i] : 0;
      b[i] = i < v.size() ? v[i] : 0;
    }
    ntt(a, len);
    ntt(b, len);
    REP(i, len)
    a[i] = a[i] * b[i] % MOD;
    ntt(a, len, true);
    vector <ll> ret(len);
    REP(i, len)
    ret[i] = a[i];
    while (ret.size() > 1 && ret.back() == 0) ret.pop_back();
    return ret;
  }
};

const int maxn = 21234;

vector<ll> poly[maxn << 2];

int n, Q, k;
int a[maxn], b[maxn];

void solve(int o, int l, int r) {
  if (l == r) {
    poly[o] = {1, b[l]};
    return;
  }
  int mi = l + r >> 1;
  solve(o << 1, l, mi);
  solve(o << 1 | 1, mi + 1, r);
  poly[o] = NTT::mul(poly[o << 1], poly[o << 1 | 1]);
}

int main() {
  NTT::init();
  scanf("%d%d", &n, &k);
  FOR(i, 1, n) {
    scanf("%d", a + i);
    a[i] %= MOD;
  }
  scanf("%d", &Q);
  while (Q--) {
    int op, q; scanf("%d%d", &op, &q);
    if (op == 1) {
      int i, d;
      scanf("%d%d", &i, &d);
      q %= MOD, d %= MOD;
      FOR(j, 1, n) {
        b[j] = j == i ? q - d : q - a[j];
        if (b[j] < 0) b[j] += MOD;
      }
    } else {
      int l, r, d;
      scanf("%d%d%d", &l, &r, &d);
      q %= MOD, d %= MOD;
      FOR(i, 1, n) {
        if (l <= i && i <= r) b[i] = ((q - a[i] - d) % MOD + MOD) % MOD;
        else b[i] = (q - a[i] + MOD) % MOD;
      }
    }
    solve(1, 1, n);
    printf("%lld\n", poly[1][k]);
  }
}