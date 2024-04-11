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

const int maxn = 112345;

vector<int> G[maxn];
int n, mx;
bool odd;

void dfs(int u, int par, int dep) {
  int leaves = 0;
  for (auto v : G[u]) if (v != par) {
    dfs(v, u, dep + 1);
    if (G[v].size() == 1) leaves++;
    else mx++;
  }
  if (G[u].size() == 1) {
    if (dep & 1) odd = true;
    if (par) mx++;
  }
  if (leaves > 1) mx -= leaves - 1;
  if (leaves && dep == 1) mx--;
}

int main() {
  scanf("%d", &n);
  REP(i, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].eb(v);
    G[v].eb(u);
  }
  int r = 0;
  FOR(i, 1, n) if (G[i].size() == 1) {
    r = i;
    break;
  }
  dfs(r, 0, 0);
  printf("%d %d", odd ? 3 : 1, mx);
}