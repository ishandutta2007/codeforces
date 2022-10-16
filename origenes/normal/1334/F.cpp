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

const int maxn = 512345;

int a[maxn], b[maxn], pos[maxn], best[maxn];
ll p[maxn], f[maxn], fen[maxn], suf[2][maxn];
int n, m;

inline int lowbit(int x) {
  return x & -x;
}

void add(int x, ll d) {
  while (x <= n + 1) {
    fen[x] += d;
    x += lowbit(x);
  }
}

ll query(int x) {
  ll ret = 0;
  while (x > 0) {
    ret += fen[x];
    x -= lowbit(x);
  }
  return ret;
}

ll query(int l, int r) {
  if (l > r) return 0;
  return query(r) - query(l - 1);
}

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", a + i);
  FOR(i, 1, n) scanf("%lld", p + i);
  scanf("%d", &m);
  FOR(i, 1, m) scanf("%d", b + i);
  FOR(i, 1, m) pos[b[i]] = i;
  b[m + 1] = b[m] + 1;
  ROF(i, n, 1) {
    if (pos[a[i]]) {
      suf[0][i] = query(b[pos[a[i]]] + 1, n + 1);
      suf[1][i] = query(b[pos[a[i]] - 1] + 1, n + 1);
    }
    if (p[i] >= 0) add(a[i], p[i]);
    else add(n + 1, p[i]);
  }
  suf[0][0] = query(n + 1);
  FOR(i, 1, n) if (pos[a[i]]) {
    if (a[i] == b[1]) {
      f[i] = suf[0][0] - suf[1][i] + suf[0][i] - p[i];
      if (best[a[i]] == 0 || f[i] < f[best[a[i]]]) best[a[i]] = i;
    } else {
      int j = best[b[pos[a[i]] - 1]];
      if (j) {
        f[i] = f[j] - suf[1][i] + suf[0][i] - p[i];
        if (best[a[i]] == 0 || f[i] < f[best[a[i]]]) best[a[i]] = i;
      }
    }
  }
  if (best[b[m]] == 0) puts("NO");
  else {
    puts("YES");
    printf("%lld", f[best[b[m]]]);
  }
}