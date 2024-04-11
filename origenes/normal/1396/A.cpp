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

ll a[maxn], x[maxn];
int n;

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%lld", a + i);
  if (n == 1) {
    printf("1 1\n%lld\n1 1\n0\n1 1\n0", -a[1]);
    return 0;
  }
  printf("1 %d\n", n);
  FOR(i, 1, n) {
    x[i] = -a[i] % (n - 1);
    if (x[i] < 0) x[i] += n - 1;
    printf("%lld ", x[i] * n);
  }
  putchar('\n');
  puts("1 1");
  printf("%lld\n", -(x[1] * n + a[1]));
  printf("2 %d\n", n);
  FOR(i, 2, n) printf("%lld ", -(x[i] * n + a[i]));
}