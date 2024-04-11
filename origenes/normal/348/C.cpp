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
const int sz = 320;

int n, m, q, heavy;
int id[maxn], cnt[maxn][sz + 5];
ll ans[sz + 5], buff[sz + 5], a[maxn];
vector<int> s[maxn];
char op[5];

int main() {
  scanf("%d%d%d", &n, &m, &q);
  FOR(i, 1, n) scanf("%lld", a + i);
  FOR(i, 1, m) {
    int k;
    scanf("%d", &k);
    if (k >= sz) id[i] = ++heavy;
    s[i].resize(k);
    for (auto &x : s[i]) scanf("%d", &x);
  }
  FOR(i, 1, m) if (id[i]) {
    vector<char> vis(n + 5);
    for (auto x : s[i]) {
      vis[x] = 1;
      ans[id[i]] += a[x];
    }
    FOR(j, 1, m) for (auto x : s[j]) cnt[j][id[i]] += vis[x];
  }
  while (q--) {
    scanf("%s", op);
    if (op[0] == '?') {
      int k;
      scanf("%d", &k);
      if (id[k]) printf("%lld\n", ans[id[k]]);
      else {
        ll res = 0;
        FOR(i, 1, heavy) res += buff[i] * cnt[k][i];
        for (auto x : s[k]) res += a[x];
        printf("%lld\n", res);
      }
    } else {
      int k, x;
      scanf("%d%d", &k, &x);
      FOR(i, 1, heavy) ans[i] += x * ll(cnt[k][i]);
      if (id[k]) buff[id[k]] += x;
      else for (auto i : s[k]) a[i] += x;
    }
  }
}