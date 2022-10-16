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

void solve() {
  int a, b, c, d;
  scanf("%d%d%d%d", &a, &b, &c, &d);
  int x, y, x1, y1, x2, y2;
  scanf("%d%d%d%d%d%d", &x, &y, &x1, &y1, &x2, &y2);
  if (x + b - a < x1 || x + b - a > x2 || (a == b && b && x1 == x2)) {
    puts("No");
    return;
  }
  puts(y + d - c < y1 || y + d - c > y2 || (d == c && d && y1 == y2) ? "No" : "Yes");
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}