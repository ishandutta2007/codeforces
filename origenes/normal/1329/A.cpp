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

int n, m;
int l[maxn], p[maxn];
ll s[maxn];

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, m) scanf("%d", l + i);
  ll mx = 0, mn = 0;
  FOR(i, 1, m) mx += l[i];
  ROF(i, m, 1) chkmax(mn, l[i] + ll(i) - 1);
  if (n < mn || n > mx) {
    puts("-1");
    return 0;
  }
  ROF(i, m, 1) {
    s[i] = s[i + 1] + l[i];
    p[i] = max(ll(i), n - s[i] + 1);
  }
  FOR(i, 1, m) printf("%d ", p[i]);
}