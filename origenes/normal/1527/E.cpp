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

const int maxn = 35123;

struct Seg {
  int l, r;
  int v, lzy;
} T[101][maxn << 2];

int n, k;
int a[maxn], last[maxn], pre[maxn];

void build(Seg *T, int o, int l, int r) {
  T[o].l = l, T[o].r = r;
  T[o].v = 1e9;
  if (l < r) {
    int mi = l + r >> 1;
    build(T, o << 1, l, mi);
    build(T, o << 1 | 1, mi + 1, r);
  }
}

void push_down(Seg *T, int o) {
  T[o << 1].v += T[o].lzy; T[o << 1].lzy += T[o].lzy;
  T[o << 1 | 1].v += T[o].lzy; T[o << 1 | 1].lzy += T[o].lzy;
  T[o].lzy = 0;
}

void push_up(Seg *T, int o) {
  T[o].v = min(T[o << 1].v, T[o << 1 | 1].v);
}

void add(Seg *T, int o, int l, int r, int v) {
  if (l <= T[o].l && T[o].r <= r) {
    T[o].v += v;
    T[o].lzy += v;
    return;
  }
  push_down(T, o);
  int mi = T[o].l + T[o].r >> 1;
  if (l <= mi) add(T, o << 1, l, r, v);
  if (r > mi) add(T, o << 1 | 1, l, r, v);
  push_up(T, o);
}

int query(Seg *T, int o, int l, int r) {
  if (l <= T[o].l && T[o].r <= r) return T[o].v;
  push_down(T, o);
  int mi = T[o].l + T[o].r >> 1, ret = 1e9;
  if (l <= mi) chkmin(ret, query(T, o << 1, l, r));
  if (r > mi) chkmin(ret, query(T, o << 1 | 1, l, r));
  return ret;
}

void fix(Seg *T, int o, int x, int v) {
  if (T[o].l == T[o].r) {
    T[o].v = v;
    return;
  }
  push_down(T, o);
  int mi = T[o].l + T[o].r >> 1;
  if (x <= mi) fix(T, o << 1, x, v);
  else fix(T, o << 1 | 1, x, v);
  push_up(T, o);
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> k;
  FOR(i, 1, n) cin >> a[i];
  REP(i, k + 1) build(T[i], 1, 0, n);
  FOR(i, 1, n) {
    pre[i] = last[a[i]];
    last[a[i]] = i;
  }
  fix(T[0], 1, 0, 0);
  FOR(r, 1, n) REP(i, k) {
    if (pre[r] > 0) add(T[i], 1, 0, pre[r] - 1, r - pre[r]);
    fix(T[i + 1], 1, r, query(T[i], 1, 0, r - 1));
  }
  cout << query(T[k], 1, n, n);
}