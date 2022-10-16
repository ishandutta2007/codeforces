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

void get_z(int *z, const char *s, int n) {
  z[0] = n;
  int l = -1, r = -1;
  FOR(i, 1, n - 1) {
    if (i <= r) z[i] = min(z[i - l], r - i + 1);
    while (i + z[i] < n && s[i + z[i]] == s[z[i]]) z[i]++;
    if (i + z[i] - 1 > r) {
      r = i + z[i] - 1;
      l = i;
    }
  }
}

int n, m;
char a[maxn], b[maxn], s[maxn * 3];
int za[maxn * 3], zb[maxn * 3], ma[maxn], mb[maxn], ida[maxn], idb[maxn];

inline int lowbit(int x) {
  return x & -x;
}

struct FenwickTree {
  int fen[maxn];

  void add(int x, int v) {
    while (x <= n) {
      fen[x] += v;
      x += lowbit(x);
    }
  }

  int query(int x) {
    int ret = 0;
    while (x > 0) {
      ret += fen[x];
      x -= lowbit(x);
    }
    return ret;
  }

  int query(int l, int r) {
    chkmin(r, n);
    if (l <= 1) return query(r);
    return query(r) - query(l - 1);
  }
} fa, fb;

int main() {
  scanf("%d%d", &n, &m);
  scanf("%s%s%s", a, b, s);
  s[m] = '#';
  memcpy(s + m + 1, a, n * sizeof(char));
  get_z(za, s, n + m + 1);
  FOR(i, m + 1, n + m) ma[i - m] = za[i];
  reverse(s, s + m);
  memcpy(s + m + 1, b, n * sizeof(char));
  reverse(s + m + 1, s + n + m + 1);
  get_z(zb, s, n + m + 1);
  FOR(i, m + 1, n + m) mb[i - m] = zb[i];
  reverse(mb + 1, mb + n + 1);
  iota(ida + 1, ida + n + 1, 1); iota(idb + 1, idb + n + 1, 1);
  sort(ida + 1, ida + n + 1, [](int x, int y) { return ma[x] < ma[y]; });
  sort(idb + 1, idb + n + 1, [](int x, int y) { return mb[x] < mb[y]; });
  ll ans = 0, now = 0;
  FOR(i, 1, n) fa.add(i, 1);
  for (int l = 1, r = m - 1, i = 1, j = n; l < m; l++, r--) {
    while (i <= n && ma[ida[i]] < l) {
      now -= fb.query(ida[i], ida[i] + m - 2);
      fa.add(ida[i], -1);
      i++;
    }
    while (j && mb[idb[j]] >= r) {
      now += fa.query(idb[j] - m + 2, idb[j]);
      fb.add(idb[j], 1);
      j--;
    }
    ans += now;
  }
  printf("%lld", ans);
}