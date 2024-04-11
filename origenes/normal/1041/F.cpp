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

int n, m, ans = 2;
int a[maxn], b[maxn];

int main() {
  int y1, y2;
  scanf("%d%d", &n, &y1);
  FOR(i, 1, n) scanf("%d", a + i);
  scanf("%d%d", &m, &y2);
  FOR(i, 1, m) scanf("%d", b + i);
  for (ll d = 1; d <= 1e9; d <<= 1) {
    map<int, int> x;
    FOR(i, 1, n) x[a[i] % (2 * d)]++;
    FOR(i, 1, m) x[(b[i] + d) % (2 * d)]++;
    for (auto it : x) chkmax(ans, it._2);
  }
  printf("%d", ans);
}