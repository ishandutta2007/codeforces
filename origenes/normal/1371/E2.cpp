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

int n, p, a[maxn];

int main() {
  scanf("%d%d", &n, &p);
  FOR(i, 1, n) scanf("%d", a + i);
  sort(a + 1, a + n + 1);
  int l = 0, r = 1e9 + 5;
  FOR(i, 1, n) chkmax(l, a[i] - i + 1);
  FOR(i, 1, n - p + 1) chkmin(r, a[i + p - 1] - i);
  if (l > r) puts("0");
  else {
    printf("%d\n", r - l + 1);
    FOR(i, l, r) printf("%d ", i);
  }
}