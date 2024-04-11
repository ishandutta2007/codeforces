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

const int maxn = 212345;
const ll MOD = 1e9 + 7;

ll dp[maxn][3], cnt[3];
int n, l, r;

int main() {
    scanf("%d%d%d", &n, &l, &r);
    l += 2, r += 3;
    cnt[0] = r / 3 - l / 3;
    cnt[1] = (r - 1) / 3 - (l - 1) / 3;
    cnt[2] = (r - 2) / 3 - (l - 2) / 3;
    dp[0][0] = 1;
    FOR(i, 1, n) REP(j, 3) REP(k, 3)
                dp[i][j] = (dp[i - 1][(j - k + 3) % 3] * cnt[k] + dp[i][j]) % MOD;
    printf("%lld", dp[n][0]);
}