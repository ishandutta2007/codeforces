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

int n;
vector<int> G[maxn];
vector<pii> edges;

void dfs(int u, int par) {
  for (auto v : G[u]) if (v != par) {
    edges.eb(u, v);
    dfs(v, u);
  }
}

int ask(int l, int r) {
  set<int> qs;
  FOR(i, l, r) {
    qs.emplace(edges[i]._1);
    qs.emplace(edges[i]._2);
  }
  cout << "? " << qs.size();
  for (auto x : qs) cout << ' ' << x;
  cout << endl;
  int ret; cin >> ret;
  return ret;
}

int main() {
  cin >> n;
  REP(i, n - 1) {
    int u, v;
    cin >> u >> v;
    G[u].eb(v); G[v].eb(u);
  }
  dfs(1, 0);
  int mx = ask(0, edges.size() - 1), lo = 0, hi = edges.size() - 1;
  while (lo < hi) {
    int mi = lo + hi >> 1;
    if (ask(lo, mi) == mx) hi = mi;
    else lo = mi + 1;
  }
  cout << "! " << edges[lo]._1 << ' ' << edges[lo]._2 << endl;
}