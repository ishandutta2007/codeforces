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

inline int lowbit(int x) {
  return x & -x;
}

int n, m, fen[maxn], last[maxn], a[maxn];
int mx[maxn], mn[maxn], fi[maxn];

void add(int x, int d) {
  while (x < maxn) {
    fen[x] += d;
    x += lowbit(x);
  }
}

int query(int x) {
  int ret = 0;
  while (x) {
    ret += fen[x];
    x -= lowbit(x);
  }
  return ret;
}

int query(int l, int r) {
  if (l > r) return 0;
  return query(r) - query(l - 1);
}

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, m) scanf("%d", a + i);
  FOR(i, 1, n) mx[i] = mn[i] = i;
  FOR(i, 1, m) mn[a[i]] = 1;
  FOR(i, 1, n) fi[i] = m + 1;
  ROF(i, m, 1) fi[a[i]] = i;
  ROF(i, n, 1) {
    mx[i] += query(fi[i]);
    if (fi[i] <= m) add(fi[i], 1);
  }
  reset(fen, 0);
  FOR(i, 1, m) {
    if (last[a[i]]) {
      chkmax(mx[a[i]], query(last[a[i]] + 1, i) + 1);
      add(last[a[i]], -1);
    }
    add(i, 1);
    last[a[i]] = i;
  }
  FOR(i, 1, n) chkmax(mx[i], query(last[i] + 1, m) + 1);
  FOR(i, 1, n) printf("%d %d\n", mn[i], mx[i]);
}