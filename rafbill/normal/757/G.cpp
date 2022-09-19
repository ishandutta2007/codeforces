#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
#include <bits/stdc++.h>

using namespace std;

const int N = 400010;

vector < pair <int, long long> > forc[N];
vector < pair <int, pair <int, long long> > > other[N];
vector < pair <int, pair <int, long long> > > centroid[N];
long long dist[N];
int sub[N];
bool alive[N];
int belongs[N];
vector < pair <int, int> > g[N];
int perm[N], pos[N];
int v_goes_to[N];
vector <int> all;
vector <int> in_forc[N], in_other[N];

void dfs(int v, int pr) {
  all.push_back(v);
  sub[v] = 1;
  int sz = g[v].size();
  for (int j = 0; j < sz; j++) {
    int u = g[v][j].first;
    if (!alive[u] || u == pr) {
      continue;
    }
    int len = g[v][j].second;
    dist[u] = dist[v] + len;
    belongs[u] = (belongs[v] == -1 ? u : belongs[v]);
    dfs(u, v);
    sub[v] += sub[u];
  }
}

void build(int v) {
  all.clear();
  dfs(v, -1);
  {
    // changing the root
    int old_v = v;
    int total = sub[v];
    int pr = -1;
    while (true) {
      bool found = false;
      int sz = g[v].size();
      for (int j = 0; j < sz; j++) {
        int u = g[v][j].first;
        if (!alive[u] || u == pr) {
          continue;
        }
        if (2 * sub[u] >= total) {
          pr = v;
          v = u;
          found = true;
          break;
        }
      }
      if (!found) {
        break;
      }
    }
    v_goes_to[old_v] = v;
  }
  all.clear();
  dist[v] = 0;
  belongs[v] = -1;
  dfs(v, -1);
  int cnt = all.size();
  for (int i = 0; i < cnt; i++) {
    int u = all[i];
    centroid[u].push_back(make_pair(v, make_pair(belongs[u], dist[u])));
  }
  for (int i = 0; i < cnt; i++) {
    int u = all[i];
    forc[v].push_back(make_pair(pos[u], dist[u]));
  }
  sort(forc[v].begin(), forc[v].end());
  for (int j = 1; j < cnt; j++) {
    forc[v][j].second += forc[v][j - 1].second;
  }
  for (int i = 1; i < cnt; i++) {
    int u = all[i];
    other[v].push_back(make_pair(belongs[u], make_pair(pos[u], dist[u])));
  }
  sort(other[v].begin(), other[v].end());
  for (int j = 1; j < cnt - 1; j++) {
    other[v][j].second.second += other[v][j - 1].second.second;
  }
  for (int i = 0; i < cnt; i++) {
    int u = perm[forc[v][i].first];
    in_forc[u].push_back(i);
  }
  for (int i = 0; i < cnt - 1; i++) {
    int u = perm[other[v][i].second.first];
    in_other[u].push_back(i);
  }
  vector <int> children;
  for (int i = 0; i < cnt; i++) {
    int u = all[i];
    if (belongs[u] == u) {
      children.push_back(u);
    }
  }
  alive[v] = false;
  for (int i = 0; i < (int) children.size(); i++) {
    build(children[i]);
  }
}

int main() {
  int n, tt;
  scanf("%d %d", &n, &tt);
  for (int i = 0; i < n; i++) {
    scanf("%d", perm + i);
    perm[i]--;
    pos[perm[i]] = i;
  }
  for (int i = 0; i < n - 1; i++) {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    x--; y--;
    g[x].push_back(make_pair(y, z));
    g[y].push_back(make_pair(x, z));
  }
  for (int i = 0; i < n; i++) {
    alive[i] = true;
  }
  build(0);
  int last = 0;
  while (tt--) {
    int com;
    scanf("%d", &com);
    if (com == 1) {
      int from, to, ver;
      scanf("%d %d %d", &from, &to, &ver);
      from ^= last;
      to ^= last;
      ver ^= last;
      from--; to--; ver--;
      long long ans = 0;
      for (pair <int, pair <int, long long> > p : centroid[ver]) {
        int v = p.first;
        int bel = p.second.first;
        long long d = p.second.second;
        long long sumd = 0;
        int cnt = 0;
        {
          int pf = lower_bound(forc[v].begin(), forc[v].end(), make_pair(from, -1LL)) - forc[v].begin();
          int pt = lower_bound(forc[v].begin(), forc[v].end(), make_pair(to + 1, -1LL)) - forc[v].begin();
          if (pf < pt) {
            sumd += forc[v][pt - 1].second;
            if (pf > 0) {
              sumd -= forc[v][pf - 1].second;
            }
            cnt += pt - pf;
          }
        }
        {
          int pf = lower_bound(other[v].begin(), other[v].end(), make_pair(bel, make_pair(from, -1LL))) - other[v].begin();
          int pt = lower_bound(other[v].begin(), other[v].end(), make_pair(bel, make_pair(to + 1, -1LL))) - other[v].begin();
          if (pf < pt) {
            sumd -= other[v][pt - 1].second.second;
            if (pf > 0) {
              sumd += other[v][pf - 1].second.second;
            }
            cnt -= pt - pf;
          }
        }
        ans += sumd + cnt * d;
      }
      printf("%I64d\n", ans);
      last = ans & ((1 << 30) - 1);
    } else {
      int x;
      scanf("%d", &x);
      x ^= last;
      x--;
      int v1 = perm[x];
      int v2 = perm[x + 1];
      int c1 = centroid[v1].size();
      int c2 = centroid[v2].size();
      int i1 = 0;
      int i2 = 0;
      while (i1 < c1 && i2 < c2 && centroid[v1][i1].first == centroid[v2][i2].first) {
        pair <int, pair <int, long long> > p = centroid[v1][i1];
        int v = p.first;
        int bel1 = p.second.first;
//        long long d1 = p.second.second;
        int bel2 = centroid[v2][i2].second.first;
        long long d2 = centroid[v2][i2].second.second;
        {
          int at = in_forc[v1][i1]; //lower_bound(forc[v].begin(), forc[v].end(), make_pair(pos[v1], -1LL)) - forc[v].begin();
          forc[v][at].second = (at == 0 ? 0LL : forc[v][at - 1].second) + d2;
          swap(in_forc[v1][i1], in_forc[v2][i2]);
        }
        {
          if (bel1 == bel2) {
            int at = in_other[v1][i1]; //lower_bound(other[v].begin(), other[v].end(), make_pair(bel1, make_pair(pos[v1], -1LL))) - other[v].begin();
            other[v][at].second.second = (at == 0 ? 0LL : other[v][at - 1].second.second) + d2;
            swap(in_other[v1][i1], in_other[v2][i2]);
          } else {
            if (v != v1) {
              int at = in_other[v1][i1]; //lower_bound(other[v].begin(), other[v].end(), make_pair(bel1, make_pair(pos[v1], -1LL))) - other[v].begin();
              other[v][at].second.first = pos[v2];
            }
            if (v != v2) {
              int at = in_other[v2][i2]; //lower_bound(other[v].begin(), other[v].end(), make_pair(bel2, make_pair(pos[v2], -1LL))) - other[v].begin();
              other[v][at].second.first = pos[v1];
            }
          }
        }
        i1++; i2++;
      }
      for (int rot = 0; rot < 2; rot++) {
        while (i1 < c1) {
          pair <int, pair <int, long long> > p = centroid[v1][i1];
          int v = p.first;
//          int bel = p.second.first;
//          long long d = p.second.second;
          {
            int at = in_forc[v1][i1]; //lower_bound(forc[v].begin(), forc[v].end(), make_pair(pos[v1], -1LL)) - forc[v].begin();
            forc[v][at].first = pos[v2];
          }
          if (v != v1) {
            int at = in_other[v1][i1]; //lower_bound(other[v].begin(), other[v].end(), make_pair(bel, make_pair(pos[v1], -1LL))) - other[v].begin();
            other[v][at].second.first = pos[v2];
          }
          i1++;
        }
        swap(v1, v2);
        swap(c1, c2);
        swap(i1, i2);
      }
      swap(perm[x], perm[x + 1]);
      pos[perm[x]] = x;
      pos[perm[x + 1]] = x + 1;
    }
  }
  return 0;
}