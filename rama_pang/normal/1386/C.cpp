#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAX = 6e5 + 5;

namespace LinkCut {
  struct Node {
    int ch[2] = {0, 0}, p = 0;
    int val = 0, mn = 0, sz = 0;
    bool flip = 0;
  };

  Node T[MAX];

  int GetSz(int x) {
    return x ? T[x].sz : 0;
  }

  int GetMn(int x) {
    return x ? T[x].mn : INF;
  }

  void Push(int x) {
    if (!x || !T[x].flip) return;
    T[x].flip = 0; swap(T[x].ch[0], T[x].ch[1]);
    T[T[x].ch[0]].flip ^= 1;
    T[T[x].ch[1]].flip ^= 1;
  }

  void Pull(int x) {
    if (!x) return;
    T[x].mn = min(T[x].val, min(GetMn(T[x].ch[0]), GetMn(T[x].ch[1])));
    T[x].sz = 1 + GetSz(T[x].ch[0]) + GetSz(T[x].ch[1]);
  }

  void Set(int x, int d, int y) {
    if (y) T[y].p = x;
    if (~d) T[x].ch[d] = y;
    Pull(x);
  }

  int Dir(int x) {
    int p = T[x].p; if (!p) return -1;
    return T[p].ch[0] == x ? 0 : T[p].ch[1] == x ? 1 : -1;
  }

  void Rot(int x) {
    int y = T[x].p, z = T[y].p;
    int dx = Dir(x), dy = Dir(y);
    Set(y, dx, T[x].ch[!dx]);
    Set(x, !dx, y);
    Set(z, dy, x);
  }

  void Splay(int x) {
    for (Push(x); ~Dir(x); ) {
      int y = T[x].p, z = T[y].p;
      Push(z); Push(y); Push(x);
      int dx = Dir(x), dy = Dir(y);
      if (~dy) Rot(dx == dy ? y : x);
      Rot(x);
    }
  }

  void Access(int x) {
    for (int u = x, prv = 0; u; prv = u, u = T[u].p) {
      Splay(u); Set(u, 1, prv);
    }
    Splay(x);
  }

  void Reroot(int x) {
    Access(x); T[x].flip ^= 1; Access(x);
  }

  void Link(int u, int v) {
    Reroot(u); Access(v); T[u].p = v;
  }

  void Cut(int u, int v) {
    Reroot(u); Access(v);
    T[u].p = T[v].ch[0] = 0; Pull(v);
  }

  int Lca(int u, int v) {
    if (u == v) return u;
    Access(u); Access(v);
    if (!T[u].p) return 0;
    Splay(u); return T[u].p ? : u;
  }

  bool Connected(int u, int v) {
    return Lca(u, v) != 0;
  }

  int Path(int u, int v) {
    Reroot(u); Access(v); return GetMn(v);
  }

  int Dist(int x, int y) {
    Reroot(x); Access(y); return GetSz(T[y].ch[0]);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  auto start = clock();

  int N, M, Q;
  cin >> N >> M >> Q;

  vector<pair<int, int>> edge(2 * M + 1);
  for (int i = 1; i <= M; i++) {
    cin >> edge[i].first >> edge[i].second;
    edge[i].first += 2 * M;
    edge[i].second += 2 * M;
    edge[i + M] = edge[i];
  }

  for (int i = 1; i <= 2 * M; i++) {
    LinkCut::T[i].val = i;
    LinkCut::Pull(i);
  }
  for (int i = 1; i <= N; i++) {
    LinkCut::T[2 * M + i].val = INF;
    LinkCut::Pull(2 * M + i);
  }

  vector<int> in(2 * M + 1);

  const auto Link = [&](int e) -> bool {
    auto [u, v] = edge[e];
    assert(!in[e]); in[e] = 1;
    LinkCut::Link(u, e); LinkCut::Link(v, e);
    return true;
  };

  const auto Cut = [&](int e) -> bool {
    auto [u, v] = edge[e];
    assert(in[e]); in[e] = 0;
    LinkCut::Cut(u, e); LinkCut::Cut(v, e);
    return true;
  };

  const auto AddEdge = [&](int e) -> bool {
    auto [u, v] = edge[e];
    if (!LinkCut::Connected(u, v)) return Link(e);
    if (LinkCut::Dist(u, v) % 4 == 0) return false; // u to v has even length, if we add (u, v) then there will be odd cycle
    int mn = LinkCut::Path(u, v); Cut(mn); return Link(e);
  };

  vector<int> ans(2 * M + 1, -1); // [x, ans[x]] is bipartite, ans[x] maximum
  for (int i = 1, j = 0; i <= 2 * M; i++) {
    while (j + 1 <= 2 * M && AddEdge(j + 1)) j += 1;
    if (in[i]) Cut(i);
    ans[i] = j;
  }

  while (Q--) {
    int l, r;
    cin >> l >> r;
    cout << (l + M - 1 <= ans[r + 1] ? "NO" : "YES") << '\n';
  }

  cerr << double(clock() - start) / CLOCKS_PER_SEC << " time\n";
  return 0;
}