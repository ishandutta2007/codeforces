#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint INF = 1e18;

void Solve(int N, vector<pair<int, int>> A) {
  vector<pair<int, int>> ans;
  assert(A.size() == N);
  vector<vector<int>> adj(2 * N);
  for (int i = 0; i < int(A.size()); i++) {
    int u = A[i].first, v = A[i].second;
    adj[u].emplace_back(i);
    adj[v].emplace_back(i);
  }

  vector<int> used(N);
  vector<int> vis(2 * N);
  const auto Dfs = [&](const auto &self, int u, int p, int laste) -> bool {
    int last = -1;
    const auto Update = [&](int e) {
      used[e] = 1;
      if (last != -1) {
        ans.emplace_back(last, e);
        last = -1;
      } else {
        last = e;
      }
    };
    vis[u] = 1;
    for (auto e : adj[u]) {
      int v = u ^ A[e].first ^ A[e].second;
      if (used[e]) continue;
      if (v == p) continue;
      if (!vis[v]) {
        if (self(self, v, u, e)) {
          Update(e);
        }
      } else {
        Update(e);
      }
    }
    if (last != -1 && laste != -1) {
      Update(laste);
      return false;
    }
    return true;
  };
  for (int i = 0; i < 2 * N; i++) if (!vis[i]) Dfs(Dfs, i, -1, -1);

  cout << ans.size() << '\n';
  for (auto [x, y] : ans) {
    cout << x + 1 << ' ' << y + 1 << '\n';
  }
}

void Main() {
  int N;
  cin >> N;
  vector<lint> A(N), B(N), C(N), D(N);

  for (int i = 0; i < N; i++) {
    cin >> A[i] >> B[i] >> C[i] >> D[i];
    lint g = __gcd(A[i], B[i]); A[i] /= g; B[i] /= g;
    g = __gcd(C[i], D[i]); C[i] /= g; D[i] /= g;
  }

  // A / B + 1, C / D = (A + B) / B
  vector<lint> done(N);
  map<pair<lint, lint>, vector<pair<lint, lint>>> slope;
  vector<pair<lint, lint>> coords;
  const auto AddPoint = [&](lint a, lint b, lint c, lint d, lint i, lint occ) {
    lint up = a * d;
    lint dn = b * c;
    lint g = __gcd(up, dn);
    up /= g; dn /= g;
    slope[{up, dn}].emplace_back(i, occ);
    coords.emplace_back(up, dn);
  };

  const auto Get = [&](lint a, lint b, lint c, lint d, lint i, lint occ) {
    lint up = a * d;
    lint dn = b * c;
    lint g = __gcd(up, dn);
    up /= g; dn /= g;

    pair<lint, lint> p = pair(up, dn);
    auto it = lower_bound(begin(coords), end(coords), p) - begin(coords);
    return it;
  };

  for (int i = 0; i < N; i++) {
    auto [a, b, c, d] = tuple(A[i], B[i], C[i], D[i]);
    AddPoint(a + b, b, c, d, i, 1);
    AddPoint(a, b, c + d, d, i, 0);
  }

  sort(begin(coords), end(coords));
  coords.resize(unique(begin(coords), end(coords)) - begin(coords));

  vector<pair<int, int>> pick(N);
  for (int i = 0; i < N; i++) {
    auto [a, b, c, d] = tuple(A[i], B[i], C[i], D[i]);
    pick[i].first = Get(a + b, b, c, d, i, 1);
    pick[i].second = Get(a, b, c + d, d, i, 0);
  }

  Solve(N, pick);

}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  // cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}