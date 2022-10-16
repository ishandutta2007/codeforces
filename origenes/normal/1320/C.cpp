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

struct Seg {
  int l, r, v, lzy;
} T[maxn << 2];

int n, m, p;
pii weapons[maxn], armors[maxn];
tuple<int, int, int> monsters[maxn];
vector<pii> events[maxn * 5];

void push_up(int o) {
  T[o].v = max(T[o << 1].v, T[o << 1 | 1].v);
}

void build(int o, int l, int r) {
  T[o].l = l, T[o].r = r;
  if (l < r) {
    int mi = l + r >> 1;
    build(o << 1, l, mi);
    build(o << 1 | 1, mi + 1, r);
    push_up(o);
  } else {
    T[o].v = -weapons[l]._2;
  }
}

void push_down(int o) {
  T[o << 1].lzy += T[o].lzy;
  T[o << 1].v += T[o].lzy;
  T[o << 1 | 1].lzy += T[o].lzy;
  T[o << 1 | 1].v += T[o].lzy;
  T[o].lzy = 0;
}

void add(int o, int l, int r, int x) {
  if (l <= T[o].l && T[o].r <= r) {
    T[o].v += x;
    T[o].lzy += x;
    return;
  }
  int mi = T[o].l + T[o].r >> 1;
  push_down(o);
  if (l <= mi) add(o << 1, l, r, x);
  if (r > mi) add(o << 1 | 1, l, r, x);
  push_up(o);
}

int main() {
  scanf("%d%d%d", &n, &m, &p);
  FOR(i, 1, n) {
    int a, ca; scanf("%d%d", &a, &ca);
    weapons[i] = {a, ca};
  }
  FOR(i, 1, m) {
    int b, cb;
    scanf("%d%d", &b, &cb);
    armors[i] = {b, cb};
  }
  FOR(i, 1, p) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    monsters[i] = {x, y, z};
  }
  sort(weapons + 1, weapons + n + 1);
  int j = 0;
  FOR(i, 1, n) if (weapons[i]._1 != weapons[i - 1]._1) weapons[++j] = weapons[i];
  n = j;
  sort(armors + 1, armors + m + 1);
  j = 0;
  FOR(i, 1, m) if (armors[i]._1 != armors[i - 1]._1) armors[++j] = armors[i];
  m = j;
  FOR(i, 1, p) events[get<1>(monsters[i])].eb(get<0>(monsters[i]), get<2>(monsters[i]));
  FOR(i, 1, 1e6) if (!events[i].empty()) sort(all(events[i]));
  build(1, 1, n);
  j = 0;
  int ans = -2e9 - 10;
  FOR(i, 1, m) {
    int b = armors[i]._1, cb = armors[i]._2;
    while (j < b) {
      for (auto [x, z] : events[j]) {
        if (x >= weapons[n]._1) break;
        int pos = lower_bound(weapons + 1, weapons + n + 1, mp(x + 1, -1)) - weapons;
        add(1, pos, n, z);
      }
      j++;
    }
    int now = T[1].v - cb;
    chkmax(ans, now);
  }
  printf("%d", ans);
}