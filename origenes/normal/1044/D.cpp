#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

map<int, int> par, w;

int Find(int x) {
  if (!par.count(x)) return x;
  int p = Find(par[x]);
  w[x] ^= w[par[x]];
  return par[x] = p;
}

void Union(int u, int v, int x) {
  int pu = Find(u), pv = Find(v);
  if (pu == pv) return;
  par[pu] = pv;
  w[pu] = w[u] ^ w[v] ^ x;
}

int q, t, l, r, last, x;

int main() {
  scanf("%d", &q);
  while (q--) {
    scanf("%d", &t);
    if (t == 1) {
      scanf("%d%d%d", &l, &r, &x);
      l ^= last, r ^= last, x ^= last;
      if (l > r) swap(l, r);
      r++;
      Union(l, r, x);
    } else {
      scanf("%d%d", &l, &r);
      l ^= last, r ^= last;
      if (l > r) swap(l, r);
      r++;
      int ans = -1;
      if (Find(l) == Find(r)) ans = w[l] ^ w[r];
      printf("%d\n", ans);
      last = ans == -1 ? 1 : ans;
    }
  }
}