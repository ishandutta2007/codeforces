#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define reset(a,b) memset(a, b, sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl;
#define BUGP(x) cout << #x << " = " << x._1 << ", " << x._2 << endl;
#define pb push_back
#define _1 first
#define _2 second
#define PR(x,a,b) { cout << #x << " = "; FOR(_,a,b) cout << x[_] << ' '; cout << endl; }
#define CON(x) { cout << #x << " = "; for (auto i: x) cout << i << ' '; cout << endl; }
#define eps 1e-9
#define sqr(x) ((x) * (x))
#define all(x) x.begin(), x.end()
#define mod 1000000007

int t, n, m, k, cnt[26], dp[200500], dp2[30004];
string s;

int main() {
  ios::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    reset(cnt, 0);
    cin >> n >> m >> k >> s;
    for (auto c: s) cnt[c - 'A']++;
    reset(dp, 0);
    dp[0] = 1;
    REP (i, 26) FORD (j, k - m, cnt[i]) dp[j] = max(dp[j], dp[j - cnt[i]]);
    bool flag = false;
    FOR (i, n, k - m) if (dp[i]) flag = true;
    if (flag) {
      cout << 0 << endl;
      continue;
    }

    long long ans = (1LL << 55);
    REP (ii, 26) {
      reset(dp2, 0);
      dp2[0] = 1;
      REP (i, 26) if (i != ii) FORD (j, n, cnt[i]) dp2[j] = max(dp2[j], dp2[j - cnt[i]]);
      FOR (len, max(0, n - cnt[ii]), n) if (dp2[len]) {
        ans = min(ans, 1LL * (n - len) * (len + cnt[ii] + m - k));
      }
    }

    cout << ans << endl;
  }
}