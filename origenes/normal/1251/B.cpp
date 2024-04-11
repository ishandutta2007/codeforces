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

const int maxn = 55;

int n;
char s[maxn][maxn];

void solve() {
  scanf("%d", &n);
  REP(i, n) scanf("%s", s[i]);
  int cnt[2] = {}, par[2] = {};
  REP(i, n) {
    int j;
    for (j = 0; s[i][j]; j++) cnt[s[i][j] - '0']++;
    par[j & 1]++;
  }
  int ans = n;
  if ((cnt[0] & 1) + (cnt[1] & 1) > par[1]) ans--;
  printf("%d\n", ans);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}