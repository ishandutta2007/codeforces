#include <bits/stdc++.h>

#define Task "B"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

const int N = 100100;

int n, m, ans = 0;
int fa[N], u[N], v[N], cnt[N], ord[N], deg[N];
vector <pair<int, int> > edge[N];
vector <int> a[N];

int Root(int x) {
  return (fa[x] == x) ? x : (fa[x] = Root(fa[x]));
}

int Get(int x) {
  for (int i = 1; i <= cnt[x]; i++) {
    deg[i] = 0;
    a[i].clear();
  }
  for (int i = 0; i < edge[x].size(); i++) {
    a[edge[x][i].first].push_back(edge[x][i].second);
    deg[edge[x][i].second]++;
  }
  int dem =0;
  queue <int> q;
  for (int i = 1; i <= cnt[x]; i++) {
    if (!deg[i]) {
      q.push(i);
    }
  }
  while (!q.empty()) {
    int foo = q.front();
    q.pop();
    dem++;
    for (int i = 0; i < a[foo].size(); i++) {
      int foo2 = a[foo][i];
      if (--deg[foo2] == 0) {
        q.push(foo2);
      }
    }
  }
  return cnt[x] == dem ? cnt[x] - 1 : cnt[x];
}

int main() {
  ios_base::sync_with_stdio(0);
  //fi, fo;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    fa[i] = i;
  }
  for (int i = 1; i <= m; i++) {
    cin >> u[i] >> v[i];
    int xx = Root(u[i]);
    int yy = Root(v[i]);
    if(Root(xx) != Root(yy)) {
      fa[xx] = yy;
    }
  }
  for (int i = 1; i <= n; i++) {
    ord[i] = ++cnt[Root(i)];
  }
  for (int i = 1; i <= m; i++) {
    edge[Root(u[i])].push_back(make_pair(ord[u[i]], ord[v[i]]));
  }
  for (int i = 1; i <= n; i++) {
    if (!edge[i].size()) {
      continue;
    }
    ans += Get(i);
  }
  cout << ans;
  return 0;
}