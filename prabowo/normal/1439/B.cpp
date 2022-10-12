#include <bits/stdc++.h>
using namespace std;
 
const int N = 100005;
 
int n, m, k;
vector<int> edges[N];
 
int deg[N];
bool removed[N];
int q[N];
void removeDegLessK(int k) {
  int front = 0, tail = 0;
  for (int i = 0; i < n; ++i) {
    deg[i] = edges[i].size();
    removed[i] = false;
    if (deg[i] < k) {
      q[tail++] = i;
      removed[i] = true;
    }
  }
 
  while (front < tail) {
    int u = q[front++];
 
    for (int v: edges[u]) {
      if (removed[v]) continue;
      if (--deg[v] < k) {
        removed[v] = true;
        q[tail++] = v;
      }
    }
  }
}

void sortAndCleanList() {
  for (int i = 0; i < n; ++i) {
    if (removed[i]) continue;
    for (int j = 0; j < edges[i].size(); ++j) {
      int v = edges[i][j];
      if (removed[v]) {
        edges[i][j] = edges[i].back();
        edges[i].pop_back();
        --j;
      }
    }
    sort(edges[i].begin(), edges[i].end());
  }
}
 
bool isClique(int u, int k) {
  if (deg[u] != k-1) return false;
 
  vector<int> neighs;
  for (int v: edges[u]) {
    if (removed[v]) continue;
    neighs.push_back(v);
  }
 
  bool ret = true;
  for (int v: edges[u]) {
    if (removed[v]) continue;

    int cnt = 0;
    for (int w: neighs) {
      if (w == v) continue;
      if (!binary_search(edges[v].begin(), edges[v].end(), w)) break;
      ++cnt;
    }
 
    if (cnt != k-2) {
      ret = false;
      break;
    }
  }
 
  return ret;
}
 
int solve() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < n; ++i) edges[i].clear();
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
 
  removeDegLessK(k);
 
  vector<int> v;
  for (int i = 0; i < n; ++i) {
    if (!removed[i]) v.push_back(i);
  }
  if (v.size() > 0) {
    printf("1 %d\n", (int) v.size());
    for (int u: v) printf("%d ", u+1);
    printf("\n");
    return 0;
  }
 
  removeDegLessK(k-1);
  sortAndCleanList();
 
  int front = 0, tail = 0;
  for (int i = 0; i < n; ++i) {
    if (removed[i]) continue;
    if (deg[i] == k-1) {
      q[tail++] = i;
    }
  }
 
  while (front < tail) {
    int u = q[front++];
 
    if (removed[u]) continue;
 
    if (isClique(u, k)) {
      printf("2\n");
      for (int v: edges[u]) if (!removed[v]) {
        printf("%d ", v+1);
      }
      printf("%d\n", u+1);
      return 0;
    }
 
    removed[u] = true;
    for (int v: edges[u]) {
      if (removed[v]) continue;
      if (--deg[v] == k-1) q[tail++] = v;
    }
  }
 
  printf("-1\n");
  return 0;
}
 
int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}