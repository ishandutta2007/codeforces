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

const int maxn = 2123456;
const int MOD = 1e9 + 7;

int f[maxn], n, T;

int main() {
  FOR(i, 3, 2e6) {
    f[i] = (f[i - 1] + 2LL * f[i - 2]) % MOD;
    if (i % 3 == 0) f[i] += 4;
    if (f[i] >= MOD) f[i] -= MOD;
  }
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    printf("%d\n", f[n]);
  }
}