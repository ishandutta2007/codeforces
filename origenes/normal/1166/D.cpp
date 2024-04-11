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
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 112;

int q;
ll x[maxn], r[maxn];

int main() {
  scanf("%d", &q);
  while (q--) {
    ll a, b, m;
    scanf("%lld%lld%lld", &a, &b, &m);
    if (a == b) {
      printf("1 %lld\n", a);
      continue;
    }
    if (b == a + 1) {
      printf("2 %lld %lld\n", a, b);
      continue;
    }
    x[1] = a, x[2] = a + 1;
    int i;
    for (i = 3; ; i++) {
      x[i] = x[i - 1] << 1;
      if (x[i] > b) {
        i--;
        break;
      }
    }
    if (x[i + 1] == b) {
      printf("%d", i + 1);
      FOR(j, 1, i + 1) printf(" %lld", x[j]);
      puts("");
      continue;
    }
    ll diff = b - x[i];
    FOR(j, 2, i - 1) {
      r[j] = 1;
      ll now = min(m - 1, diff / (1LL << i - j - 1));
      r[j] += now;
      diff -= now * (1LL << i - j - 1);
    }
    r[i] = 1;
    ll now = min(m - 1, diff);
    r[i] += now;
    diff -= now;
    if (diff) {
      puts("-1");
      continue;
    }
    x[1] = a, x[2] = a + r[2];
    FOR(j, 3, i) {
      x[j] = r[j];
      ROF(k, j - 1, 1) x[j] += x[k];
    }
    printf("%d", i);
    FOR(j, 1, i) printf(" %lld", x[j]);
    puts("");
  }
}