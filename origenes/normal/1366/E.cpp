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

const int maxn = 212345;
const int MOD = 998244353;

int n, m;
int a[maxn], b[maxn];

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, n) scanf("%d", a + i);
  FOR(i, 1, m) scanf("%d", b + i);
  map<int, int> last;
  FOR(i, 1, n) last[a[i]] = i;
  int ans = 1;
  FOR(i, 1, m) {
    if (last.count(b[i]) == 0 || (i > 1 && last[b[i]] < last[b[i - 1]])) {
      puts("0");
      return 0;
    }
    if (i == 1) {
      FOR(j, 1, last[b[1]]) if (a[j] < b[1]) {
        puts("0");
        return 0;
      }
    }
    else {
      int j = last[b[i]];
      while (j > last[b[i - 1]] && a[j] >= b[i]) j--;
      FOR(k, last[b[i - 1]], j) if (a[k] < b[i - 1]) {
        puts("0");
        return 0;
      }
      ans = ans * ll(last[b[i]] - j) % MOD;
    }
    if (i == m) FOR(j, last[b[m]] + 1, n) if (a[j] < b[m]) {
      puts("0");
      return 0;
    }
  }
  printf("%d", ans);
}