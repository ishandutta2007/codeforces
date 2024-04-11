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

const int maxn = 212;
const int maxm = 2123;

int n, m;
int G[maxn][maxn];
int u[maxm], v[maxm], b[maxm];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> m;
  FOR(i, 1, n) FOR(j, 1, n) if (i != j) G[i][j] = 1e9;
  FOR(i, 1, m) {
    cin >> u[i] >> v[i] >> b[i];
    G[u[i]][v[i]] = 1;
    G[v[i]][u[i]] = (b[i] == 0 ? 1 : -1);
  }
  FOR(k, 1, n) FOR(i, 1, n) FOR(j, 1, n) {
    if (G[i][k] != 1e9 && G[k][j] != 1e9) {
      chkmin(G[i][j], G[i][k] + G[k][j]);
      if (G[i][j] < -1e9) {
        cout << "NO";
        return 0;
      }
    }
  }
  pii best = {-1, 1};
  FOR(i, 1, n) {
    if (G[i][i] < 0) {
      cout << "NO";
      return 0;
    }
    FOR(j, 1, n) chkmax(best, mp(G[i][j], i));
  }
  int w = best._2;
  FOR(i, 1, m) if (G[w][u[i]] == G[w][v[i]]) {
    cout << "NO";
    return 0;
  }
  cout << "YES\n" << best._1 << '\n';
  FOR(i, 1, n) cout << G[w][i] << ' ';
}