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

const int maxn = 112;
const int maxw = 11234;

char dp[maxn][maxn][maxw];
int n, cnt[maxn], s, pre[maxn], nxt[maxn];

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) {
    int a;
    scanf("%d", &a);
    cnt[a]++;
    s += a;
  }
  int last = 0;
  FOR(i, 1, 100) if (cnt[i]) {
    pre[i] = last;
    last = nxt[last] = i;
  }
  dp[0][0][0] = 1;
  for (int now = nxt[0]; now; now = nxt[now]) {
    REP(k, cnt[now] + 1) ROF(j, s, now * k) FOR(i, k, n) {
      dp[now][i][j] += dp[pre[now]][i - k][j - now * k];
      if (dp[now][i][j] >= 2) dp[now][i][j] = 2;
    }
  }
  int st = 0;
  ROF(i, 100, 1) if (cnt[i]) {
    st = i;
    break;
  }
  ROF(k, n, 1) FOR(j, 1, s) if (j % k == 0 && cnt[j / k] >= k && dp[st][k][j] == 1) {
    int now = j / k;
    if (k < n && cnt[now] == k) {
      int rem = s - k * now;
      if (dp[st][n - k][rem] == 1 && rem % (n - k) == 0 && cnt[rem / (n - k)] == n - k) {
        printf("%d", n);
        return 0;
      }
    }
    printf("%d", k);
    return 0;
  }
}