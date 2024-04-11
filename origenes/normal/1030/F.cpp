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

const int maxn = 212345;
const int MOD = 1e9 + 7;

struct Fenwick {
  vector<ll> fen;
  int n;

  Fenwick(int n) : fen(n + 1), n(n) {}

  int lowbit(int x) {
    return x & -x;
  }

  void add(int x, ll d) {
    while (x <= n) {
      fen[x] += d;
      x += lowbit(x);
    }
  }

  ll query(int x) {
    ll ret = 0;
    while (x) {
      ret = ret + fen[x];
      x -= lowbit(x);
    }
    return ret;
  }

  ll query(int l, int r) {
    if (l > r) return 0;
    ll ans = query(r) - query(l - 1);
    return ans;
  }
};

int n, q;
int a[maxn], w[maxn];

int main() {
  scanf("%d%d", &n, &q);
  FOR(i, 1, n) {
    scanf("%d", a + i);
    a[i] -= i;
  }
  FOR(i, 1, n) scanf("%d", w + i);
  Fenwick f1(n), f2(n);
  FOR(i, 1, n) {
    f1.add(i, w[i]);
    f2.add(i, ll(w[i]) * a[i] % MOD);
  }
  while (q--) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x < 0) {
      x = -x;
      int dw = y - w[x];
      f1.add(x, dw);
      f2.add(x, ll(a[x]) * dw % MOD);
      w[x] = y;
    } else {
      int lo = x, hi = y;
      ll tot = f1.query(x, y);
      while (lo < hi) {
        int mi = lo + hi >> 1;
        if (f1.query(x, mi) * 2 >= tot) hi = mi;
        else lo = mi + 1;
      }
      ll ans = f1.query(x, lo) % MOD * a[lo] - f2.query(x, lo) % MOD + f2.query(lo + 1, y) % MOD - f1.query(lo + 1, y) % MOD * a[lo];
      ans %= MOD;
      if (ans < 0) ans += MOD;
      printf("%lld\n", ans);
    }
  }
}