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

const int maxn = 212345;

vector<int> G[maxn];
int n;
int a[maxn], b[maxn];
ll f[maxn], ans;
bool pre[maxn];

void dfs(int u, int par) {
  f[u] = a[u];
  for (auto v : G[u]) if (v != par) {
    dfs(v, u);
    if (f[v] > 0) {
      f[u] += f[v];
      pre[v] = true;
    }
  }
  ans += f[u];
}

void print(int u, int par) {
  for (auto v : G[u]) if (v != par) if (pre[v]) print(v, u);
  printf("%d ", u);
  for (auto v : G[u]) if (v != par) if (!pre[v]) print(v, u);
}

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", a + i);
  FOR(i, 1, n) scanf("%d", b + i);
  FOR(i, 1, n) if (b[i] != -1) G[b[i]].eb(i);
  FOR(i, 1, n) if (b[i] == -1) dfs(i, 0);
  printf("%lld\n", ans);
  FOR(i, 1, n) if (b[i] == -1) print(i, 0);
}