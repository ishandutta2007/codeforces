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

const int maxn = 312345;

int n, cnt[maxn][2];
pii par[maxn][2];

pii Find(int i, int j) {
  return par[i][j] == mp(i, j) ? mp(i, j) : par[i][j] = Find(par[i][j]._1, par[i][j]._2);
}

void Union(pii a, pii b) {
  auto [u, i] = Find(a._1, a._2);
  auto [v, j] = Find(b._1, b._2);
  if (u == v && i == j) return;
  par[v][j] = mp(u, i);
  cnt[u][i] += cnt[v][j];
}

void solve() {
  string s;
  cin >> n >> s;
  REP(i, n + 1) REP(j, 2) {
    par[i][j] = {i, j};
    cnt[i][j] = 1;
  }
  REP(i, n) {
    if (s[i] == 'L') Union(mp(i + 1, 0), mp(i, 1));
    else Union(mp(i, 0), mp(i + 1, 1));
  }
  REP(i, n + 1) {
    auto [u, j] = Find(i, 0);
    cout << cnt[u][j] << ' ';
  }
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