#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 505;
const int M = 1e4 + 123;
const int K = 2e4 + 123;

int n, m, k;
pair<int, int> edges[M];
int prefix[M][N];
int suffix[M][N];
int q[K][N];

int get(int *dsu, int v) {
  if (dsu[v] == v) {
    return v;
  }
  
  return dsu[v] = get(dsu, dsu[v]);
}

void unite(int *dsu, int u, int v) {
  u = get(dsu, u);
  v = get(dsu, v);
  
  if (u == v) {
    return;
  }
  
  dsu[u] = v;
}

void merge(int *a, int *b, int *to) {
  copy(a, a + n, to);
  
  for (int i = 0; i < n; i++) {
    int v = i;
    while (v != b[v]) {
      unite(to, v, b[v]);
      v = b[v];
    }
  }
}

bool tmp[N];

int calc(int *dsu) {
  fill(tmp, tmp + n, 0);
  
  for (int i = 0; i < n; i++) {
    tmp[get(dsu, i)] = 1;
  }
  
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += tmp[i];
  }
  
  return ans;
}

int main() {
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif
  
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--; y--;
    edges[i] = {x, y};
  }
  
  for (int i = 0; i < n; i++) {
    prefix[0][i] = i;
    suffix[m + 1][i] = i;
  }
  
  for (int i = 1; i <= m; i++) {
    copy(prefix[i - 1], prefix[i - 1] + n, prefix[i]);
    unite(prefix[i], edges[i - 1].first, edges[i - 1].second);
  }
  
  for (int i = m; i >= 1; i--) {
    copy(suffix[i + 1], suffix[i + 1] + n, suffix[i]);
    unite(suffix[i], edges[i - 1].first, edges[i - 1].second);
  }
  
  scanf("%d", &k);
  
  for (int i = 0; i < k; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    
    merge(prefix[l - 1], suffix[r + 1], q[i]);
    printf("%d\n", calc(q[i]));
  }
  
  return 0;
}