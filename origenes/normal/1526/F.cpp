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

int ask(int i, int j, int k) {
  cout << "? " << i << ' ' << j << ' ' << k << endl;
  int ret; cin >> ret;
  return ret;
}

void solve() {
  int n; cin >> n;
  int x, y;
  FOR(i, 1, 11) FOR(j, i + 1, 12) FOR(k, j + 1, 13) if (ask(i, j, k) <= (n - 4) / 6) {
    x = i, y = j;
    goto label;
  }
  label:
  vector<vector<int>> G(n);
  int mx = 0;
  FOR(i, 1, n) if (x != i && y != i) {
    int now = ask(x, y, i);
    G[now].eb(i);
    chkmax(mx, now);
  }
  int u = G[mx][0], v;
  if (G[mx - 1].size() == 1) v = G[mx - 1][0];
  else v = ask(x, u, G[mx - 1][0]) < ask(x, u, G[mx - 1][1]) ? G[mx - 1][0] : G[mx - 1][1];
  vector<int> p(n + 1);
  p[u] = 1, p[v] = 2;
  FOR(i, 1, n) if (u != i && v != i) p[i] = ask(u, v, i) + 2;
  if (p[1] > p[2]) FOR(i, 1, n) p[i] = n - p[i] + 1;
  cout << "!";
  FOR(i, 1, n) cout << ' ' << p[i];
  cout << endl;
  int ret; cin >> ret;
  assert(ret == 1);
}

int main() {
  int T; cin >> T;
  while (T--) solve();
}