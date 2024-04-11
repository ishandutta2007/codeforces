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
int n, m, dep[maxn], need;
bool ban[maxn];
stack<int> s;

void dfs(int u, int par) {
  dep[u] = dep[par] + 1;
  s.emplace(u);
  for (auto v : G[u]) if (v != par) {
    if (!dep[v]) dfs(v, u);
    else if (dep[u] - dep[v] + 1 >= need) {
      printf("2\n%d\n", dep[u] - dep[v] + 1);
      int have = dep[u] - dep[v] + 1;
      while (have--) {
        printf("%d ", s.top());
        s.pop();
      }
      exit(0);
    }
  }
  s.pop();
  if (!ban[u]) for (auto v : G[u]) ban[v] = true;
}

int main() {
  scanf("%d%d", &n, &m);
  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].eb(v);
    G[v].eb(u);
  }
  need = sqrt(n);
  while (sqr(need) < n) need++;
  dfs(1, 0);
  puts("1");
  for (int i = 1; need; i++) if (!ban[i]) {
    need--;
    printf("%d ", i);
  }
}