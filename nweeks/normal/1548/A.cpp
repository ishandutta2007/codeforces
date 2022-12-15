#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int nbPersonnes, nbAmities;
  cin >> nbPersonnes >> nbAmities;
  int nbCC = nbPersonnes;
  vector<int> deg(nbPersonnes);
  int nbNonNuls = 0;
  while (nbAmities--) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    if (x > y)
      swap(x, y);
    if (!deg[x])
      nbNonNuls++;
    deg[x]++;
  }

  int q;
  cin >> q;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      if (u > v)
        swap(u, v);
      if (!deg[u])
        nbNonNuls++;
      deg[u]++;
    } else if (t == 2) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      if (u > v)
        swap(u, v);
      if (deg[u] == 1)
        nbNonNuls--;
      deg[u]--;
    } else {
      cout << nbPersonnes - nbNonNuls << '\n';
    }
  }
}