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

vector<int> G[maxn];

void solve() {
  int n; cin >> n;
  FOR(i, 1, n) G[i].clear();
  vector<int> deg(n + 1);
  FOR(i, 1, n) {
    int k; cin >> k;
    deg[i] = k;
    while (k--) {
      int a; cin >> a;
      G[a].eb(i);
    }
  }
  set<int> q, nq;
  FOR(i, 1, n) if (!deg[i]) q.emplace(i);
  int ans = 0;
  while (!q.empty() || !nq.empty()) {
    while (!q.empty()) {
      auto u = *q.begin(); q.erase(q.begin());
      for (auto v : G[u]) if (!--deg[v]) {
        if (v > u) q.emplace(v);
        else nq.emplace(v);
      }
    }
    swap(q, nq);
    ans++;
  }
  FOR(i, 1, n) if (deg[i]) {
    cout << "-1\n";
    return;
  }
  cout << ans << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}