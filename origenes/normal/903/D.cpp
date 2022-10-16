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

map<int, int> cnt;

int main() {
  int n, a;
  ll tot = 0;
  long double ans = 0;
  scanf("%d", &n);
  FOR(i, 1, n) {
    scanf("%d", &a);
    ll cur = 0;
    int now = 0;
    FOR(j, a - 1, a + 1) if (cnt.count(j)) {
        now += cnt[j];
        cur += cnt[j] * ll(j);
      }
    ans += ll(a) * (i - 1 - now) - tot + cur;
    tot += a;
    cnt[a]++;
  }
  printf("%.0Lf", ans);
}