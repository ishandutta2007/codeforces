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

int T, n, h[maxn], k;
ll m;

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%lld%d", &n, &m, &k);
    FOR(i, 1, n) scanf("%d", h + i);
    bool ok = true;
    FOR(i, 1, n - 1) {
      if (h[i] < h[i + 1] - k) {
        int need = h[i + 1] - h[i] - k;
        if (m >= need) {
          m -= need;
          continue;
        }
        ok = false;
        break;
      }
      m += h[i] - max(h[i + 1] - k, 0);
    }
    puts(ok ? "YES" : "NO");
  }
}