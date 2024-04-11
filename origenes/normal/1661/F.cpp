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

int n, a[maxn];
ll m;

ll f(ll x, ll k) {
  return sqr(x / k + 1) * (x % k) + sqr(x / k) * (k - x % k);
}

pair<int, ll> check(ll x) {
  int cnt = 0;
  ll sum = 0;
  REP(i, n) {
    int w = a[i + 1] - a[i];
    int lo = 1, hi = w, cur = 0;
    while (lo < hi) {
      int mi = lo + hi >> 1;
      if (f(w, mi) - f(w, mi + 1) >= x) {
        cur = mi;
        lo = mi + 1;
      } else hi = mi;
    }
    cnt += cur;
    sum += f(w, cur + 1);
  }
  return {cnt, sum};
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  FOR(i, 1, n) cin >> a[i];
  cin >> m;
  ll lo = 1, hi = 1e18, ans;
  while (lo < hi) {
    ll mi = lo + hi >> 1;
    auto [cnt, sum] = check(mi);
    if (sum <= m) {
      ans = cnt - (m - sum) / mi;
      lo = mi + 1;
    } else hi = mi;
  }
  cout << ans;
}