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

int st[maxn][18], dep[maxn], in[maxn], out[maxn];
int n, m, clk;
vector<int> ch[maxn], lis[maxn];

void dfs(int u, int par) {
  in[u] = ++clk;
  dep[u] = dep[par] + 1;
  FOR(i, 1, 17) {
    st[u][i] = st[u][i - 1];
    if (st[u][i]) st[u][i] = st[st[u][i]][i - 1];
  }
  for (auto v : ch[u]) dfs(v, u);
  out[u] = clk;
}

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) {
    int r;
    scanf("%d", &r);
    st[i][0] = r;
    ch[r].eb(i);
  }
  FOR(i, 1, n) if (!dep[i] && !st[i][0]) dfs(i, 0);
  FOR(i, 1, n) lis[dep[i]].eb(in[i]);
  FOR(i, 1, n) sort(all(lis[i]));
  scanf("%d", &m);
  while (m--) {
    int v, p;
    scanf("%d%d", &v, &p);
    ROF(i, 17, 0) if (p & (1 << i)) v = st[v][i];
    if (!v) {
      printf("0 ");
      continue;
    }
    int d = dep[v] + p;
    auto it1 = lower_bound(all(lis[d]), in[v]), it2 = upper_bound(all(lis[d]), out[v]);
    if (it1 == lis[d].end()) {
      printf("0 ");
      continue;
    }
    printf("%d ", it2 - it1 - 1);
  }
}