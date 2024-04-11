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

const int maxn = 70001;

bitset<maxn> dp[2];
int a[maxn], id[maxn], n, s, rec[maxn], c[maxn];
bool vis[maxn];
vector<int> G[maxn];

int main() {
  scanf("%d%d", &n, &s);
  FOR(i, 1, n) {
    scanf("%d", a + i);
    id[i] = i;
  }
  sort(id + 1, id + n + 1, [](int i, int j) { return a[i] > a[j]; });
  if (a[id[1]] > s) {
    puts("-1");
    return 0;
  }
  dp[0].set(0);
  FOR(i, 1, n) {
    int now = i & 1, pre = 1 - now;
    dp[now] = dp[pre] | (dp[pre] << a[id[i]]);
    auto diff = dp[now] ^ dp[pre];
    if (diff.any())
      for (auto j = diff._Find_first(); j < diff.size(); j = diff._Find_next(j)) rec[j] = i;
  }
  if (!dp[n & 1][s]) {
    puts("-1");
    return 0;
  }
  for (int i = s; i > 0; i -= a[id[rec[i]]]) {
    vis[id[rec[i]]] = true;
    c[id[rec[i]]] = a[id[rec[i]]];
  }
  if (!vis[id[1]]) {
    puts("-1");
    return 0;
  }
  int now = id[1];
  FOR(i, 2, n) if (!vis[id[i]]) {
      G[now].eb(id[i]);
      c[now] -= a[id[i]];
      c[id[i]] = a[id[i]];
      now = id[i];
    }
  FOR(i, 1, n) {
    printf("%d %d", c[i], int(G[i].size()));
    for (int v : G[i]) printf(" %d", v);
    puts("");
  }
}