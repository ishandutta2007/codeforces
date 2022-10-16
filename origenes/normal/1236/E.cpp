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
int a[maxn], l[maxn], r[maxn];

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, m) scanf("%d", a + i);
  if (n == 1) {
    puts("0");
    return 0;
  }
  map<int, int> L, R;
  auto go_l = [&](int x, int i) {
    return L[x + i] ? l[L[x + i]] : max(x - (m - i) - 1, 1);
  };
  auto go_r = [&](int x, int i) {
    return R[x - i] ? r[R[x - i]] : min(x + (m - i) + 1, n);
  };
  ROF(i, m, 1) {
    l[i] = go_l(a[i] + 1, i), r[i] = go_r(a[i] - 1, i);
    L[a[i] + i] = i, R[a[i] - i] = i;
  }
  ll ans = 0;
  FOR(i, 1, n) ans += go_r(i, 0) + 1 - go_l(i, 0);
  printf("%lld", ans);
}