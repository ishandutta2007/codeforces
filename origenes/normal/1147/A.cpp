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

int n, k, ans;
int x[maxn], fi[maxn], se[maxn];

int main() {
  scanf("%d%d", &n, &k);
  reset(fi, 0x3f);
  FOR(i, 1, k) {
    scanf("%d", x + i);
    chkmin(fi[x[i]], i);
    se[x[i]] = i;
  }
  FOR(i, 1, n) if (!se[i]) ans++;
  if (n > 1) {
    if (fi[1] > se[2]) ans++;
    FOR(i, 2, n - 1) {
      if (fi[i] > se[i + 1]) ans++;
      if (fi[i] > se[i - 1]) ans++;
    }
    if (fi[n] > se[n - 1]) ans++;
  }
  printf("%d", ans);
}