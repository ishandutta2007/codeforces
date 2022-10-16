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

int q, n;

int main() {
  scanf("%d", &q);
  while (q--) {
    scanf("%d", &n);
    vector<int> a(n + 1), b(n + 1);
    vector<vector<ll>> f(n + 1, vector<ll>(3, 1e18 + 5));
    FOR(i, 1, n) scanf("%d%d", &a[i], &b[i]);
    f[1][0] = 0, f[1][1] = b[1], f[1][2] = b[1] + b[1];
    FOR(i, 2, n) REP(j, 3) REP(k, 3) if (a[i - 1] + j != a[i] + k) chkmin(f[i][k], f[i - 1][j] + k * ll(b[i]));
    printf("%lld\n", *min_element(all(f[n])));
  }
}