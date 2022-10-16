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

int Find(int *p, int x) {
  return p[x] == x ? x : p[x] = Find(p, p[x]);
}

int p1[maxn], p2[maxn];
int n, m1, m2;
map<int, int> idx[maxn];
set<int> row[maxn], col[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> m1 >> m2;
  iota(p1 + 1, p1 + n + 1, 1);
  iota(p2 + 1, p2 + n + 1, 1);
  FOR(i, 1, m1) {
    int u, v;
    cin >> u >> v;
    u = Find(p1, u), v = Find(p1, v);
    p1[u] = v;
  }
  FOR(i, 1, m2) {
    int u, v;
    cin >> u >> v;
    u = Find(p2, u), v = Find(p2, v);
    p2[u] = v;
  }
  if (m1 < m2) swap(p1, p2);
  FOR(i, 1, n) {
    int r = Find(p1, i), c = Find(p2, i);
    idx[r][c] = i;
    row[r].emplace(c); col[c].emplace(r);
  }
  set<pii> q;
  FOR(i, 1, n) if (Find(p1, i) == i) q.emplace(-int(row[i].size()), i);
  vector<pii> ans;
  while (q.size() > 1) {
    auto r1 = q.begin()->_2; q.erase(q.begin());
    auto r2 = q.begin()->_2; q.erase(q.begin());
    if (row[r1].size() < row[r2].size()) swap(r1, r2);
    auto it = row[r1].begin();
    int c1 = *it == *row[r2].begin() ? *(++it) : *it, c2 = *row[r2].begin();
    ans.eb(idx[r1][c1], idx[r2][c2]);
    if (col[c1].size() < col[c2].size()) swap(c1, c2);
    for (auto c : row[r2]) {
      idx[r1][c] = idx[r2][c];
      row[r1].emplace(c);
      col[c].erase(r2);
      col[c].emplace(r1);
    }
    for (auto r : col[c2]) {
      idx[r][c1] = idx[r][c2];
      col[c1].emplace(r);
      row[r].erase(c2);
      row[r].emplace(c1);
    }
    q.emplace(-int(row[r1].size()), r1);
  }
  cout << ans.size() << '\n';
  for (auto [u, v] : ans) cout << u << ' ' << v << '\n';
}