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

const int maxn = 2123;

double a[maxn * 2];
int n;

int main() {
  scanf("%d", &n);
  FOR(i, 1, 2 * n) scanf("%lf", a + i);
  int zero = 0;
  double tot = 0, ans = 1e18;
  FOR(i, 1, 2 * n) {
    a[i] -= floor(a[i]);
    if (abs(a[i]) < 1e-9) zero++;
    tot += a[i];
  }
  FOR(i, max(zero - n, 0), min(zero, n)) chkmin(ans, abs(tot - n + i));
  printf("%.3lf", ans);
}