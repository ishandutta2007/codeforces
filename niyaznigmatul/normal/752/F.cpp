#include <cstdio>
#include <cassert>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
using namespace std;

int const N = 1234567;

int cn, cn2, ac;
int ax[N], ay[N];
int pa[N], pb[N];
int sz[N], have[N];
vector<int> edges[N];

void dfs(int v, int pv) {
  sz[v] = have[v];
  for (int to : edges[v]) {
    if (to == pv) continue;
    dfs(to, v);
    sz[v] += sz[to];
  }
}

void dfs2(int v, int pv) {
  if (have[v] == 1) {
    // if (cn > 0) {
      // ax[ac] = pa[cn - 1];
      // ay[ac] = v;
      // ++ac;
      // --cn;
    // } else {
      pb[cn2++] = v;
    // }
  }
  for (int to : edges[v]) {
    if (to == pv) continue;
    dfs2(to, v);
  }
}

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i + 1 < n; i++) {
    int v, u;
    scanf("%d%d", &v, &u);
    --v;
    --u;
    edges[v].push_back(u);
    edges[u].push_back(v);
  }
  for (int i = 0; i < 2 * k; i++) {
    int x;
    scanf("%d", &x);
    have[x - 1] = 1;
  }
  dfs(0, -1);
  int v = 0;
  int pv = -1;
  while (true) {
    bool found = false;
    for (int to : edges[v]) {
      if (to == pv) continue;
      if (sz[to] >= k) {
        pv = v;
        v = to;
        found = true;
        break;
      }
    }
    if (!found) break;
  }
  cn = 0;
  cn2 = 0;
  vector<vector<int> > g;
  for (int to : edges[v]) {
    dfs2(to, v);
    g.push_back(vector<int>());
    auto &list = g.back();
    while (cn2 > 0) {
      list.push_back(pb[--cn2]);
    }
    if (list.empty()) {
      g.pop_back();
    }
  }
  if (have[v] == 1) {
    g.push_back(vector<int>());
    auto &list = g.back();
    list.push_back(v);
  }
  set<pair<int, int> > w;
  for (int i = 0; i < (int) g.size(); i++) {
    w.insert({-(int) g[i].size(), i});
  }
  while (!w.empty()) {
    assert(w.size() > 1);
    pair<int, int> p1 = *w.begin();
    w.erase(w.begin());
    pair<int, int> p2 = *w.begin();
    w.erase(w.begin());
    assert(!g[p1.second].empty());
    ax[ac] = g[p1.second].back();
    ay[ac] = g[p2.second].back();
    g[p1.second].pop_back();
    g[p2.second].pop_back();
    ++ac;
    p1.first++;
    p2.first++;
    if (p1.first < 0) w.insert(p1);
    assert(-p1.first == (int) g[p1.second].size());
    if (p2.first < 0) w.insert(p2);
    assert(-p2.first == (int) g[p2.second].size());
  }
  // if (have[v] == 1) {
  //   assert(cn == 1);
  //   ax[ac] = v;
  //   ay[ac] = pa[--cn];
  //   ++ac;
  // }
  // assert(cn == 0);
  // assert(ac == k);
  puts("1");
  printf("%d\n", v + 1);
  for (int i = 0; i < ac; i++) {
    printf("%d %d %d\n", ax[i] + 1, ay[i] + 1, v + 1);
  }
}