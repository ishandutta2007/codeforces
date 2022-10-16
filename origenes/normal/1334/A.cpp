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

const int maxn = 112;

int n;
int p[maxn], c[maxn], dp[maxn], dc[maxn];

void solve() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d%d", p + i, c + i);
  FOR(i, 1, n) {
    dp[i] = p[i] - p[i - 1];
    dc[i] = c[i] - c[i - 1];
    if (dp[i] < 0 || dc[i] < 0 || dp[i] < dc[i]) {
      puts("NO");
      return;
    }
  }
  puts("YES");
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}