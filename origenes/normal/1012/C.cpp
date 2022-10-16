#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define all(x) (x).begin(), (x).end()
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 2511;

int n, a[maxn * 2];
ll dp[2][maxn][3];

inline int dist(int x, int y) {
    return x < y ? 0 : x - y + 1;
}

int main() {
    int now = 0;
    scanf("%d", &n);
    int upp = (n + 1) / 2;
    FOR(i, 1, n) scanf("%d", &a[i]);
    a[0] = a[n + 1] = -10000000;
    memset(dp[0], 0x3f, sizeof(dp[0]));
    dp[0][0][1] = 0;
    FOR(i, 1, n) {
        int p = now;
        now ^= 1;
        memset(dp[now], 0x3f, sizeof(dp[now]));
        FOR(j, 0, upp) {
            if (a[i] >= a[i + 1]) dp[now][j][0] = min(dp[p][j][0], dp[p][j][1]);
            if (min(a[i], a[i - 1] - 1) >= a[i + 1]) dp[now][j][0] = min(dp[now][j][0], dp[p][j][2] + dist(a[i], a[i - 1]));
            dp[now][j][1] = min(dp[p][j][0], dp[p][j][1]) + dist(a[i], a[i + 1]);
            dp[now][j][1] = min(dp[now][j][1], dp[p][j][2] + dist(a[i], min(a[i - 1], a[i + 1])));
            if(j) dp[now][j][2] = dp[p][j - 1][1];
        }
    }
    FOR(i, 1, upp) printf("%lld ", min(min(dp[now][i][0], dp[now][i][1]), dp[now][i][2]));
    puts("");
    return 0;
}