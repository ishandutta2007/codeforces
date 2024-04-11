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
const int inf = 2e9 + 10;

struct Seg {
  int l, r, v1[10], v2[10];
} T[maxn << 2];

int n, m;
int a[maxn];

void push_up(int o) {
  REP(i, 10) {
    T[o].v1[i] = min(T[o << 1].v1[i], T[o << 1 | 1].v1[i]);
    T[o].v2[i] = min(min(T[o << 1].v2[i], T[o << 1 | 1].v2[i]), max(T[o << 1].v1[i], T[o << 1 | 1].v1[i]));
  }
}

void build(int o, int l, int r) {
  T[o].l = l, T[o].r = r;
  REP(i, 10) T[o].v1[i] = T[o].v2[i] = inf;
  if (l == r) {
    for (int i = a[l], j = 0; i; i /= 10, j++) if (i % 10) T[o].v1[j] = a[l];
  } else {
    int mi = l + r >> 1;
    build(o << 1, l, mi);
    build(o << 1 | 1, mi + 1, r);
    push_up(o);
  }
}

void update(int o, int x, int d) {
  if (T[o].l == T[o].r) {
    REP(i, 10) T[o].v1[i] = T[o].v2[i] = inf;
    for (int i = d, j = 0; i; i /= 10, j++) if (i % 10) T[o].v1[j] = d;
    return;
  }
  int mi = T[o].l + T[o].r >> 1;
  if (x <= mi) update(o << 1, x, d);
  else update(o << 1 | 1, x, d);
  push_up(o);
}

pii query(int o, int l, int r, int d) {
  if (l <= T[o].l && T[o].r <= r) return {T[o].v1[d], T[o].v2[d]};
  int mi = T[o].l + T[o].r >> 1;
  pii x = {-1, -1}, y = {-1, -1};
  if (l <= mi) x = query(o << 1, l, r, d);
  if (r > mi) y = query(o << 1 | 1, l, r, d);
  if (x._1 == -1) return y;
  if (y._1 == -1) return x;
  return {min(x._1, y._1), min(min(x._2, y._2), max(x._1, y._1))};
}


int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, n) scanf("%d", a + i);
  build(1, 1, n);
  while (m--) {
    int op, x, y;
    scanf("%d%d%d", &op, &x, &y);
    if (op == 1) update(1, x, y);
    else {
      int ans = inf;
      REP(i, 10) {
        auto now = query(1, x, y, i);
        if (now._1 < inf && now._2 < inf) chkmin(ans, now._1 + now._2);
      }
      if (ans == inf) ans = -1;
      printf("%d\n", ans);
    }
  }
}