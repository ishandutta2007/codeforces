#include <bits/stdc++.h>

#define Task "D"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

const int N = 100100;
typedef pair<int, int> pi;

int n, m, d;
int dd[N];
vector <int> a[N];

struct node {
  pi F, S;
  node(pi _F = pi(0, 0), pi _S = pi(0, 0)) {
    F = _F;
    S = _S;
  }
  void Set(pi foo) {
    if (foo > F) {
      swap(foo, F);
    }
    if (foo > S) {
      swap(foo, S);
    }
  }
} b[N];

void DFS(int u, int p) {
  for (int i = 0; i < a[u].size(); i++) {
    int v = a[u][i];
    if (v == p) {
      continue;
    }
    DFS(v, u);
    if (!dd[v] && !b[v].F.first) {
      continue;
    }
    b[u].Set(pi(b[v].F.first + 1, v));
  }
}

void ReDFS(int u, int p) {
  for (int i = 0; i < a[u].size(); i++) {
    int v = a[u][i];
    if (v == p) {
      continue;
    }
    if (b[u].F.second == v) {
      if (b[u].S.first || dd[u]) {
        b[v].Set(pi(b[u].S.first + 1, u));
      }
    } else {
      if (b[u].F.first || dd[u]) {
        b[v].Set(pi(b[u].F.first + 1, u));
      }
    }
    ReDFS(v, u);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
 // fi, fo;
  cin >> n >> m >> d;
  for (int i = 1; i <= m; i++) {
    int u;
    cin >> u;
    dd[u] = 1;
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    a[u].push_back(v);
    a[v].push_back(u);
  }
  DFS(1, 0);
  ReDFS(1, 0);
  int res = 0;
  for (int i = 1; i <= n; i++) {
    res += (b[i].F.first <= d);
  }
  cout << res;
  return 0;
}