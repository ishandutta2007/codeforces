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

const int maxn = 2123;
const int maxc = 1123456;

int n, m;
int a[maxn], b[maxn], c[maxn], d[maxn];
int mx[maxc];

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, n) scanf("%d%d", a + i, b + i);
  FOR(i, 1, m) scanf("%d%d", c + i, d + i);
  FOR(i, 1, n) FOR(j, 1, m) if (c[j] - a[i] >= 0) chkmax(mx[c[j] - a[i]], d[j] - b[i] + 1);
  ROF(i, 1e6, 0) chkmax(mx[i], mx[i + 1]);
  int ans = 1e9;
  REP(i, 1e6 + 1) chkmin(ans, i + mx[i]);
  printf("%d", ans);
}