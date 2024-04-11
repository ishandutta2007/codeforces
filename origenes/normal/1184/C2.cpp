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

const int OFF = 1e6 + 5;
const int maxn = 4123456;

struct Seg {
  int val, lzy;
} T[maxn << 2];

inline void push_down(int o) {
  T[o << 1].lzy += T[o].lzy; T[o << 1].val += T[o].lzy;
  T[o << 1 | 1].lzy += T[o].lzy; T[o << 1 | 1].val += T[o].lzy;
  T[o].lzy = 0;
}

inline void push_up(int o) {
  T[o].val = max(T[o << 1].val, T[o << 1 | 1].val);
}

void add(int o, int lo, int ro, int l, int r, int v) {
  if (l <= lo && ro <= r) {
    T[o].val += v;
    T[o].lzy += v;
    return;
  }
  push_down(o);
  int mi = lo + ro >> 1;
  if (l <= mi) add(o << 1, lo, mi, l, r, v);
  if (r > mi) add(o << 1 | 1, mi + 1, ro, l, r, v);
  push_up(o);
}

int query(int o, int lo, int ro, int l, int r) {
  if (l <= lo && ro <= r) return T[o].val;
  push_down(o);
  int mi = lo + ro >> 1, ret = 0;
  if (l <= mi) chkmax(ret, query(o << 1, lo, mi, l, r));
  if (r > mi) chkmax(ret, query(o << 1 | 1, mi + 1, ro, l, r));
  push_up(o);
  return ret;
}

int n, r;
vector<int> loc[maxn];

int main() {
  scanf("%d%d", &n, &r);
  r *= 2;
  FOR(i, 1, n) {
    int u, v, x, y;
    scanf("%d%d", &u, &v);
    x = u + v + 2 * OFF;
    y = u - v + 2 * OFF;
    loc[x].eb(y);
  }
  int ans = 0;
  FOR(i, 1, maxn - 1000) {
    if (i > r) for (auto y : loc[i - r - 1]) add(1, 1, maxn - 1000, max(1, y - r), y, -1);
    for (auto y : loc[i]) add(1, 1, maxn - 1000, max(1, y - r), y, 1);
    if (!loc[i].empty()) chkmax(ans, query(1, 1, maxn - 1000, 1, maxn - 1000));
  }
  printf("%d", ans);
}