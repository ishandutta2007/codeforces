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

const int maxm = 1 << 22;

bool vis[maxm], have[maxm];
int m, n, ALL, ans;

void dfs(int u) {
  if (vis[u]) return;
  vis[u] = true;
  if (have[u]) dfs(ALL ^ u);
  REP(i, n) if (u & (1 << i)) dfs(u ^ (1 << i));
}

int main() {
  scanf("%d%d", &n, &m);
  REP(i, m) {
    int a;
    scanf("%d", &a);
    have[a] = true;
  }
  ALL = (1 << n) - 1;
  REP(i, ALL + 1) if (have[i] && !vis[i]) {
    ans++;
    vis[i] = true;
    dfs(ALL ^ i);
  }
  printf("%d", ans);
}