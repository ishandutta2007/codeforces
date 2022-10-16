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

const int maxn = 5123;
const int LIM = 1e9;

int n, m;
int a[maxn], inc[maxn], op[maxn], l[maxn], r[maxn], d[maxn];

int main() {
  scanf("%d%d", &n, &m);
  fill(a + 1, a + n + 1, LIM);
  FOR(i, 1, m) {
    scanf("%d%d%d%d", op + i, l + i, r + i, d + i);
    if (op[i] == 1) FOR(j, l[i], r[i]) inc[j] += d[i];
    else FOR(j, l[i], r[i]) chkmin(a[j], d[i] - inc[j]);
  }
  memcpy(inc + 1, a + 1, n * sizeof(int));
  bool ok = true;
  FOR(i, 1, m) {
    if (op[i] == 1) FOR(j, l[i], r[i]) inc[j] += d[i];
    else {
      int mx = -1e9;
      FOR(j, l[i], r[i]) chkmax(mx, inc[j]);
      if (mx != d[i]) {
        ok = false;
        break;
      }
    }
  }
  if (ok) {
    puts("YES");
    FOR(i, 1, n) printf("%d ", a[i]);
  } else puts("NO");
}