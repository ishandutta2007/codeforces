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

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int n; cin >> n;
  vector<int> f(n + 2), par(n + 2);
  vector<vector<int>> mx(n + 2, vector<int>(2));
  FOR(i, 2, n + 1) {
    cin >> par[i];
    f[i] = 1;
    for (int u = i; u != 1; u = par[u]) {
      if (f[u] > mx[par[u]][0]) {
        mx[par[u]][1] = mx[par[u]][0];
        mx[par[u]][0] = f[u];
      } else chkmax(mx[par[u]][1], f[u]);
      if (max(mx[par[u]][1] + 1, mx[par[u]][0]) == f[par[u]]) break;
      f[par[u]] = max(mx[par[u]][0], mx[par[u]][1] + 1);
    }
    cout << mx[1][0] << ' ';
  }
}