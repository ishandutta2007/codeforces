#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int N = 200005;
int n, m, a[N], b[N], c[N];
int fa[N << 1];
bool gu[N];
vector<pair<int, int>> to[N];

int find(int x) {
  while (x != fa[x])
    x = fa[x] = fa[fa[x]];
  return x;
}

void merge(int x, int y) {
  x = find(x), y = find(y);
  fa[min(x, y)] = max(x, y);
}

void dfs(int i, int fa) {
  for (auto tp : to[i]) {
    int j = tp.first;
    if (j == fa)
      continue;

    cout << i << ' ' << j << ' ';
    if (tp.second == -1)
      cout << (gu[i] ^ gu[j]);
    else
      cout << tp.second;
    cout << '\n';

    dfs(j, i);
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 1; i <= 2 * n; i++)
      fa[i] = i;
    for (int i = 1; i < n; i++) {
      int x, y, z;
      cin >> x >> y >> z;
      to[x].push_back(make_pair(y, z)), to[y].push_back(make_pair(x, z));
      a[i] = x, b[i] = y, c[i] = z;
      if (z != -1) {
        bool op = __builtin_parity(z);
        if (op)
          merge(x, n + y), merge(n + x, y);
        else
          merge(x, y), merge(n + x, n + y);
      }
    }

    while (m--) {
      int x, y, z;
      cin >> x >> y >> z;
      if (z)
        merge(x, n + y), merge(n + x, y);
      else
        merge(x, y), merge(n + x, n + y);
    }

    bool ok = 1;
    for (int i = 1; i <= n; i++)
      if (find(i) == find(n + i)) {
        ok = 0;
        break;
      }

    if (!ok) {
      for (int i = 1; i <= n; i++)
        to[i].clear();
      cout << "NO\n";
      continue;
    }

    for (int i = 1; i <= n; i++)
      if (find(i) != find(1) && find(n + i) != find(1))
        merge(i, 1), merge(n + 1, n + i);

    for (int i = 1; i <= n; i++)
      gu[i] = find(i) == find(1);

    cout << "YES\n";
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
      to[i].clear();
  }
}