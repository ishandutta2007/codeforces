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

int n;
int x[maxn], y[maxn];

bool check(int u) {
  int xmx = -1, xmn = 55, ymx = -1, ymn = 55;
  FOR(i, 1, n) if (i != u) {
    chkmax(xmx, x[i]);
    chkmin(xmn, x[i]);
    chkmax(ymx, y[i]);
    chkmin(ymn, y[i]);
  }
  if (xmx - xmn != ymx - ymn) return false;
  FOR(i, 1, n) if (i != u && x[i] != xmn && x[i] != xmx && y[i] != ymn && y[i] != ymx) return false;
  return true;
}

int main() {
  scanf("%d", &n);
  n = 4 * n + 1;
  FOR(i, 1, n) scanf("%d%d", x + i, y + i);
  FOR(i, 1, n) if (check(i)) {
    printf("%d %d", x[i], y[i]);
    return 0;
  }
}