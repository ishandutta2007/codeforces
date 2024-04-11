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
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 112345;

int a[maxn], n, m;
ll tot, s;

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, n) {
    scanf("%d", a + i);
    s += a[i];
  }
  sort(a + 1, a + n + 1);
  ROF(i, n - 1, 0) {
    if (a[i] >= a[i + 1]) {
      tot++;
      a[i] = a[i + 1] - 1;
    } else {
      tot += a[i + 1] - a[i];
    }
    if (a[i] < 1) a[i] = 1;
  }
  printf("%lld", s - tot);
}