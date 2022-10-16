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

int n, par[maxn];
int c[maxn], l[maxn], r[maxn];

int Find(int x) {
  return par[x] == x ? x : par[x] = Find(par[x]);
}

void Union(int x, int y) {
  x = Find(x); y = Find(y);
  par[x] = y;
}

void solve() {
  cin >> n;
  FOR(i, 1, n) cin >> c[i] >> l[i] >> r[i];
  iota(par + 1, par + n + 1, 1);
  priority_queue<array<int, 4>> q1;
  FOR(i, 1, n) q1.push({r[i], c[i], l[i], i});
  priority_queue<pii> q2[2];
  while (!q1.empty()) {
    auto [r, c, l, i] = q1.top(); q1.pop();
    REP(j, 2) while (!q2[j].empty() && q2[j].top()._1 > r) q2[j].pop();
    q2[c].emplace(l, i);
    if (q2[1 - c].empty()) continue;
    while (q2[1 - c].size() > 1) {
      Union(q2[1 - c].top()._2, i);
      q2[1 - c].pop();
    }
    Union(q2[1 - c].top()._2, i);
  }
  int ans = 0;
  FOR(i, 1, n) if (Find(i) == i) ans++;
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