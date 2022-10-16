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

const int maxn = 212345;

int n, q, have[maxn];
int a[maxn];
map<int, int> now[maxn];

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", a + i);
  ll ans = 0;
  FOR(i, 1, n) ans += a[i];
  scanf("%d", &q);
  while (q--) {
    int u, t, v;
    scanf("%d%d%d", &u, &t, &v);
    if (now[u].count(t)) {
      int w = now[u][t];
      have[w]--;
      if (have[w] < a[w]) ans++;
    }
    if (v) {
      now[u][t] = v;
      have[v]++;
      if (have[v] <= a[v]) ans--;
    } else now[u].erase(t);
    printf("%lld\n", ans);
  }
}