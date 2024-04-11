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

int n, k, m;
int cnt[maxn * 2];

struct Seg {
  int l, r;
  int mx, lzy;
} T[maxn << 3];

void push_down(int o) {
  T[o << 1].lzy += T[o].lzy, T[o << 1].mx += T[o].lzy;
  T[o << 1 | 1].lzy += T[o].lzy, T[o << 1 | 1].mx += T[o].lzy;
  T[o].lzy = 0;
}

void push_up(int o) {
  T[o].mx = max(T[o << 1].mx, T[o << 1 | 1].mx);
}

void build(int o, int l, int r) {
  T[o].l = l, T[o].r = r;
  if (l == r) T[o].mx = l - n - 1;
  else {
    int mi = l + r >> 1;
    build(o << 1, l, mi);
    build(o << 1 | 1, mi + 1, r);
    push_up(o);
  }
}

void add(int o, int l, int r, int v) {
  if (l <= T[o].l && T[o].r <= r) {
    T[o].mx += v;
    T[o].lzy += v;
    return;
  }
  push_down(o);
  int mi = T[o].l + T[o].r >> 1;
  if (l <= mi) add(o << 1, l, r, v);
  if (r > mi) add(o << 1 | 1, l, r, v);
  push_up(o);
}

int query(int o, int l, int r) {
  if (l <= T[o].l && T[o].r <= r) return max(0, T[o].mx);
  int ret = 0, mi = T[o].l + T[o].r >> 1;
  push_down(o);
  if (l <= mi) chkmax(ret, query(o << 1, l, r));
  if (r > mi) chkmax(ret, query(o << 1 | 1, l, r));
  push_up(o);
  return ret;
}

int main() {
  scanf("%d%d%d", &n, &k, &m);
  build(1, 1, 2 * n);
  set<pii> s;
  set<int> val;
  while (m--) {
    int x, y;
    scanf("%d%d", &x, &y);
    int tar = y + abs(x - k);
    if (s.count(mp(x, y))) {
      s.erase(mp(x, y));
      if (!--cnt[tar]) val.erase(tar);
      add(1, 1, tar, -1);
    } else {
      s.emplace(x, y);
      cnt[tar]++;
      val.emplace(tar);
      add(1, 1, tar, 1);
    }
    if (val.empty()) puts("0");
    else printf("%d\n", query(1, 1, *val.rbegin()));
  }
}