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

int n, ans, clk;
int a[maxn], cnt[2 * maxn], vis[2 * maxn];

void dfs(int u) {
  if (vis[u] == clk) return;
  if (cnt[u] >= 2) return;
  cnt[u]++;
  vis[u] = clk;
  ROF(i, 21, 0) if (u & (1 << i)) dfs(u ^ (1 << i));
}

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", a + i);
  ROF(i, n, 1) {
    if (i <= n - 2) {
      int mask = 0, cur = 0;
      ROF(j, 21, 0) {
        if (a[i] & (1 << j)) {
          mask |= 1 << j;
          continue;
        }
        if (cnt[cur | (1 << j)] >= 2) {
          mask |= 1 << j;
          cur |= 1 << j;
        }
      }
      chkmax(ans, mask);
    }
    ++clk;
    dfs(a[i]);
  }
  printf("%d", ans);
}