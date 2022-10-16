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

vector<int> G[maxn], ids[maxn];

void solve() {
  int n; cin >> n;
  FOR(i, 1, n) {
    G[i].clear();
    ids[i].clear();
  }
  vector<int> a(n + 1), b(n + 1);
  FOR(i, 1, n) {
    cin >> a[i];
    ids[a[i]].eb(i);
  }
  vector<int> deg(n + 1), id(n);
  iota(all(id), 1);
  sort(all(id), [](int x, int y) { return size(ids[x]) > size(ids[y]); });
  FOR(i, 1, n) {
    cin >> b[i];
    if (b[i] != id[0]) {
      G[a[i]].eb(b[i]);
      deg[b[i]]++;
    }
  }
  queue<int> q;
  FOR(i, 1, n) if (deg[i] == 0) q.emplace(i);
  int cnt = 0;
  while (!q.empty()) {
    cnt++;
    auto u = q.front(); q.pop();
    for (auto v : G[u]) if (!--deg[v]) q.emplace(v);
  }
  if (cnt == n) cout << "AC\n";
  else cout << "WA\n";
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}