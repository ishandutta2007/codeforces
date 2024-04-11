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

const int maxn = 112345;

int n, p;
double a[maxn], b[maxn];

int main() {
  scanf("%d%d", &n, &p);
  double s = 0;
  FOR(i, 1, n) {
    scanf("%lf%lf", a + i, b + i);
    b[i] = b[i] / a[i];
    s += a[i];
  }
  if (s <= p) {
    puts("-1");
    return 0;
  }
  double l = 0, r = 1e15;
  REP(i, 200) {
    double mi = (l + r) / 2;
    double req = 0;
    FOR(j, 1, n) req += max(0.0, mi - b[j]) * a[j];
    if (req > p * mi) r = mi;
    else l = mi;
  }
  printf("%.10lf", l);
}