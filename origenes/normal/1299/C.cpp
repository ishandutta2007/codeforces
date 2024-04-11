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

const int maxn = 1123456;

int n, a[maxn], best[maxn];
ll suf[maxn];

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", a + i);
  ROF(i, n, 1) suf[i] = suf[i + 1] + a[i];
  best[n] = n;
  best[n + 1] = n + 1;
  ROF(i, n - 1, 1) {
    best[i] = i;
    int j = best[i + 1];
    while (j <= n && (suf[i] - suf[best[i] + 1]) * (j + 1 - i) > (suf[i] - suf[j + 1]) * (best[i] + 1 - i)) {
      best[i] = j;
      j = best[j + 1];
    }
  }
  int done = 0;
  FOR(i, 1, n) if (i > done) {
    double now = double(suf[i] - suf[best[i] + 1]) / (best[i] + 1 - i);
    FOR(j, done + 1, best[i]) printf("%.15lf\n", now);
    done = best[i];
  }
}