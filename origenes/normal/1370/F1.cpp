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

const int maxn = 1123;

int n, dep[maxn], mx;
vector<int> G[maxn], q;

void bfs(int s) {
  reset(dep, -1);
  dep[s] = 0;
  queue<int> que; que.emplace(s);
  while (!que.empty()) {
    auto u = que.front(); que.pop();
    for (auto v : G[u]) if (dep[v] == -1) {
      dep[v] = dep[u] + 1;
      que.emplace(v);
    }
  }
  mx = *max_element(dep + 1, dep + n + 1);
}

pii query() {
  cout << "? " << q.size();
  for (auto u : q) cout << ' ' << u;
  cout << endl;
  int x, d;
  cin >> x >> d;
  return {x, d};
}

void answer(int u, int v) {
  cout << "! " << u << ' ' << v << endl;
  string s;
  cin >> s;
  assert(s == "Correct");
}

void solve() {
  cin >> n;
  FOR(i, 1, n) G[i].clear();
  REP(i, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].eb(v); G[v].eb(u);
  }
  q.clear();
  FOR(i, 1, n) q.eb(i);
  auto [r, d] = query();
  bfs(r);
  int lo = (d + 1) / 2, hi = min(mx, d), u = r, e;
  while (lo <= hi) {
    int mi = lo + hi >> 1;
    q.clear();
    FOR(i, 1, n) if (dep[i] == mi) q.eb(i);
    int v;
    if (q.empty()) e = 1e5;
    else tie(v, e) = query();
    if (e > d) hi = mi - 1;
    else lo = mi + 1, u = v;
  }
  q.clear();
  bfs(u);
  FOR(i, 1, n) if (dep[i] == d) q.eb(i);
  int v = query()._1;
  answer(u, v);
}

int main() {
  int T; cin >> T;
  while (T--) solve();
}