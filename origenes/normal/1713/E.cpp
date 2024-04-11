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

int a[maxn][maxn], par[maxn * 2];

int Find(int x) {
  return par[x] == x ? x : par[x] = Find(par[x]);
}

void solve() {
  int n; cin >> n;
  FOR(i, 1, n) FOR(j, 1, n) cin >> a[i][j];
  iota(par + 1, par + 2 * n + 1, 1);
  FOR(i, 1, n) FOR(j, i + 1, n) {
    if (a[i][j] > a[j][i]) {
      int u = i, v = j, nu = u + n, nv = v + n;
      if (Find(nu) == Find(nv)) continue;
      par[Find(u)] = Find(nv);
      par[Find(nu)] = Find(v);
    } else if (a[i][j] < a[j][i]) {
      int u = i, v = j, nu = u + n, nv = v + n;
      if (Find(u) == Find(nv)) continue;
      par[Find(u)] = Find(v);
      par[Find(nu)] = Find(nv);
    }
  }
  set<int> heads;
  FOR(i, 1, n) if (par[i] == i) heads.emplace(i);
  FOR(i, 1, n) if (heads.count(Find(i))) FOR(j, 1, n) swap(a[i][j], a[j][i]);
  FOR(i, 1, n) {
    FOR(j, 1, n) cout << a[i][j] << ' ';
    cout << '\n';
  }
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}