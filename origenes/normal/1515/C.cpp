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
  int m, n, x;
  cin >> n >> m >> x;
  vector<pii> h(n);
  REP(i, n) {
    cin >> h[i]._1;
    h[i]._2 = i;
  }
  sort(all(h), greater<>());
  set<pii> q;
  vector<int> ans(n), have(m);
  REP(i, m) q.emplace(0, i);
  REP(i, n) {
    auto [w, id] = h[i];
    auto j = q.begin()->_2;
    q.erase(q.begin());
    ans[id] = j + 1;
    have[j] += w;
    q.emplace(have[j], j);
  }
  cout << "YES\n";
  for (auto y : ans) cout << y << ' ';
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