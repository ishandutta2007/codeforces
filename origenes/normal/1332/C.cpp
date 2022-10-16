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

char s[maxn];
int n, k;

void solve() {
  scanf("%d%d", &n, &k);
  scanf("%s", s);
  vector<vector<int>> cnt((k + 1) / 2, vector<int>(26));
  REP(i, n) {
    int idx = min(i % k, k - 1 - i % k);
    cnt[idx][s[i] - 'a']++;
  }
  int ans = 0;
  REP(i, (k + 1) / 2) {
    int sum = accumulate(all(cnt[i]), 0), now = sum;
    REP(j, 26) chkmin(now, sum - cnt[i][j]);
    ans += now;
  }
  printf("%d\n", ans);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}