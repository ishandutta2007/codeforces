#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 1234567;
const int inf = 0x3f3f3f3f;

int n, dp[maxn][2];
char a[maxn], b[maxn];

int main() {
    scanf("%d", &n);
    scanf("%s%s", a + 1, b + 1);
    reset(dp, 0x3f);
    dp[0][0] = 0;
    FOR(i, 1, n) {
        if (a[i] == b[i]) {
            dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + 1);
            if (i != n && a[i + 1] != a[i]) dp[i][1] = dp[i - 1][1] + 1;
        }
        else {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][0] + 1);
            if (i != n && a[i + 1] != a[i]) dp[i][1] = dp[i - 1][0] + 1;
        }
    }
    printf("%d\n", min(dp[n][0], dp[n][1]));
    return 0;
}