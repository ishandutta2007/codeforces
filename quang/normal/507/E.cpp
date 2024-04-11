#include <bits/stdc++.h>

#define Task "C"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

const int N = 100100;

int n, m;
vector <int> a[N];
vector <pair <pair <int, int >, bool > > ds;
vector <int> ans;
bool dd[N];
int tr[N];

void Go() {
  priority_queue <pair<int, int> > p;
  vector <int> d(n + 1, 1000000);
  vector <int> slmin(n + 1, 1000000);
  vector <int> used(n + 1, 0);
  p.push(make_pair(0, 1));
  d[1] = 0;
  slmin[1] = 0;
  while(!p.empty()) {
    int u = p.top().second;
    p.pop();
    if (used[u]) continue;
    used[u] = 1;
    for (int i = 0; i < a[u].size(); i++) {
      int w = a[u][i], v;
      int x = ds[w].second ^ 1;
      if (u == ds[w].first.first) v = ds[w].first.second;
      else v = ds[w].first.first;
      if (d[v] == d[u] + 1) {
        if (slmin[v] > slmin[u] + x) {
          slmin[v] = slmin[u] + x;
          tr[v] = w;
        }
      }
      if (d[v] > d[u] + 1) {
        d[v] = d[u] + 1;
        tr[v] = w;
        slmin[v] = slmin[u] + x;
        p.push(make_pair(-d[v], v));
      }
    }
  }
  int u = n;
  while(u) {
    int w = tr[u];
    dd[w] = 1;
    if (u == ds[w].first.first) u = ds[w].first.second;
    else u = ds[w].first.first;
  }
  for (int i = 1; i <= m; i++)
  if (dd[i] ^ ds[i].second)
    ans.push_back(i);
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    int u = ans[i];
    cout << ds[u].first.first << " " << ds[u].first.second << " " << (ds[u].second ^ 1) << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  //fi, fo;
  cin >> n >> m;
  ds.resize(m + 1);
  for (int i = 1; i <= m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    a[x].push_back(i);
    a[y].push_back(i);
    ds[i] = make_pair(make_pair(x, y), z);
  }
  Go();
  return 0;
}