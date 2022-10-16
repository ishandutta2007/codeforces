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

int fac(int x) {
  int ret = -1;
  for (int i = 2; sqr(i) <= x; i++) if (x % i == 0) {
    while (x % i == 0) x /= i;
    ret = i;
  }
  if (x > 1) ret = x;
  return ret;
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int x2; cin >> x2;
  int st = x2 - fac(x2) + 1, ans = x2;
  FOR(x1, st, x2) {
    int p = fac(x1);
    if (p != x1) chkmin(ans, x1 - p + 1);
  }
  cout << ans;
}