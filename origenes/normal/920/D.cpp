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

const int maxn = 5123;

int a[maxn], n, k, V, s, pre[maxn][maxn];
bool dp[maxn][maxn];

int main() {
  scanf("%d%d%d", &n, &k, &V);
  FOR(i, 1, n) {
    scanf("%d", a + i);
    s += a[i];
  }
  if (s < V) {
    puts("NO");
    return 0;
  }
  int need = V % k;
  dp[0][0] = true;
  REP(i, n) REP(j, k) if (dp[i][j]) {
        if (!dp[i + 1][j]) {
          dp[i + 1][j] = true;
          pre[i + 1][j] = j;
        }
        if (!dp[i + 1][(j + a[i + 1]) % k]) {
          dp[i + 1][(j + a[i + 1]) % k] = true;
          pre[i + 1][(j + a[i + 1]) % k] = j;
        }
      }
  if (!dp[n][need]) {
    puts("NO");
    return 0;
  }
  puts("YES");
  set<int> s[2];
  int now = need;
  ROF(i, n, 1) {
    if (pre[i][now] == now) s[1].insert(i);
    else s[0].insert(i);
    now = pre[i][now];
  }
  if (s[0].empty()) {
    FOR(i, 2, n) if (a[i]) printf("%d %d 1\n", (a[i] + k - 1) / k, i);
    if (V) printf("%d 1 2\n", V / k);
  } else {
    int ss = *s[0].begin(), have = a[ss];
    for (auto it : s[0]) if (it != ss) {
        if (a[it]) printf("%d %d %d\n", (a[it] + k - 1) / k, it, ss);
        have += a[it];
      }
    if (have == V) return 0;
    if (have > V) {
      int to = ss == 1 ? 2 : 1;
      printf("%d %d %d\n", (have - V) / k, ss, to);
    } else {
      int tt = *s[1].begin();
      for (auto it : s[1]) if (it != tt)
          if (a[it]) printf("%d %d %d\n", (a[it] + k - 1) / k, it, tt);
      printf("%d %d %d\n", (V - have) / k, tt, ss);
    }
  }
}