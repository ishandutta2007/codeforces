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

const int maxn = 212345;

int n;
int a[maxn];
ll ans;

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) {
    scanf("%d", a + i);
    if (a[i] < 0) a[i] = -a[i];
  }
  sort(a + 1, a + n + 1);
  FOR(i, 1, n) {
    auto it1 = lower_bound(a + 1, a + n + 1, a[i] + 1), it2 = upper_bound(a + 1, a + n + 1, 2 * a[i]);
    ans += it2 - it1;
  }
  for (int i = 1; i <= n; ) {
    int j = i;
    while (j <= n && a[j] == a[i]) j++;
    ll cnt = j - i;
    ans += cnt * (cnt - 1) / 2;
    i = j;
  }
  printf("%lld", ans);
}