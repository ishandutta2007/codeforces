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

void solve() {
  int n, T, a, b;
  scanf("%d%d%d%d", &n, &T, &a, &b);
  vector<pii> problems(n);
  REP(i, n) scanf("%d", &problems[i]._2);
  REP(i, n) scanf("%d", &problems[i]._1);
  sort(all(problems));
  vector<ll> required(n);
  vector<int> clk(n + 1), have(n + 1);
  REP(i, n) {
    if (i) required[i] = required[i - 1];
    required[i] += problems[i]._2 ? b : a;
  }
  ROF(i, n - 1, 0) have[i] = have[i + 1] + (problems[i]._2 == 0);
  REP(i, n) clk[i] = problems[i]._1 - 1;
  clk.back() = T;
  sort(all(clk)); uni(clk);
  int ans = 0, j = 0;
  REP(i, int(clk.size())) {
    if (clk[i] > T) break;
    while (j < n && problems[j]._1 <= clk[i]) j++;
    if (j && required[j - 1] > clk[i]) continue;
    int now = j, left = clk[i] - (j ? required[j - 1] : 0);
//    cerr << clk[i] << ' ' << now << ' ' << left << endl;
    if (left <= have[j] * ll(a)) {
      now += left / a;
      left = 0;
    } else {
      now += have[j];
      left -= have[j] * a;
    }
    now += left / b;
    chkmin(now, n);
    chkmax(ans, now);
  }
  printf("%d\n", ans);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}