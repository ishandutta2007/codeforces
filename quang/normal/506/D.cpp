#include <bits/stdc++.h>

#define Task "D"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

const int N = 100100;

int n, m, q, cnt;
vector <pair<int, int> > edge[N];
int u[N], v[N];
map < pair<int, int>, int> sl;
int ans[N], lab[N], fa[N];

int Getfa(int x) {
  return (fa[x] == x) ? x : (fa[x] = Getfa(fa[x]));
}

int main() {
  ios_base::sync_with_stdio(0);
  //fi, fo;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    edge[c].push_back(make_pair(a, b));
  }
  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> u[i] >> v[i];
  }
  for (int i = 1; i <= m; i++) {
    if (!edge[i].size()) {
      continue;
    }
    vector <int> ds;
    for (int j = 0; j < edge[i].size(); j++) {
      int x = edge[i][j].first;
      int y = edge[i][j].second;
      ds.push_back(x);
      ds.push_back(y);
    }
    ++cnt;
    sort(ds.begin(), ds.end());
    ds.resize(unique(ds.begin(), ds.end()) - ds.begin());
    for (int j = 0; j < ds.size(); j++) {
      int x = ds[j];
      lab[x] = cnt;
      fa[x] = x;
    }
    for (int j = 0; j < edge[i].size(); j++) {
      int x = Getfa(edge[i][j].first);
      int y = Getfa(edge[i][j].second);
      if (x != y) {
        fa[x] = y;
      }
    }
    if (1ll * ds.size() * ds.size() > n) {
      for (int j = 1; j <= q; j++) {
        if (lab[u[j]] != cnt || lab[v[j]] != cnt) {
          continue;
        }
        ans[j] += (Getfa(u[j]) == Getfa(v[j]));
      }
    } else {
      for (int j = 0; j < ds.size(); j++) {
        for (int k = j + 1; k < ds.size(); k++) {
          if (Getfa(ds[j]) == Getfa(ds[k])) {
            sl[make_pair(ds[j], ds[k])]++;
            sl[make_pair(ds[k], ds[j])]++;
          }
        }
      }
    }
  }
  for (int i = 1; i <= q; i++) {
    cout << ans[i] + sl[make_pair(u[i], v[i])] << endl;
  }
  return 0;
}