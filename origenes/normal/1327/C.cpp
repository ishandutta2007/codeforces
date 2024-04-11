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

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  printf("%d\n", n * m + n + m - 3);
  REP(i, n - 1) putchar('U');
  REP(i, m - 1) putchar('L');
  REP(i, n) {
    if (i) putchar('D');
    if (i & 1) REP(j, m - 1) putchar('L');
    else REP(j, m - 1) putchar('R');
  }
}