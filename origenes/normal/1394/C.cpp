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

char s[maxn];
int n, ax, ay;
int x[maxn], y[maxn];

bool check(int r) {
  int lx = 0, rx = 1e9, ly = 0, ry = 1e9;
  int ld = -1e9, rd = 1e9;
  FOR(i, 1, n) {
    chkmax(lx, x[i] - r); chkmin(rx, x[i] + r);
    chkmax(ly, y[i] - r); chkmin(ry, y[i] + r);
    chkmax(ld, x[i] - y[i] - r); chkmin(rd, x[i] - y[i] + r);
  }
  FOR(i, lx, rx) {
    int u = max(ly, i - rd), v = min(ry, i - ld);
    if (!i) chkmax(u, 1);
    if (u <= v) {
      ax = i, ay = u;
      return true;
    }
  }
  return false;
}

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) {
    scanf("%s", s);
    int m = strlen(s);
    x[i] = count(s, s + m, 'B');
    y[i] = count(s, s + m, 'N');
  }
  int lo = 0, hi = 1e6;
  while (lo < hi) {
    int mi = lo + hi >> 1;
    if (check(mi)) hi = mi;
    else lo = mi + 1;
  }
  check(lo);
  printf("%d\n", lo);
  REP(i, ax) putchar('B');
  REP(i, ay) putchar('N');
}