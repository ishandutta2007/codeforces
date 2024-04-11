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

const int maxn = 112345;

int n, m, q;
int out[maxn];
vector<int> in[maxn];

int main() {
  scanf("%d%d", &n, &m);
  REP(i, m) {
    int u, v;
    scanf("%d%d", &u, &v);
    if (u < v) swap(u, v);
    out[u]++;
    in[v].eb(u);
  }
  ll ans = 0;
  FOR(i, 1, n) ans += out[i] * ll(in[i].size());
  printf("%lld\n", ans);
  scanf("%d", &q);
  while (q--) {
    int u;
    scanf("%d", &u);
    ans -= out[u] * ll(in[u].size());
    for (auto v : in[u]) {
      ans -= out[v] * ll(in[v].size());
      out[v]--;
      in[v].eb(u);
      out[u]++;
      ans += out[v] * ll(in[v].size());
    }
    in[u].clear();
    printf("%lld\n", ans);
  }
}