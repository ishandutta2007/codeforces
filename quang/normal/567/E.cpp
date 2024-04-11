#include <bits/stdc++.h>

using namespace std;

const int N = 100010, MOD1 = 19038127, MOD2 = 94821307;
typedef unsigned long long ull;

int n, m, s, t;
vector <pair<int, int> > a[2][N], pos;
long long d[2][N];
int used[N];
long long c[2][N], C[2][N];

void go(int x, int s, int t) {
  for (int i = 1; i <= n; i++) {
    d[x][i] = 1e17;
    c[x][i] = 0;
    C[x][i] = 0;
    used[i] = 0;
  }
  c[x][s] = 1;
  C[x][s] = 1;
  d[x][s] = 0;
  priority_queue <pair<long long, int> > p;
  p.push(make_pair(0, s));
  while (!p.empty()) {
    int u = p.top().second;
    p.pop();
    if (used[u]) {
      continue;
    }
    used[u] = 1;
    for (int i = 0; i < a[x][u].size(); i++) {
      int v = a[x][u][i].first;
      long long len = a[x][u][i].second;
      if (d[x][v] == d[x][u] + len) {
        (c[x][v] += c[x][u]) %= MOD1;
        (C[x][v] += C[x][u]) %= MOD2;
      }
      if (d[x][v] > d[x][u] + len) {
        d[x][v] = d[x][u] + len;
        c[x][v] = c[x][u];
        C[x][v] = C[x][u];
        p.push(make_pair(-d[x][v], v));
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  #ifdef Doflamingo
  freopen("input", "r", stdin);
  #endif // Doflamingo
  cin >> n >> m >> s >> t;
  for (int i = 1; i <= m; i++) {
    int u, v, l;
    cin >> u >> v >> l;
    pos.push_back(make_pair(u, a[0][u].size()));
    a[0][u].push_back(make_pair(v, l));
    a[1][v].push_back(make_pair(u, l));
  }
  go(0, s, t);
  go(1, t, s);
  for (int i = 0; i < m; i++) {
    int u = pos[i].first;
    int v = a[0][u][pos[i].second].first;
    long long len = a[0][u][pos[i].second].second;
    long long l = d[0][u] + d[1][v];
    if ((c[0][u] * c[1][v]) % MOD1 == c[0][t] && d[0][t] == l + len && (C[0][u] * C[1][v]) % MOD2 == C[0][t]) {
      cout << "YES\n";
      continue;
    }
    l = d[0][t] - l - 1;
    if (l < 1 || l >= len) {
      cout << "NO\n";
      continue;
    }
    cout << "CAN " << len - l << endl;
  }
  return 0;
}