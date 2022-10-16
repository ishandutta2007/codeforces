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

const int maxn = 512345;

int par[maxn], in[maxn * 2], out[maxn * 2];
int L[maxn], R[maxn];
int n;

int Find(int x) {
  return par[x] == x ? x : par[x] = Find(par[x]);
}

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) {
    scanf("%d%d", L + i, R + i);
    in[L[i]] = i, out[R[i]] = i;
  }
  iota(par + 1, par + n + 1, 1);
  set<pii> now;
  FOR(i, 1, 2 * n) {
    if (in[i]) now.emplace(i, in[i]);
    if (out[i]) {
      int j = out[i];
      now.erase(mp(L[j], j));
      for (auto it = now.lower_bound(mp(L[j], 0)); it != now.end(); ++it) {
        int u = Find(it->_2), v = Find(j);
        if (u == v) {
          puts("NO");
          return 0;
        }
        par[u] = v;
      }
    }
  }
  FOR(i, 1, n) if (Find(i) != Find(1)) {
    puts("NO");
    return 0;
  }
  puts("YES");
}