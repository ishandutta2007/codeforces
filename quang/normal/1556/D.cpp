#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int LOG = 30;

int n, k;
vector<int> adj[LOG][N];
int val[LOG][N];
int a[N];
bool used[LOG][N];

void Dfs(int id, int u) {
  used[id][u] = 1;
  for (int v : adj[id][u]) {
    if (used[id][v] || val[id][v] != -1) continue;
    val[id][v] = val[id][u] ^ 1;
    Dfs(id, v);
  }
}

int32_t main() {
  cin >> n >> k;
  memset(val, -1, sizeof val);

  auto Ask = [&](int u, int v) {
    cout << "or " << u << ' ' << v << endl;
    int or_val;
    cin >> or_val;
    cout << "and " << u << ' ' << v << endl;
    int and_val;
    cin >> and_val;
    for (int i = 0; i < LOG; i++) {
      int or_i = (or_val >> i & 1);
      int and_i = (and_val >> i & 1);
      if (or_i != and_i) {
        adj[i][u].push_back(v);
        adj[i][v].push_back(u);
      } else {
        val[i][u] = val[i][v] = or_i;
      }
    }
  };

  for (int i = 1; i < n; i++) {
    Ask(i, i + 1);
  }
  Ask(1, 3);
  for (int i = 0; i < LOG; i++) {
    for (int j = 1; j <= n; j++) {
      if (!used[i][j] && val[i][j] != -1) {
        Dfs(i, j);
      }
    }
  }

  for (int i = 0; i < LOG; i++) {
    for (int j = 1; j <= n; j++) {
      assert(val[i][j] != -1);
      if (val[i][j]) a[j] |= (1 << i);
    }
  }
  sort(a + 1, a + n + 1);
  cout << "finish " << a[k] << endl;
  return 0;
}