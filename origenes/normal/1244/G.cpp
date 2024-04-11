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

const int maxn = 1123456;

int n;
ll k;
int a[maxn], b[maxn];

int main() {
  scanf("%d%lld", &n, &k);
  if (k < ll(n) * (n + 1) / 2) {
    puts("-1");
    return 0;
  }
  k -= ll(n) * (n + 1) / 2;
  iota(a + 1, a + n + 1, 1);
  iota(b + 1, b + n + 1, 1);
  ll ans = 0;
  FOR(i, 1, n / 2) {
    if (!k) break;
    if (n - i + 1 - i <= k) {
      swap(b[n - i + 1], b[i]);
      ans += n - i + 1 - i;
      k -= n - i + 1 - i;
    } else {
      FOR(j, i, n - i) {
        if (n - i + 1 - j == k) {
          swap(b[n - i + 1], b[j]);
          ans += k;
          k = 0;
          break;
        }
      }
    }
  }
  printf("%lld\n", ll(n) * (n + 1) / 2 + ans);
  FOR(i, 1, n) printf("%d ", a[i]);
  putchar('\n');
  FOR(i, 1, n) printf("%d ", b[i]);
}