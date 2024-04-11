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

ll st[maxn][18], S, w[maxn];
int n, L, ans;
int last[maxn][18], good[maxn], dep[maxn], p[maxn], up[maxn];
vector<int> ch[maxn];

void dfs1(int u) {
  st[u][0] = w[u];
  last[u][0] = u;
  FOR(i, 1, 17) {
    st[u][i] = st[u][i - 1];
    int now = p[last[u][i - 1]];
    if (!now) {
      last[u][i] = last[u][i - 1];
      continue;
    }
    st[u][i] += st[now][i - 1];
    last[u][i] = last[now][i - 1];
  }
  ll s = S;
  int l = L, now = u, pre = u;
  ROF(i, 17, 0) if (st[now][i] <= s && dep[now] - dep[last[now][i]] < l) {
    s -= st[now][i];
    l -= dep[now] - dep[last[now][i]] + 1;
    pre = last[now][i];
    now = p[last[now][i]];
  }
  up[u] = pre;
  for (auto v : ch[u]) {
    dep[v] = dep[u] + 1;
    dfs1(v);
  }
}

void dfs2(int u) {
  int rec = dep[u] + 1;
  for (auto v : ch[u]) {
    dfs2(v);
    if (dep[good[v]] < rec) {
      rec = dep[good[v]];
      good[u] = good[v];
    }
  }
  if (rec == dep[u] + 1) {
    ans++;
    good[u] = up[u];
  }
}

int main() {
  scanf("%d%d%lld", &n, &L, &S);
  FOR(i, 1, n) {
    scanf("%lld", w + i);
    if (w[i] > S) {
      puts("-1");
      return 0;
    }
  }
  FOR(i, 2, n) {
    int par;
    scanf("%d", &par);
    ch[par].eb(i);
    p[i] = par;
  }
  dep[1] = 1;
  w[0] = 2e18;
  REP(i, 18) st[0][i] = 2e18;
  dfs1(1);
  dfs2(1);
  printf("%d", ans);
}