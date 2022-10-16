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
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 312345;

set<int> G[maxn];
int n, k, deg[maxn], tot;

int check(int n) {
  int ret = 0;
  FOR(i, 1, n) ret += n / i - 1;
  return ret;
}

int main() {
  scanf("%d%d", &n, &k);
  if (check(n) < k) {
    puts("No");
    return 0;
  }
  int lo = 1, hi = n;
  while (lo < hi) {
    int mi = lo + hi >> 1;
    if (check(mi) >= k) hi = mi;
    else lo = mi + 1;
  }
  n = lo;
  puts("Yes");
  if (n < 1000) {
    FOR(i, 1, n) for (int j = i * 2; j <= n; j += i) {
      G[j].emplace(i);
      G[i].emplace(j);
      deg[i]++, deg[j]++;
      tot++;
    }
    auto cmp = [](int a, int b) { return deg[a] < deg[b] || (deg[a] == deg[b] && a < b); };
    set<int, decltype(cmp)> q(cmp);
    FOR(i, 1, n) q.emplace(i);
    deg[n + 5] = tot - k;
    int &need = deg[n + 5];
    int now = n + 5;
    while (need && !q.empty()) {
      auto it = q.upper_bound(now);
      it--;
      for (auto v : G[*it])
        if (q.count(v)) {
          deg[v]--;
          G[v].erase(*it);
        }
      need -= deg[*it];
      q.erase(it);
    }
    printf("%d\n", int(q.size()));
    for (auto it : q) printf("%d ", it);
  } else {
    tot = check(n);
    int need = tot - k;
    vector<bool> vis(n + 1, false);
    FOR(i, 2, n) if (!vis[i])
      for (ll j = ll(i) * i; j <= n; j += i) vis[j] = true;
    vector<int> ans;
    int br;
    if (need) {
      ROF(i, n, n / 2 + 1) {
        if (!vis[i]) {
          need--;
          if (!need) {
            br = i - 1;
            break;
          }
        }
      }
    } else br = n;
    assert(need == 0);
    printf("%d\n", n - tot + k);
    FOR(i, 1, br) printf("%d ", i);
    FOR(i, br + 1, n) if (vis[i]) printf("%d ", i);
  }
}