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

const int maxn = 112;

int n, m, s[maxn];
char op[20][5];
int p[20], f[1 << 20];

int main() {
  scanf("%d", &n);
  REP(i, n) scanf("%d", s + i);
  sort(s, s + n, greater<>());
  scanf("%d", &m);
  REP(i, m) scanf("%s%d", op[i], p + i);
  ROF(mask, (1 << m) - 2, 0) {
    int turn = __builtin_popcount(mask);
    f[mask] = p[turn] == 1 ? -1e9 : 1e9;
    REP(i, m) if (!(mask & (1 << i))) {
      if (p[turn] == 1) {
        if (op[turn][0] == 'p') chkmax(f[mask], f[mask | (1 << i)] + s[i]);
        else chkmax(f[mask], f[mask | (1 << i)]);
      } else {
        if (op[turn][0] == 'p') chkmin(f[mask], f[mask | (1 << i)] - s[i]);
        else chkmin(f[mask], f[mask | (1 << i)]);
      }
    }
  }
  printf("%d", f[0]);
}