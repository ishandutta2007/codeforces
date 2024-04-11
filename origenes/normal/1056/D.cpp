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

vector<int> G[maxn];
int n, cnt[maxn];

void dfs(int u, int par) {
  for (auto v : G[u]) if (v != par) {
    dfs(v, u);
    cnt[u] += cnt[v];
  }
  if (!cnt[u]) cnt[u]++;
}

int main() {
  scanf("%d", &n);
  FOR(i, 2, n) {
    int par;
    scanf("%d", &par);
    G[i].eb(par);
    G[par].eb(i);
  }
  dfs(1, 0);
  sort(cnt + 1, cnt + n + 1);
  FOR(i, 1, n) printf("%d ", cnt[i]);
}