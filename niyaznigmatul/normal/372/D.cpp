#include <set>
#include <cstdio>

using namespace std;

const int SS = 20;
const int N = 333444;
int en[N], ex[N], de[N], pv[N], ss[N], ff[N], he[N], ne[N], ct, plca[SS][N];

void dfs(int v, int pp, int d) {
  pv[v] = pp;
  en[v] = ct++;
  de[v] = d;
  for (int e = he[v]; e >= 0; e = ne[e]) {
    if (ff[e] == pp) continue;
    dfs(ff[e], v, d + 1);
  }
  ex[v] = ct;
}

bool isanc(int v, int u) {
  return en[v] <= en[u] && ex[u] <= ex[v];
}

int lca(int v, int u) {
  if (isanc(v, u)) return v;
  for (int i = SS - 1; i >= 0; i--) {
    if (!isanc(plca[i][v], u)) v = plca[i][v];
  }
  return pv[v];
}

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n - 1; i++) {
    scanf("%d%d", ss + i, ff + i);
    --ss[i];
    --ff[i];
    ss[i + n - 1] = ff[i];
    ff[i + n - 1] = ss[i];
  }
  for (int i = 0; i < n; i++) he[i] = -1;
  for (int i = 0; i < n + n - 2; i++) {
    ne[i] = he[ss[i]];
    he[ss[i]] = i;
  }
  ct = 0;
  dfs(0, -1, 0);
  for (int i = 0; i < n; i++) plca[0][i] = pv[i] < 0 ? i : pv[i];
  for (int i = 1; i < SS; i++) {
    for (int v = 0; v < n; v++) {
      plca[i][v] = plca[i - 1][plca[i - 1][v]];
    }    
  }
  int current = 0;
  set<pair<int, int> > q;
  set<pair<pair<int, int>, pair<int, int> > > llc;
  int ans = 1;
  for (int i = 0, j = 0; i < n; i++) {
//    printf("%d %d %d %d\n", i, j, current + 1 + (llc.empty() ? 0 : (de[q.begin()->second] - llc.begin()->first.first)), llc.size());
    while (j < n && current + 1 + (llc.empty() ? 0 : (de[q.begin()->second] - llc.begin()->first.first)) <= k) {
      pair<int, int> z(en[j], j);
      auto e = q.insert(z);
      int v = -1;
      int u = -1;
      if (e.first != q.begin()) {
        auto f = e.first;
        --f;
        v = f->second;
      } 
      if (e.first != (--q.end())) {
        auto f = e.first;
        ++f;
        u = f->second;
      }
      if (v >= 0 && u >= 0) {
        int vv = lca(u, v);
        current -= de[u] - de[vv];
        llc.erase(make_pair(make_pair(de[vv], vv), make_pair(v, u)));
      }
      if (v >= 0) {
        int vv = lca(j, v);
        llc.insert(make_pair(make_pair(de[vv], vv), make_pair(v, j)));
        current += de[j] - de[vv];
      }
      if (u >= 0) {
        int vv = lca(j, u);
        llc.insert(make_pair(make_pair(de[vv], vv), make_pair(j, u)));
        current += de[u] - de[vv];
      }
      ++j;
      int ffc = (llc.empty() ? 0 : (de[q.begin()->second] - llc.begin()->first.first)) + current + 1;
//      printf("%d %d %d\n", i, j, ffc);
      if (ffc <= k) {
        if (j - i > ans) {
          ans = j - i;
        }
      }
    }
    pair<int, int> z(en[i], i);
    auto e = q.find(z);
    int v = -1;
    int u = -1;
    if (e != q.begin()) {
      auto f = e;
      --f;
      v = f->second;
    } 
    if (e != (--q.end())) {
      auto f = e;
      ++f;
      u = f->second;
    }
    if (v >= 0 && u >= 0) {
      int vv = lca(u, v);
      current += de[u] - de[vv];
      llc.insert(make_pair(make_pair(de[vv], vv), make_pair(v, u)));
    }
    if (v >= 0) {
      int vv = lca(i, v);
      llc.erase(make_pair(make_pair(de[vv], vv), make_pair(v, i)));
      current -= de[i] - de[vv];
    }
    if (u >= 0) {
      int vv = lca(i, u);
      llc.erase(make_pair(make_pair(de[vv], vv), make_pair(i, u)));
      current -= de[u] - de[vv];
    }
    q.erase(e);
  }
  printf("%d\n", ans);
}