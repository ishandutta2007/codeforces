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

int n, m;
int st[maxn], en[maxn];
set<int> G[maxn];
vector<int> ans;

void dfs(int u, int par, bool f) {
  if (par) {
    if (f) ans.eb(par);
    G[u].erase(par);
    if (G[u].empty()) {
      if (!f) ans.eb(par);
      return;
    }
  }
  int now = *G[u].begin();
  G[u].erase(G[u].begin());
  dfs(st[now] ^ en[now] ^ u, now, !f);
}

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, m) {
    scanf("%d%d", st + i, en + i);
    G[st[i]].emplace(i);
    G[en[i]].emplace(i);
  }
  FOR(i, 1, n) if (G[i].size() & 1) dfs(i, 0, false);
  FOR(i, 1, n) if (G[i].size()) dfs(i, 0, false);
  printf("%d\n", int(ans.size()));
  for (auto idx : ans) printf("%d %d\n", st[idx], en[idx]);
}