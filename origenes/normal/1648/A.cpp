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

vector<ll> x[maxn], y[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int n, m;
  cin >> n >> m;
  FOR(i, 1, n) FOR(j, 1, m) {
    int c; cin >> c;
    x[c].eb(i);
    y[c].eb(j);
  }
  ll ans = 0;
  FOR(i, 1, 1e5) if (size(x[i]) >= 2) {
    sort(all(x[i])); sort(all(y[i]));
    ll s = 0;
    REP(idx, size(x[i])) {
      ans += idx * x[i][idx] - s;
      s += x[i][idx];
    }
    s = 0;
    REP(idx, size(y[i])) {
      ans += idx * y[i][idx] - s;
      s += y[i][idx];
    }
  }
  cout << ans;
}