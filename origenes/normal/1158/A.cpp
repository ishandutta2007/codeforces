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

int b[maxn], g[maxn];
int n, m;

int main() {
  scanf("%d%d", &n, &m);
  ll s1 = 0, s2 = 0;
  int mmax = 0;
  FOR(i, 1, n) {
    scanf("%d", b + i);
    chkmax(mmax, b[i]);
    s1 += b[i];
  }
  bool flag = false;
  FOR(i, 1, m) {
    scanf("%d", g + i);
    if (g[i] < mmax) {
      puts("-1");
      return 0;
    }
    if (g[i] == mmax) flag = true;
    s2 += g[i];
  }
  if (flag) printf("%lld", (s1 - mmax) * m + s2);
  else {
    sort(b + 1, b + n + 1);
    printf("%lld", (s1 - mmax) * m + s2 + b[n] - b[n - 1]);
  }
}