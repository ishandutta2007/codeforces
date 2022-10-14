#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint INF = 1e18;

void Main() {
  lint N, M, L;
  cin >> N >> M >> L;

  vector<lint> dsu(N);
  iota(begin(dsu), end(dsu), 0);
  function<lint(lint)> Find = [&](lint x) {
    return dsu[x] == x ? x : dsu[x] = Find(dsu[x]);
  };

  vector<lint> A(N);
  for (lint i = 0; i < N; i++) cin >> A[i];
  vector<array<lint, 2>> e;
  vector<array<lint, 3>> edge;
  vector<lint> done(M);
  for (lint i = 0; i < M; i++) {
    lint u, v;
    cin >> u >> v;
    u--, v--;
    e.push_back({u, v});
    if (Find(u) != Find(v)) {
      dsu[Find(u)] = Find(v);
      edge.push_back({u, v, i});
    } else {
      done[i] = 1;
    }
  }

  if (edge.size() != N - 1) {
    cout << "NO\n";
    return;
  }

  if (accumulate(begin(A), end(A), 0ll) < 1ll * (N - 1) * L) {
    cout << "NO\n";
    return;
  }

  vector<set<pair<lint, lint>>> adj(N);
  for (auto [u, v, i] : edge) {
    adj[u].emplace(i, v);
    adj[v].emplace(i, u);
  }

  set<pair<lint, lint>> active;
  for (lint i = 0; i < N; i++) {
    active.emplace(A[i], i);
  }

  iota(begin(dsu), end(dsu), 0);
  vector<lint> ans;
  while (ans.size() < N - 1 && !active.empty()) {
    auto top = *prev(end(active)); 
    active.erase(prev(end(active)));
    if (top.first < L) break;

    lint u = top.second; assert(Find(u) == u);
    assert(!adj[u].empty());
    
    auto eid = *begin(adj[u]);    
    ans.emplace_back(eid.first);
    done[eid.first] = 1;

    lint v = eid.second; v = Find(v);

    adj[u].erase(adj[u].lower_bound({eid.first, -1}));
    adj[v].erase(adj[v].lower_bound({eid.first, -1}));
    active.erase({A[v], v});

    dsu[v] = u;
    A[u] = A[u] + A[v] - L;
    active.emplace(A[u], u);

    if (adj[u].size() < adj[v].size()) swap(adj[u], adj[v]);
    for (auto i : adj[v]) adj[u].emplace(i);    
    adj[v].clear();
  }

  int comps = 0;
  for (int i = 0; i < N; i++) if (Find(i) == i) comps++;
  for (int i = 0; i < M; i++) if (!done[i]) comps--;
  assert(comps == 1);

  for (int i = 0; i < M; i++) if (!done[i]) {
    ans.emplace_back(i);
    auto [u, v] = e[i];
    if (A[Find(u)] + A[Find(v)] < L) {
      cout << "NO\n";
      return;
    }
    assert(Find(u) != Find(v) && A[Find(u)] + A[Find(v)] >= L);
    A[Find(u)] += A[Find(v)] - L;
    dsu[Find(v)] = Find(u);
  }

  assert(ans.size() == N - 1);

  cout << "YES\n";
  for (auto i : ans) cout << i + 1 << '\n';
}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  lint T = 1;
  // cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}