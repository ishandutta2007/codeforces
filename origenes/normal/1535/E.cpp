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

int anc[maxn][20];
ll a[maxn], c[maxn];

int main() {
  int q;
  cin >> q >> a[0] >> c[0];
  FOR(i, 1, q) {
    int op;
    cin >> op;
    if (op == 1) {
      int p;
      cin >> p >> a[i] >> c[i];
      anc[i][0] = p;
      FOR(j, 1, 19) anc[i][j] = anc[anc[i][j - 1]][j - 1];
    } else {
      int v, w;
      cin >> v >> w;
      ll have = 0, cost = 0;
      while (have < w) {
        int u = v;
        ROF(j, 19, 0) if (a[anc[u][j]] > 0) u = anc[u][j];
        if (a[u] == 0) break;
        if (have + a[u] >= w) {
          cost += (w - have) * c[u];
          a[u] -= w - have;
          have = w;
        } else {
          cost += a[u] * c[u];
          have += a[u];
          a[u] = 0;
        }
      }
      cout << have << ' ' << cost << endl;
    }
  }
}