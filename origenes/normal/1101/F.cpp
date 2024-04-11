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

const int maxn = 401;

int a[maxn], dp[maxn][maxn][maxn], n, m;
ll ans;

int main() {
    scanf("%d%d", &n, &m);
    FOR(i, 1, n) scanf("%d", a + i);
    FOR(i, 1, n) FOR(j, 1, i - 1) dp[j][i][1] = a[i] - a[j];
    FOR(i, 1, n) ROF(j, i - 1, 1) {
            int b = i - j, r = i - 1;
            FOR(k, 2, b) {
                while (r > j + 1 && max(dp[j][r][1], dp[r][i][k - 1]) >= max(dp[j][r - 1][1], dp[r - 1][i][k - 1])) r--;
                dp[j][i][k] = max(dp[j][r][1], dp[r][i][k - 1]);
            }
            FOR(k, b + 1, n - 1) dp[j][i][k] = dp[j][i][k - 1];
        }
    REP(i, m) {
        int s, f, c, r;
        scanf("%d%d%d%d", &s, &f, &c, &r);
        ans = max(ans, ll(dp[s][f][min(r + 1, f - s)]) * c);
    }
    printf("%lld", ans);
}