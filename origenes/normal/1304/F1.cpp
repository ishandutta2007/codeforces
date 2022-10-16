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

const int maxn = 55;
const int maxm = 21234;

int n, m, k;
int a[maxn][maxm], s[maxn][maxm], f[maxn][maxm];

inline int get(int i, int j) {
  return s[i][j + k - 1] - s[i][j - 1] + s[i + 1][j + k - 1] - s[i + 1][j - 1];
}

struct Seg {
  int l, r;
  int lmx, rmx, v;
} T[maxm << 2];

void build(int row, int o, int l, int r) {
  T[o].l = l, T[o].r = r;
  if (l == r) {
    if (l >= k) T[o].rmx = f[row][l - k + 1] - s[row + 1][l];
    else T[o].rmx = -1e9;
    T[o].lmx = f[row][l] + s[row + 1][l - 1];
    T[o].v = f[row][l];
  } else {
    int mi = l + r >> 1;
    build(row, o << 1, l, mi);
    build(row, o << 1 | 1, mi + 1, r);
    T[o].lmx = max(T[o << 1].lmx, T[o << 1 | 1].lmx);
    T[o].rmx = max(T[o << 1].rmx, T[o << 1 | 1].rmx);
    T[o].v = max(T[o << 1].v, T[o << 1 | 1].v);
  }
}

int query(int o, int l, int r, int op) {
  if (l <= T[o].l && T[o].r <= r) {
    if (op == 0) return T[o].v;
    return op == 1 ? T[o].lmx : T[o].rmx;
  }
  int ret = -1e9, mi = T[o].l + T[o].r >> 1;
  if (l <= mi) chkmax(ret, query(o << 1, l, r, op));
  if (r > mi) chkmax(ret, query(o << 1 | 1, l, r, op));
  return ret;
}

int main() {
  scanf("%d%d%d", &n, &m, &k);
  FOR(i, 1, n) FOR(j, 1, m) {
    scanf("%d", &a[i][j]);
    s[i][j] = s[i][j - 1] + a[i][j];
  }
  FOR(i, 1, n) {
    build(i - 1, 1, 1, m);
    FOR(j, 1, m - k + 1) {
      int v = get(i, j);
      f[i][j] = v;
      if (j > k) chkmax(f[i][j], query(1, 1, j - k, 0) + v);
      if (j + k <= m) chkmax(f[i][j], query(1, j + k, m, 0) + v);
      chkmax(f[i][j], v - s[i][j + k - 1] + query(1, j, j + k - 1, 1));
      chkmax(f[i][j], v + s[i][j - 1] + query(1, j, j + k - 1, 2));
    }
  }
  int ans = 0;
  FOR(i, 1, m) chkmax(ans, f[n][i]);
  printf("%d", ans);
}