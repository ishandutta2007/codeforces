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

int L[maxn], R[maxn], n;

void solve() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", L + i);
  FOR(i, 1, n) scanf("%d", R + i);
  FOR(i, 1, n) if (L[i] == 2) L[i] = -1;
  FOR(i, 1, n) if (R[i] == 2) R[i] = -1;
  FOR(i, 1, n) L[i] = L[i - 1] + L[i];
  reverse(R + 1, R + n + 1);
  FOR(i, 1, n) R[i] = R[i - 1] + R[i];
  map<int, int> last;
  last[0] = 0;
  FOR(i, 1, n) last[R[i]] = i;
  int ans = 0;
  REP(i, n + 1) if (last.count(-L[i])) chkmax(ans, i + last[-L[i]]);
  printf("%d\n", 2 * n - ans);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}