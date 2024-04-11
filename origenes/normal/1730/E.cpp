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

const int maxn = 1123456;

int n;
int a[maxn], l[maxn], r[maxn];
int pl[maxn], pr[maxn];
vector<int> pos[maxn];

int Find(int *par, int x) {
  return par[x] == x ? x : par[x] = Find(par, par[x]);
}

void solve() {
  cin >> n;
  FOR(i, 1, n) cin >> a[i];
  FOR(i, 1, 1e6) pos[i].clear();
  iota(pl, pl + n + 2, 0);
  iota(pr, pr + n + 2, 0);
  FOR(i, 1, n) {
    pos[a[i]].eb(i);
    r[i] = n + 1;
  }
  stack<int> S;
  FOR(i, 1, n) {
    while (!S.empty() && a[S.top()] < a[i]) {
      r[S.top()] = i;
      S.pop();
    }
    l[i] = S.empty() ? 0 : S.top();
    S.emplace(i);
  }
  ll ans = 0;
  ROF(i, 1e6, 1) if (!pos[i].empty()) {
    for (int j = i + i; j <= 1e6; j += i)
      for (auto x : pos[j]) ans -= ll(x - max(l[x], Find(pl, x))) * (min(r[x], Find(pr, x)) - x);
    for (auto x : pos[i]) {
      pl[x] = Find(pl, x - 1);
      pr[x] = Find(pr, x + 1);
    }
    for (int j = i; j <= 1e6; j += i)
      for (auto x : pos[j]) ans += ll(x - max(l[x], Find(pl, x))) * (min(r[x], Find(pr, x)) - x);
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