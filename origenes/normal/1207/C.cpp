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

ll a, b;
int n, T;
char s[maxn];

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%lld%lld", &n, &a, &b);
    vector<vector<ll>> f(n + 1, vector<ll>(2, 1e18));
    f[0][0] = 0;
    scanf("%s", s + 1);
    FOR(i, 1, n) {
      if (s[i] == '0') {
        chkmin(f[i][0], f[i - 1][0] + a + b);
        chkmin(f[i][0], f[i - 1][1] + 2 * a + 2 * b);
        chkmin(f[i][1], f[i - 1][0] + 2 * a + b);
      }
      chkmin(f[i][1], f[i - 1][1] + 2 * b + a);
    }
    printf("%lld\n", f[n][0] + b);
  }
}