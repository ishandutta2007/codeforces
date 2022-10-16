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

ll a[maxn];
int n;

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%lld", a + i);
  FOR(i, 1, n) a[i] = a[i - 1] + a[i];
  map<ll, int> last;
  last[0] = 1;
  ll ans = 0;
  int nowr = 0;
  FOR(i, 1, n) {
    chkmax(nowr, last[a[i]]);
    ans += i - nowr;
    last[a[i]] = i + 1;
  }
  printf("%lld", ans);
}