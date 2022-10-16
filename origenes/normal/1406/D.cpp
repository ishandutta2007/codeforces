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

int n, q;
ll a[maxn];

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%lld", a + i);
  ll inc = 0;
  FOR(i, 2, n) inc += max(a[i] - a[i - 1], 0LL);
  printf("%lld\n", (a[1] + inc + 1) >> 1);
  ROF(i, n, 1) a[i] = a[i] - a[i - 1];
  scanf("%d", &q);
  while (q--) {
    int l, r, s;
    scanf("%d%d%d", &l, &r, &s);
    if (l == 1) a[1] += s;
    else {
      if (a[l] > 0) inc -= a[l];
      a[l] += s;
      if (a[l] > 0) inc += a[l];
    }
    if (r != n) {
      r++;
      if (a[r] > 0) inc -= a[r];
      a[r] -= s;
      if (a[r] > 0) inc += a[r];
    }
    printf("%lld\n", (a[1] + inc + 1) >> 1);
  }
}