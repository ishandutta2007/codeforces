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
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  int n; cin >> n;
  vector<int> a(n);
  vector<vector<int>> from(n);
  REP(i, n) {
    cin >> a[i];
    a[i]--;
    from[a[i]].eb(i);
  }
  while (true) {
    int ans = 0;
    vector<int> out(n), in(n), b(n);
    REP(i, n) if (!from[i].empty()) {
      uniform_int_distribution<> distrib(0, from[i].size() - 1);
      int pre = from[i][distrib(rng)];
      out[pre]++;
      in[i]++;
      b[pre] = i;
      ans++;
    }
    vector<int> heads, tails;
    REP(i, n) if (!out[i]) heads.eb(i);
    REP(i, n) if (!in[i]) tails.eb(i);
    shuffle(all(tails), rng);
    bool ok = true;
    REP(i, int(heads.size())) {
      b[heads[i]] = tails[i];
      if (heads[i] == tails[i]) {
        ok = false;
        break;
      }
    }
    if (ok) {
      cout << ans << '\n';
      REP(i, n) cout << b[i] + 1 << ' ';
      cout << '\n';
      return;
    }
  }
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}