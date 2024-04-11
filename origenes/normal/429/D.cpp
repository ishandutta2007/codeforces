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

int n;
pair<ll, ll> p[maxn];

ll f(int l, int r) {
  return sqr(p[l]._1 - p[r]._1) + sqr(p[l]._2 - p[r]._2);
}

ll solve(int l, int r) {
  if (l >= r) return 1e18;
  if (l + 1 == r) return f(l, r);
  int mi = l + r >> 1;
  ll ret = min(solve(l, mi), solve(mi + 1, r));
  vector<int> id;
  FOR(i, l, r) if (sqr(p[i]._1 - p[mi]._1) <= ret) id.eb(i);
  sort(all(id), [](int i, int j) { return p[i]._2 < p[j]._2; });
  int m = id.size();
  REP(i, m) FOR(j, i + 1, m - 1) {
    if (sqr(p[id[j]]._2 - p[id[i]]._2) >= ret) break;
    chkmin(ret, f(id[i], id[j]));
  }
  return ret;
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  ll s = 0;
  FOR(i, 1, n) {
    int a; cin >> a;
    p[i] = {i, s += a};
  }
  cout << solve(1, n);
}