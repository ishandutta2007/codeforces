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

int n;
int b[maxn];
ll a[maxn];

int main() {
  scanf("%d", &n);
  int mn = 1e9, mx = 0;
  REP(i, n) {
    scanf("%d", b + i);
    chkmin(mn, b[i]);
    chkmax(mx, b[i]);
  }
  if (!mx) {
    puts("YES");
    REP(i, n) printf("1 ");
    return 0;
  }
  if (mn == mx) {
    puts("NO");
    return 0;
  }
  puts("YES");
  int peak = -1;
  REP(i, n) if (b[i] == mx) {
    peak = i;
    break;
  }
  if (!peak) {
    for (int i = n - 1; b[i] == mx; i--) peak = i;
  }
  a[peak] = mx;
  FOR(i, 1, n - 1) {
    if (b[(peak - i + n) % n] == 0 && a[(peak - i + n + 1) % n] == mx)
      a[(peak - i + n) % n] = mx * 2;
    else a[(peak - i + n) % n] = a[(peak - i + n + 1) % n] + b[(peak - i + n) % n];
  }
  REP(i, n) printf("%lld ", a[i]);
}