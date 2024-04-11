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

const int maxn = 112345;

bool inq[maxn];
int par[maxn];
tuple<int, int, int> tri[maxn];
vector<int> G[maxn];
set<int> belong[maxn];

int Find(int x) {
  return par[x] == x ? x : par[x] = Find(par[x]);
}

void Union(int u, int v) {
  u = Find(u), v = Find(v);
  par[u] = v;
}

void solve() {
  int n; scanf("%d", &n);
  iota(par + 1, par + n + 1, 1);
  fill(inq + 1, inq + n + 1, false);
  FOR(i, 1, n) belong[i].clear(), G[i].clear();
  FOR(i, 1, n - 2) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    belong[a].emplace(i); belong[b].emplace(i); belong[c].emplace(i);
    tri[i] = {a, b, c};
  }
  queue<pii> q;
  FOR(i, 1, n) if (belong[i].size() == 1 && !inq[*belong[i].begin()]) {
    q.emplace(i, *belong[i].begin());
    inq[*belong[i].begin()] = true;
  }
  vector<int> ans2; ans2.reserve(n - 2);
  while (!q.empty()) {
    int x = q.front()._1, grp = q.front()._2; q.pop();
//    BUG(grp);
    ans2.eb(grp);
    int a = get<0>(tri[grp]), b = get<1>(tri[grp]), c = get<2>(tri[grp]);
    if (b == x) swap(a, b); if (c == x) swap(a, c);
    assert(belong[a].size() == 1);
    if (Find(a) != Find(b)) {
      G[a].eb(b); G[b].eb(a);
      Union(a, b);
    }
    if (Find(a) != Find(c)) {
      G[a].eb(c); G[c].eb(a);
      Union(a, c);
    }
    belong[b].erase(grp); belong[c].erase(grp);
    if (belong[b].size() == 1 && !inq[*belong[b].begin()]) {
      q.emplace(b, *belong[b].begin());
      inq[*belong[b].begin()] = true;
    }
    if (belong[c].size() == 1 && !inq[*belong[c].begin()]) {
      q.emplace(c, *belong[c].begin());
      inq[*belong[c].begin()] = true;
    }
  }
  int st = 1;
  FOR(i, 1, n) {
    assert(!G[i].empty() && G[i].size() <= 2);
    if (G[i].size() == 1) {
      st = i;
      break;
    }
  }
  vector<int> ans1; ans1.reserve(n);
  vector<char> vis(n + 1);
  for (int u = st; !vis[u]; ) {
    ans1.eb(u);
    vis[u] = true;
    for (auto v : G[u]) if (!vis[v]) {
      u = v;
      break;
    }
  }
//  BUG(ans1.size());
//  BUG(ans2.size());
  assert(ans1.size() == n && ans2.size() == n - 2);
  for (auto u : ans1) printf("%d ", u);
  putchar('\n');
  for (auto u : ans2) printf("%d ", u);
  putchar('\n');
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}