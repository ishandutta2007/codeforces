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

const int maxn = 7123;

int n;
ll a[maxn], b[maxn];
bool ok[maxn];

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%lld", a + i);
  FOR(i, 1, n) scanf("%lld", b + i);
  FOR(i, 1, n) {
    int mx = 0;
    FOR(j, 1, n) if (a[i] == a[j]) mx++;
    if (mx >= 2) {
      FOR(j, 1, n) if ((a[j] & a[i]) == a[j]) ok[j] = true;
    }
  }
  ll ans = 0;
  FOR(i, 1, n) if (ok[i]) ans += b[i];
  printf("%lld", ans);
}