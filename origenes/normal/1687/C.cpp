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

int n, m;
vector<int> G[maxn];
ll a[maxn], b[maxn];

void solve() {
  cin >> n >> m;
  FOR(i, 1, n) cin >> a[i];
  FOR(i, 1, n) {
    cin >> b[i];
    a[i] = a[i] - b[i] + a[i - 1];
  }
  set<int> s;
  REP(i, n + 1) {
    s.emplace(i);
    G[i].clear();
  }
  vector<pii> edges(m);
  vector<int> deg(m, 2);
  REP(i, m) {
    auto &[l, r] = edges[i];
    cin >> l >> r;
    G[l - 1].eb(i);
    G[r].eb(i);
  }
  queue<int> q;
  REP(i, n + 1) if (!a[i]) {
    q.emplace(i);
    s.erase(i);
  }
  while (!q.empty()) {
    auto u = q.front(); q.pop();
    for (auto i : G[u]) if (!--deg[i]) {
      auto [l, r] = edges[i];
      auto it1 = s.lower_bound(l), it2 = s.lower_bound(r);
      for (auto it = it1; it != it2; ++it) q.emplace(*it);
      s.erase(it1, it2);
    }
  }
  if (s.empty()) cout << "YES\n";
  else cout << "NO\n";
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}