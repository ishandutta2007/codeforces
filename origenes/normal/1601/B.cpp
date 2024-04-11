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

int n, a[maxn], b[maxn], f[maxn], pre[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  FOR(i, 1, n) cin >> a[i];
  FOR(i, 1, n) cin >> b[i];
  int reach = n;
  f[n] = 0;
  queue<int> q; q.emplace(n);
  while (!q.empty()) {
    auto v = q.front(); q.pop();
    int u = v + b[v];
    ROF(i, a[u], 0) {
      if (u - i >= reach) break;
      f[u - i] = f[v] + 1;
      pre[u - i] = v;
      q.emplace(u - i);
    }
    if (u == a[u]) break;
    chkmin(reach, u - a[u]);
  }
  if (f[0] == 0) {
    cout << -1;
    return 0;
  }
  cout << f[0] << '\n';
  vector<int> ans;
  for (int u = 0; u != n; u = pre[u]) ans.eb(u);
  reverse(all(ans));
  for (auto x : ans) cout << x << ' ';
}