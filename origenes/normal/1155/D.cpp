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

const int maxn = 312345;

int n, x;
ll a[maxn], L[maxn], R[maxn], ans, cur;

int main() {
  scanf("%d%d", &n, &x);
  FOR(i, 1, n) scanf("%lld", a + i);
  FOR(i, 1, n) a[i] = a[i] + a[i - 1];
  ll mmin = 0, mmax = a[n];
  FOR(i, 1, n) {
    chkmin(mmin, a[i]);
    L[i] = max(a[i] - mmin, 0LL);
  }
  ROF(i, n, 1) {
    chkmax(mmax, a[i]);
    R[i] = max(mmax - a[i - 1], 0LL);
  }
  FOR(i, 1, n) {
    chkmax(ans, x * a[i] + R[i + 1] + cur);
    chkmax(ans, L[i]);
    chkmax(cur, L[i] - x * a[i]);
  }
  printf("%lld", ans);
}