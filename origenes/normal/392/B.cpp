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

const int maxn = 45;

ll f[maxn][3][3];
int t[3][3];

ll dfs(int n, int st, int en) {
  if (~f[n][st][en]) return f[n][st][en];
  ll &ret = f[n][st][en];
  int other;
  REP(i, 3) if (i != st && i != en) other = i;
  ret = dfs(n - 1, st, other) + dfs(n - 1, other, en) + t[st][en];
  chkmin(ret, dfs(n - 1, st, en) + t[st][other] + dfs(n - 1, en, st) + t[other][en] + dfs(n - 1, st, en));
  return ret;
}

int main() {
  REP(i, 3) REP(j, 3) scanf("%d", &t[i][j]);
  int n;
  scanf("%d", &n);
  reset(f, -1);
  reset(f[0], 0);
  printf("%lld", dfs(n, 0, 2));
}