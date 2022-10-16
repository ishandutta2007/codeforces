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
const int INF = 1e9;

int n1, n2, lmatch[maxn], rmatch[maxn], d[maxn], mx[maxn], my[maxn];
bool vx[maxn], vy[maxn];
vector<pii> G[maxn]; // left to right
vector<pii> edges;

bool bfs() {
  queue<int> q;
  for (int i = 1; i <= n1; ++i) {
    if (lmatch[i] == 0) { d[i] = 0; q.push(i); }
    else d[i] = INF;
  }
  d[0] = INF;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    if (d[u] >= d[0]) continue;
    for (auto [v, id] : G[u]) {
      if (d[rmatch[v]] == INF) {
        d[rmatch[v]] = d[u] + 1;
        q.push(rmatch[v]);
      }
    }
  }
  return d[0] < INF;
}

bool dfs(int u) {
  if (u == 0) return true;
  for (auto [v, id] : G[u]) {
    if (d[rmatch[v]] == d[u] + 1 && dfs(rmatch[v])) {
      lmatch[u] = v;
      rmatch[v] = u;
      mx[u] = my[v] = id;
      return true;
    }
  }
  return false;
}

int max_match() {  // left size, right size
  fill(lmatch + 1, lmatch + n1 + 1, 0);
  fill(rmatch + 1, rmatch + n2 + 1, 0);
  int ans = 0;
  while (bfs()) {
    for (int i = 1; i <= n1; ++i) {
      if (lmatch[i] == 0 && dfs(i)) ++ans;
    }
  }
  return ans;
}

void go(int u) {
  vx[u] = false;
  for (auto [v, id] : G[u]) if (!vy[v]) {
    vy[v] = true;
    go(rmatch[v]);
  }
}

int m, q;

int main() {
  cin >> n1 >> n2 >> m >> q;
  edges.resize(m + 1);
  FOR(i, 1, m) {
    auto &[x, y] = edges[i];
    cin >> x >> y;
    G[x].eb(y, i);
  }
  int sz = max_match();
  fill(vx + 1, vx + n1 + 1, true);
  FOR(i, 1, n1) if (!lmatch[i]) go(i);
  ll sum = 0;
  vector<int> match;
  FOR(i, 1, n1) if (vx[i]) {
    match.eb(i);
    sum += mx[i];
  }
  FOR(i, 1, n2) if (vy[i]) {
    match.eb(-i);
    sum += my[i];
  }
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      cout << "1\n" << match.back() << '\n';
      int eid = match.back() > 0 ? mx[match.back()] : my[-match.back()];
      sum -= eid, sz--;
      match.pop_back();
      cout << sum << endl;
    } else {
      cout << sz << '\n';
      for (auto x : match) cout << (x > 0 ? mx[x] : my[-x]) << ' ';
      cout << endl;
    }
  }
}