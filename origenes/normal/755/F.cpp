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

const int maxn = 1123456;

bitset<maxn> dp;
bool vis[maxn];
int p[maxn], w[maxn], have[maxn], val[maxn];
int n, k, tot, tt, mmax;

int main() {
  scanf("%d%d", &n, &k);
  FOR(i, 1, n) scanf("%d", p + i);
  FOR(i, 1, n) {
    int now = i, cnt = 0;
    while (!vis[now]) {
      vis[now] = true;
      now = p[now];
      cnt++;
    }
    if (cnt) {
      if (!have[cnt]) w[++tot] = cnt;
      have[cnt]++;
    }
  }
  FOR(i, 1, tot) mmax += w[i] / 2 * have[w[i]];
  if (mmax >= k) mmax = 2 * k;
  else mmax += k;
  chkmin(mmax, n);
  FOR(i, 1, tot) {
    for (int j = 1; j <= have[w[i]]; j <<= 1) {
      val[++tt] = j * w[i];
      have[w[i]] -= j;
    }
    if (have[w[i]] > 0) val[++tt] = have[w[i]] * w[i];
  }
  dp.set(0);
  FOR(i, 1, tt) dp |= dp << val[i];
  if (dp[k]) printf("%d %d", k, mmax);
  else printf("%d %d", k + 1, mmax);
}