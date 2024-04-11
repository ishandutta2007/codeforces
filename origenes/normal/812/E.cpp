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

const int maxn = 112345;
const int maxa = 11234567;

bool mark[maxn];
int n, sg, a[maxn], cnt[2][maxa * 2], tot[2];
ll ans;
vector<int> G[maxn];

bool dfs(int u) {
  mark[u] = true;
  for (int v : G[u]) mark[u] = dfs(v) ^ 1;
  cnt[mark[u]][a[u]]++;
  tot[mark[u]]++;
  if (mark[u]) sg ^= a[u];
  return mark[u];
}

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", a + i);
  FOR(i, 2, n) {
    int p;
    scanf("%d", &p);
    G[p].eb(i);
  }
  dfs(1);
  if (!sg) ans = tot[0] * ll(tot[0] - 1) / 2 + tot[1] * ll(tot[1] - 1) / 2;
  FOR(i, 1, n) if (mark[i]) {
      int need = sg ^ a[i];
      ans += cnt[0][need];
    }
  printf("%lld", ans);
}