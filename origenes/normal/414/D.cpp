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

int n, k, p, dep[maxn], cnt[maxn];
vector<int> G[maxn];

void dfs(int u, int par) {
  dep[u] = dep[par] + 1;
  cnt[dep[u]]++;
  for (auto v : G[u]) if (v != par) dfs(v, u);
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> k >> p;
  REP(i, n - 1) {
    int u, v;
    cin >> u >> v;
    G[u].eb(v);
    G[v].eb(u);
  }
  dfs(1, 0);
  int ans = min(k, cnt[2]), have = ans, cost = 0, j = 2;
  FOR(i, 3, n) {
    cost += have;
    have += cnt[i];
    while (have > k) {
      if (k <= have - cnt[j]) {
        have -= cnt[j];
        cost -= (i - j) * cnt[j];
        j++;
        continue;
      }
      cnt[j] -= have - k;
      cost -= (i - j) * (have - k);
      have = k;
    }
    while (cost > p) {
      if (p <= cost - (i - j) * cnt[j]) {
        have -= cnt[j];
        cost -= (i - j) * cnt[j];
        j++;
        continue;
      }
      int extra = (cost - p + i - j - 1) / (i - j);
      have -= extra;
      cost -= (i - j) * extra;
      cnt[j] -= extra;
    }
    chkmax(ans, have);
  }
  cout << ans;
}