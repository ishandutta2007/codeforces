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

const int maxn = 11234567;

int vis[maxn], last[maxn];

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1), pre(n + 1);
  FOR(i, 1, n) {
    cin >> a[i];
    int x = 1;
    while (vis[a[i]]) {
      int p = vis[a[i]], cnt = 0;
      while (a[i] % p == 0) {
        a[i] /= p;
        cnt = 1 - cnt;
      }
      if (cnt) x *= p;
    }
    if (a[i] > 0) x *= a[i];
    a[i] = x;
    pre[i] = last[a[i]];
    last[a[i]] = i;
  }
  set<int> occ;
  occ.emplace(0);
  vector<vector<int>> f(n + 1, vector<int>(k + 1));
  FOR(i, 1, n) {
    if (pre[i]) {
      occ.emplace(pre[i]);
      if (occ.size() > k + 1) occ.erase(occ.begin());
    }
    REP(j, k + 1) f[i][j] = i;
    int rm = int(occ.size()) - 1;
    for (auto pi : occ) {
      FOR(j, rm, k) chkmin(f[i][j], f[pi][j - rm] + 1);
      rm--;
    }
  }
  cout << *min_element(all(f[n])) << '\n';
  FOR(i, 1, n) last[a[i]] = 0;
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  FOR(i, 2, 1e7) if (!vis[i]) {
    for (ll j = ll(i) * i; j <= 1e7; j += i) if (!vis[j]) vis[j] = i;
  }
  int T; cin >> T;
  while (T--) solve();
}