#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1e7 + 1;
const int INF = 1e18;

int factor[MAXN];

void sieve() {
  for (int i = 0; i < MAXN; ++i)
    factor[i] = -1;

  for (int p = 2; p < MAXN; ++p)
    if (factor[p] == -1) {
      for (int i = p; i < MAXN; i += p)
        factor[i] = p;
    }
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbPaires;
  cin >> nbPaires;

  sieve();

  for (int iPaire = 0; iPaire < nbPaires; ++iPaire) {
    int x, y;
    cin >> x >> y;
    int diff = y - x;
    int sol = INF;
    while (diff > 1) {
      int p = factor[diff];
      diff /= p;
      int m = y % p;
      if (!m)
        sol = 0;
      else
        sol = min(sol, p - m);
    }
    if (sol == INF)
      sol = -1;
    cout << sol << '\n';
  }
}