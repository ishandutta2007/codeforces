#include <bits/stdc++.h>

#define Task "C"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

int n, m, k;
int pos[100100], a[100100];

int main() {
  ios_base::sync_with_stdio(0);
 // fi, fo;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    int u;
    cin >> u;
    pos[u] = i;
    a[i] = u;
  }
  long long res= 0 ;
  while (m--) {
    int u;
    cin >> u;
    int x = pos[u];
    res += (int)(x / k) + 1;
    if (pos[u]) {
      int v = a[pos[u] - 1];
      swap (pos[u], pos[v]);
      swap (a[pos[u]], a[pos[v]]);
    }
  }
  cout << res;
  return 0;
}