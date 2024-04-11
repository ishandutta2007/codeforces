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
const int maxb = 710;

int q, a[maxn];
int s[maxb][maxb];

int main() {
  scanf("%d", &q);
  while (q--) {
    int t, x, y;
    scanf("%d%d%d", &t, &x, &y);
    if (t == 1) {
      a[x] += y;
      FOR(i, 1, maxb - 1) s[i][x % i] += y;
    } else {
      int ans = 0;
      if (x >= maxb) {
        for (int i = y; i <= 500000; i += x) ans += a[i];
      } else {
        ans = s[x][y];
      }
      printf("%d\n", ans);
    }
  }
}