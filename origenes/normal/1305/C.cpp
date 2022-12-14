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
const int maxm = 1123;

int n, m, a[maxn];
int cnt[maxm];

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, n) {
    scanf("%d", a + i);
    cnt[a[i] % m]++;
  }
  REP(i, m) if (cnt[i] >= 2) {
    puts("0");
    return 0;
  }
  ll ans = 1;
  FOR(i, 1, n) FOR(j, i + 1, n) ans = ans * abs(a[i] - a[j]) % m;
  printf("%lld", ans);
}