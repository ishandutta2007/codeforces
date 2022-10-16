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

const int maxn = 25;

bool G[maxn][maxn];
int n, p;

void solve() {
  scanf("%d%d", &n, &p);
  reset(G, 0);
  REP(i, n) {
    printf("%d %d\n", i + 1, (i + 1) % n + 1);
    printf("%d %d\n", i + 1, (i + 2) % n + 1);
    G[i][(i + 1) % n] = G[(i + 1) % n][i] = true;
    G[i][(i + 2) % n] = G[(i + 2) % n][i] = true;
  }
  REP(i, n) REP(j, i) if (!G[i][j] && p) {
    printf("%d %d\n", i + 1, j + 1);
    G[i][j] = G[j][i] = true;
    p--;
  }
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}