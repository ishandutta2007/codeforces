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

map<pair<ll, ll>, ll> f;

ll dfs(ll n, ll m, ll step) {
  if (f.count(mp(n, m))) return f[mp(n, m)];
  if (n == 0) return 0;
  if (n + m <= step) return f[mp(n, m)] = dfs(n, m, step >> 1);
  if (n >= step) return f[mp(n, m)] = m - dfs(n - step, m, step);
  ll x = step - n, y = n + m - step;
  return f[mp(n, m)] = dfs(n, x, step) + y - dfs(x, y, step);
}

void solve() {
  ll n, m;
  cin >> n >> m;
  cout << dfs(n, m, 1LL << 61) << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}