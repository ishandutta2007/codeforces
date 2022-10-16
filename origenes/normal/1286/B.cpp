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

const int maxn = 2123;

int n, p[maxn], c[maxn], a[maxn], sz[maxn];
bool bad;
vector<int> G[maxn];

void dfs(int u) {
  sz[u] = 1;
  for (auto v : G[u]) {
    dfs(v);
    sz[u] += sz[v];
  }
}

void dfs(int u, vector<int> &avail) {
  if (avail.size() <= c[u]) {
    bad = true;
    return;
  }
  a[u] = avail[c[u]];
  avail.erase(avail.begin() + c[u]);
  int OFF = 0;
  for (auto v : G[u]) {
    vector<int> have(avail.begin() + OFF, avail.begin() + OFF + sz[v]);
    dfs(v, have);
    OFF += sz[v];
  }
}

int main() {
  scanf("%d", &n);
  int root;
  FOR(i, 1, n) {
    scanf("%d%d", p + i, c + i);
    G[p[i]].eb(i);
    if (p[i] == 0) root = i;
  }
  dfs(root);
  vector<int> avail(n);
  iota(all(avail), 1);
  dfs(root, avail);
  if (bad) puts("NO");
  else {
    puts("YES");
    FOR(i, 1, n) printf("%d ", a[i]);
  }
}