#include <bits/stdc++.h>
using namespace std;

const int PENALTY = 100005;
const int MAXN = 100005;

struct Edge {
  int u, v, w, id;
  Edge() {}
  Edge(int u, int v, int w, int id) : u(u), v(v), w(w), id(id) {}
};

template<int SZ>
struct DisjointSet {
  int p[SZ];
  int sz[SZ];
  
  int find(int x) {
    return p[x] == x ? x : p[x] = find(p[x]);
  }

  bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) {
      return false;
    }
    if (sz[x] > sz[y]) {
      swap(x, y);
    }
    p[y] = x;
    sz[x] += sz[y];
    return true;
  }

  void init() {
    iota(p, p + SZ, 0);
    fill(sz, sz + SZ, 1);
  }
};

int N, M, K;

int n[2] = {};
int mark[MAXN];
int ans[MAXN], ansPtr = 1;
Edge edge[2][MAXN];

void read() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> N >> M >> K;
  for (int i = 0; i < M; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    if (u > v) {
      swap(u, v);
    }
    if (u != 1) {
      edge[0][n[0]++] = Edge(u, v, w, i);
    } else {
      edge[1][n[1]++] = Edge(u, v, w, i);
    }
  }

  sort(edge[0], edge[0] + n[0], [&](Edge &a, Edge &b) { return a.w < b.w; });
  sort(edge[1], edge[1] + n[1], [&](Edge &a, Edge &b) { return a.w < b.w; });
}

DisjointSet<MAXN> d;

int trial(int lambda) {
  d.init();
  memset(mark, 0, sizeof(mark));

  int p[2] = {0, 0};
  int comp = N;
  int cnt = 0;
  while (comp > 1 && (p[0] < n[0] || p[1] < n[1])) {
    if (p[0] < n[0] && (p[1] == n[1] || edge[0][p[0]].w <= edge[1][p[1]].w + lambda)) {
      if (d.unite(edge[0][p[0]].u, edge[0][p[0]].v)) {
        comp--;
      }
      p[0]++;
    } 
    else if (p[1] < n[1] && (p[0] == n[0] || edge[1][p[1]].w + lambda < edge[0][p[0]].w)) {
      if (d.unite(edge[1][p[1]].u, edge[1][p[1]].v)) {
        comp--;
        cnt++;
        mark[edge[1][p[1]].id] = 1;
      }
      p[1]++;
    }
  }
  return cnt;
}

int need;

void trace(int lambda) {
  d.init();
  int p[2] = {0, 0};
  int comp = N;
  
  while (comp > 1 && (p[0] < n[0] || p[1] < n[1])) {
    if (p[0] < n[0] && p[1] < n[1] && edge[1][p[1]].w + lambda == edge[0][p[0]].w && need > 0 && mark[edge[1][p[1]].id] == 0) {
      if (d.unite(edge[1][p[1]].u, edge[1][p[1]].v)) {
        comp--;
        need--;
        ans[ansPtr++] = edge[1][p[1]].id;
      }
      p[0]++;
    }
    else if (p[0] < n[0] && (p[1] == n[1] || edge[0][p[0]].w <= edge[1][p[1]].w + lambda)) {
      if (d.unite(edge[0][p[0]].u, edge[0][p[0]].v)) {
        comp--;
        ans[ansPtr++] = edge[0][p[0]].id;
      }
      p[0]++;
    } 
    else if (p[1] < n[1] && (p[0] == n[0] || edge[1][p[1]].w + lambda < edge[0][p[0]].w)) {
      if (d.unite(edge[1][p[1]].u, edge[1][p[1]].v)) {
        comp--;
        ans[ansPtr++] = edge[1][p[1]].id;
      }
      p[1]++;
    }
  }
}

void solve() {
  if (trial(-PENALTY) < K || trial(PENALTY) > K) {
    cout << -1 << "\n";
    return;
  }

  int opt = PENALTY;
  for (int l = -PENALTY, r = PENALTY, mid = (l + r) >> 1; l <= r; mid = (l + r) >> 1) {
    int cnt = trial(mid);
    if (cnt <= K) {
      opt = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  memset(ans, -1, sizeof(ans));
  need = K - trial(opt);
  trace(opt);

  cout << N - 1 << "\n";
  sort(ans + 1, ans + N);
  for (int i = 1; i < N; i++) {
    cout << ans[i] + 1 << " \n"[i == N - 1];
  }
}

int main() {
  read();
  solve();
  return 0;
}