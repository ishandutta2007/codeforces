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

const int upp = 812;
const int maxn = 112345;

int n, k, f[2][upp], g[2][upp];
vector<int> G[maxn];

int main() {
  scanf("%d%d", &n, &k);
  REP(i, k) {
    int x, y;
    scanf("%d%d", &x, &y);
    G[y].eb(x + 1 - y);
  }
  FOR(i, 1, n) sort(all(G[i]));
  int pre = 0, now = 1;
  FOR(i, 1, n) {
    f[now][0] = g[now][0] = g[pre][1] + 3 * G[i].size();
    FOR(j, 1, min(n - i + 1, 800)) {
      int d = 3 * (upper_bound(all(G[i]), n - i + 1 - j) - G[i].begin());
      f[now][j] = 2 + j * (j + 1) / 2 + g[pre][j] + d;
      if (i > 1 && j < 800) chkmin(f[now][j], f[pre][j + 1] + d);
      g[now][j] = min(g[now][j - 1], f[now][j]);
    }
    swap(now, pre);
  }
  printf("%d", min(f[pre][0], f[pre][1]));
}