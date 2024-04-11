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
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 512345;

int n, r = 1;
int st[maxn][20], a[maxn];
ll w;
vector<int> G[maxn];

void dfs(int u, int par) {
  st[u][0] = par;
  FOR(i, 1, 19) st[u][i] = st[st[u][i - 1]][i - 1];
  for (int v : G[u]) if (v != par) dfs(v, u);
}

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", a + i);
  FOR(i, 2, n) if (a[i] < a[r]) r = i;
  REP(i, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].eb(v);
    G[v].eb(u);
  }
  dfs(r, 0);
  FOR(i, 1, n) if (i != r) {
    ll now = a[st[i][0]];
    FOR(j, 1, 19) {
      if (st[i][j]) chkmin(now, ll(j + 1) * a[st[i][j]]);
      else {
        chkmin(now, ll(j + 1) * a[r]);
        break;
      }
    }
    w += now + a[i];
  }
  printf("%lld", w);
}