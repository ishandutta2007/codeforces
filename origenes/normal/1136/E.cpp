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
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 112345;
const ll inf = 1e18;

struct Seg {
  int l, r;
  ll val, sum, lzy;
} T[maxn << 2];

ll a[maxn], k[maxn], val[maxn], s[maxn];
int n, q;
char op[5];

inline void pushdown(int o) {
  if (T[o].lzy != -inf) {
    T[o << 1].val = T[o << 1].lzy = T[o].lzy;
    T[o << 1].sum = (T[o << 1].r - T[o << 1].l + 1) * T[o].lzy;
    T[o << 1 | 1].val = T[o << 1 | 1].lzy = T[o].lzy;
    T[o << 1 | 1].sum = (T[o << 1 | 1].r - T[o << 1 | 1].l + 1) * T[o].lzy;
    T[o].lzy = -inf;
  }
}

inline void pushup(int o) {
  T[o].val = max(T[o << 1].val, T[o << 1 | 1].val);
  T[o].sum = T[o << 1].sum + T[o << 1 | 1].sum;
}

void build(int o, int l, int r) {
  T[o].l = l, T[o].r = r, T[o].lzy = -inf;
  if (l != r) {
    int m = l + r >> 1;
    build(o << 1, l, m);
    build(o << 1 | 1, m + 1, r);
    pushup(o);
  } else {
    T[o].val = T[o].sum = a[l];
  }
}

void update(int o, int l, int r, ll v) {
  if (l > r) return;
  if (l <= T[o].l && T[o].r <= r) {
    T[o].val = T[o].lzy = v;
    T[o].sum = (T[o].r - T[o].l + 1) * v;
    return;
  }
  pushdown(o);
  int m = T[o].l + T[o]. r >> 1;
  if (l <= m) update(o << 1, l, r, v);
  if (r > m) update(o << 1 | 1, l, r, v);
  pushup(o);
}

ll query(int o, int l, int r) {
  if (l > r) return -inf;
  if (l <= T[o].l && T[o].r <= r) return T[o].val;
  pushdown(o);
  int m = T[o].l + T[o].r >> 1;
  ll ret = -inf;
  if (l <= m) chkmax(ret, query(o << 1, l, r));
  if (r > m) chkmax(ret, query(o << 1 | 1, l, r));
  return ret;
}

ll sum(int o, int l, int r) {
  if (l > r) return 0;
  if (l <= T[o].l && T[o].r <= r) return T[o].sum;
  pushdown(o);
  int m = T[o].l + T[o].r >> 1;
  ll ret = 0;
  if (l <= m) ret += sum(o << 1, l, r);
  if (r > m) ret += sum(o << 1 | 1, l, r);
  return ret;
}

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%lld", a + i);
  FOR(i, 1, n - 1) {
    scanf("%lld", k + i);
    val[i] = val[i - 1] + k[i];
    a[i + 1] -= val[i];
    s[i] = s[i - 1] + val[i];
  }
  build(1, 1, n);
  scanf("%d", &q);
  while (q--) {
    int l, r;
    scanf("%s%d%d", op, &l, &r);
    if (op[0] == 's') {
      printf("%lld\n", sum(1, l, r) + s[r - 1] - (l >= 2 ? s[l - 2] : 0));
    } else {
      ll now = sum(1, l, l);
      int lo = l, hi = n;
      while (lo < hi) {
        int mi = lo + hi + 1 >> 1;
        if (query(1, l + 1, mi) >= now + r) hi = mi - 1;
        else lo = mi;
      }
      update(1, l, lo, now + r);
    }
  }
}