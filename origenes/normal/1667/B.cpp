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
  int n; cin >> n;
  vector<int> a(n + 1);
  FOR(i, 1, n) cin >> a[i];
  vector<ll> pre(n + 1);
  vector<pair<ll, int>> seq; seq.reserve(n);
  FOR(i, 1, n) {
    pre[i] = pre[i - 1] + a[i];
    seq.eb(pre[i], i);
  }
  sort(all(seq), [](auto x, auto y) { return x._1 == y._1 ? x._2 > y._2 : x._1 < y._1; });
  vector<int> pos(n + 1);
  REP(i, n) pos[seq[i]._2] = i + 1;
  vector<ll> fen(n + 1, -1e18), f(n + 1);
  auto add = [&](int p, ll x) {
    while (p <= n) {
      chkmax(fen[p], x);
      p += p & -p;
    }
  };
  auto query = [&](int p) {
    ll ret = -1e18;
    while (p > 0) {
      chkmax(ret, fen[p]);
      p -= p & -p;
    }
    return ret;
  };
  FOR(i, 1, n) {
    f[i] = f[i - 1];
    if (a[i] > 0) f[i]++;
    else if (a[i] < 0) f[i]--;
    if (pre[i] > 0) f[i] = i;
    else chkmax(f[i], query(pos[i]) + i);
    add(pos[i], f[i] - i);
  }
  cout << f[n] << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}