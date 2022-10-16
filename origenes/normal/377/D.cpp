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

struct Seg {
  int l, r, mx, pos, lzy;
} T[maxn << 2];

void build(int o, int l, int r) {
  T[o].l = l, T[o].r = r;
  T[o].pos = l;
  if (l < r) {
    int mi = l + r >> 1;
    build(o << 1, l, mi);
    build(o << 1 | 1, mi + 1, r);
  }
}

inline void push_down(int o) {
  T[o << 1].lzy += T[o].lzy, T[o << 1].mx += T[o].lzy;
  T[o << 1 | 1].lzy += T[o].lzy, T[o << 1 | 1].mx += T[o].lzy;
  T[o].lzy = 0;
}

inline void push_up(int o) {
  if (T[o << 1].mx >= T[o << 1 | 1].mx) {
    T[o].mx = T[o << 1].mx;
    T[o].pos = T[o << 1].pos;
  } else {
    T[o].mx = T[o << 1 | 1].mx;
    T[o].pos = T[o << 1 | 1].pos;
  }
}

void add(int o, int l, int r, int v) {
  if (l <= T[o].l && T[o].r <= r) {
    T[o].lzy += v;
    T[o].mx += v;
    return;
  }
  int mi = T[o].l + T[o].r >> 1;
  push_down(o);
  if (l <= mi) add(o << 1, l, r, v);
  if (r > mi) add(o << 1 | 1, l, r, v);
  push_up(o);
}

int n, l[maxn], r[maxn], v[maxn];
vector<pii> in[maxn], out[maxn];

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) {
    scanf("%d%d%d", l + i, v + i, r + i);
    in[v[i]].eb(l[i], v[i]);
    out[r[i]].eb(l[i], v[i]);
  }
  build(1, 1, 3e5);
  int mx = 0, x, y;
  FOR(i, 1, 3e5) {
    for (auto q : in[i]) add(1, q._1, q._2, 1);
    if (T[1].mx > mx) {
      mx = T[1].mx;
      x = T[1].pos, y = i;
    }
    for (auto q : out[i]) add(1, q._1, q._2, -1);
  }
  printf("%d\n", mx);
  FOR(i, 1, n) if (l[i] <= x && x <= v[i] && v[i] <= y && y <= r[i]) printf("%d ", i);
}