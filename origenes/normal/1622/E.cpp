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

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> x(n);
  REP(i, n) cin >> x[i];
  vector<string> s(n);
  REP(i, n) cin >> s[i];
  ll ans = -1;
  vector<int> p;
  REP(mask, 1 << n) {
    ll tot = 0;
    vector<int> coeff(m);
    REP(i, n) {
      int op = 1;
      if (mask & (1 << i)) op = -1;
      if (op == 1) tot -= x[i];
      else tot += x[i];
      REP(j, m) if (s[i][j] == '1') coeff[j] += op;
    }
    vector<int> id(m);
    iota(all(id), 0);
    sort(all(id), [&](int x, int y) { return coeff[x] < coeff[y]; });
    REP(i, m) tot += coeff[id[i]] * (i + 1);
    if (tot > ans) {
      ans = tot;
      p = id;
    }
  }
  vector<int> res(m);
  REP(i, m) res[p[i]] = i + 1;
  for (auto u : res) cout << u << ' ';
  cout << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}