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

const int maxn = 312345;
const int MOD = 1e9 + 7;

inline int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

inline int mul(int a, int b) {
  return ll(a) * b % MOD;
}

int pow_mod(int a, int k) {
  int ret = 1;
  while (k) {
    if (k & 1) ret = mul(ret, a);
    a = mul(a, a);
    k >>= 1;
  }
  return ret;
}

struct Seg {
  int l, r;
  int v, sl, sr, cnt;
} T[maxn << 3];

int n, q;
int pw[maxn], id[maxn], pos[maxn * 2], now[maxn * 2];
pii p[maxn * 2];

void push_up(int o) {
  T[o].v = add(add(mul(T[o << 1].v, pw[T[o << 1 | 1].cnt]), mul(T[o << 1].sl, T[o << 1 | 1].sr)), mul(T[o << 1 | 1].v, pw[T[o << 1].cnt]));
  T[o].sl = add(T[o << 1].sl, mul(T[o << 1 | 1].sl, pw[T[o << 1].cnt]));
  T[o].sr = add(T[o << 1 | 1].sr, mul(T[o << 1].sr, pw[T[o << 1 | 1].cnt]));
  T[o].cnt = T[o << 1].cnt + T[o << 1 | 1].cnt;
}

void build(int o, int l, int r) {
  T[o].l = l, T[o].r = r;
  if (l < r) {
    int mi = l + r >> 1;
    build(o << 1, l, mi);
    build(o << 1 | 1, mi + 1, r);
    push_up(o);
  } else {
    if (p[l]._2 <= n) {
      now[p[l]._2] = pos[p[l]._2];
      T[o].cnt = 1;
      T[o].sl = T[o].sr = p[l]._1;
    }
  }
}

void update(int o, int x, int v) {
  if (T[o].l == T[o].r) {
    T[o].sl = T[o].sr = v;
    T[o].cnt = v > 0;
  } else {
    int mi = T[o].l + T[o].r >> 1;
    if (x <= mi) update(o << 1, x, v);
    else update(o << 1 | 1, x, v);
    push_up(o);
  }
}

int main() {
  scanf("%d", &n);
  pw[0] = 1;
  FOR(i, 1, n) pw[i] = add(pw[i - 1], pw[i - 1]);
  FOR(i, 1, n) {
    scanf("%d", &p[i]._1);
    p[i]._2 = i;
  }
  scanf("%d", &q);
  FOR(i, 1, q) {
    scanf("%d%d", id + i, &p[i + n]._1);
    p[i + n]._2 = i + n;
  }
  sort(p + 1, p + n + q + 1);
  FOR(i, 1, n + q) pos[p[i]._2] = i;
  int den = pow_mod(pw[n], MOD - 2);
  build(1, 1, n + q);
  printf("%d\n", mul(T[1].v, den));
  FOR(i, 1, q) {
    update(1, now[id[i]], 0);
    update(1, pos[n + i], p[pos[n + i]]._1);
    now[id[i]] = pos[n + i];
    printf("%d\n", mul(T[1].v, den));
  }
}