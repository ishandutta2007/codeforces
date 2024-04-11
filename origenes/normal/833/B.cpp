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

const int maxn = 35123;
const int maxk = 55;

struct Seg {
  int l, r, ans, lazy;
} T[maxk][maxn << 2];

int a[maxn], pre[maxn], lis[maxn];

void build(int id, int o, int l, int r) {
  T[id][o].l = l;
  T[id][o].r = r;
  if (l != r) {
    int m = l + r >> 1;
    build(id, o << 1, l, m);
    build(id, o << 1 | 1, m + 1, r);
  }
}

inline void push_down(int id, int o) {
  T[id][o << 1].lazy += T[id][o].lazy;
  T[id][o << 1 | 1].lazy += T[id][o].lazy;
  T[id][o].lazy = 0;
}

inline void push_up(int id, int o) {
  T[id][o].ans = max(T[id][o << 1].ans + T[id][o << 1].lazy, T[id][o << 1 | 1].ans + T[id][o << 1 | 1].lazy);
}

void add(int id, int o, int l, int r, int v) {
  if (l <= T[id][o].l && T[id][o].r <= r) {
    T[id][o].lazy += v;
    return;
  }
  int m = T[id][o].l + T[id][o].r >> 1;
  push_down(id, o);
  if (l <= m) add(id, o << 1, l, r, v);
  if (r > m) add(id, o << 1 | 1, l, r, v);
  push_up(id, o);

}

int query(int id, int o, int l, int r) {
  if (l <= T[id][o].l && T[id][o].r <= r) return T[id][o].ans + T[id][o].lazy;
  int m = T[id][o].l + T[id][o].r >> 1, ret = 0;
  push_down(id, o);
  if (l <= m) chkmax(ret, query(id, o << 1, l, r));
  if (r > m) chkmax(ret, query(id, o << 1 | 1, l, r));
  push_up(id, o);
  return ret;
}

int n, k;

int main() {
  scanf("%d%d", &n, &k);
  REP(i, k) build(i, 1, 0, (1 << 16) - 1);
  FOR(i, 1, n) {
    scanf("%d", a + i);
    pre[i] = lis[a[i]];
    lis[a[i]] = i;
  }
  FOR(i, 1, n) {
    add(0, 1, pre[i], i - 1, 1);
    FOR(j, 1, k - 1) {
      add(j, 1, pre[i], i - 1, 1);
      add(j, 1, i, i, query(j - 1, 1, 0, i - 1));
    }
  }
  printf("%d", query(k - 1, 1, 0, n));
}