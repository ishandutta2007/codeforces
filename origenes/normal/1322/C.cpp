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
const int M1 = 1e9 + 7;
const int M2 = 998244353;

int n, m;
ll c[maxn];
vector<int> G[maxn];

void solve() {
  scanf("%d%d", &n, &m);
  REP(i, n) G[i].clear();
  REP(i, n) scanf("%lld", c + i);
  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    G[v].eb(u);
  }
  map<pair<pii, int>, vector<int>> hash;
  REP(i, n) {
    sort(all(G[i]));
    ll h1 = 0, h2 = 0;
    for (auto v : G[i]) {
      h1 = (h1 * n + v) % M1;
      h2 = (h2 * n + v) % M2;
    }
    hash[mp(mp(h1, h2), G[i].size())].eb(i);
  }
  ll ans = 0;
  for (auto [h, v] : hash) if (h._2) {
    ll now = 0;
    for (auto i : v) now += c[i];
    ans = gcd(ans, now);
  }
  printf("%lld\n", ans);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}