#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int B = 555, N = 300005;
int t, n, m, x, k[N];
int pre[N], pos[N];
vector<int> a[N], b[N];
int main() {
  cin >> t;
  while (t--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
      scanf("%d", k + i);
      a[i].resize(k[i]);
      for (int j = 0; j < k[i]; j++) {
        scanf("%d", &a[i][j]);
        if (k[i] < B) b[a[i][j]].push_back(i);
      }
    }
    bool ok = 1;
    for (int i = 1; i <= m && ok; i++) {
      if (k[i] < B) continue;
      memset(pre, 0, (n + 1) << 2), memset(pos, 0x3f, (n + 1) << 2);
      for (int j = 0; j < k[i]; j++) pos[a[i][j]] = j;
      for (int j = 1; j < k[i]; j++) pre[a[i][j]] = a[i][j - 1];
      for (int z = 1; z <= m && ok; z++) {
        if (z >= i && k[z] >= B) continue;
        int tp = pos[a[z][0]];
        for (int j = 1; j < k[z]; j++) {
          int x = a[z][j];
          if (pre[x] && pre[x] != a[z][j - 1] && tp < pos[x]) {
            ok = 0;
            break;
          }
          if (pos[x] < tp) tp = pos[x];
        }
      }
    }
    memset(pre, 0, (n + 1) << 2);
    for (int i = 1; i <= n && ok; i++) {
      for (int z : b[i])
        for (int j = k[z] - 1; a[z][j] != i; j--) {
          int x = a[z][j], y = a[z][j - 1];
          if (pre[x] && pre[x] != y) {
            ok = 0;
            break;
          }
          pre[x] = y;
        }
      for (int z : b[i])
        for (int j = k[z] - 1; a[z][j] != i; j--)
          pre[a[z][j]] = 0;
    }
    puts(ok ? "Robot" : "Human");
    for (int i = 1; i <= n; i++) b[i].clear();
  }
}