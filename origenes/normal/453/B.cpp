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

const int maxn = 112;

int a[maxn], b[maxn], dp[maxn][1 << 16], m[65], n;
pii pre[maxn][1 << 16];
vector<int> G[1 << 16], primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};

int main() {
    FOR(i, 1, 58) REP(j, 16) if (i % primes[j] == 0) m[i] |= 1 << j;
    REP(mask, 1 << 16) FOR(i, 1, 58) if (!(mask & m[i])) G[mask].eb(i);
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", a + i);
    reset(dp, 0x3f);
    dp[0][0] = 0;
    REP(i, n) REP(mask, 1 << 16) for (int j : G[mask]) {
                if (dp[i + 1][mask | m[j]] > dp[i][mask] + abs(j - a[i + 1])) {
                    pre[i + 1][mask | m[j]] = {j, mask};
                    dp[i + 1][mask | m[j]] = dp[i][mask] + abs(j - a[i + 1]);
                }
            }
    int ans = 0;
    REP(mask, 1 << 16) if (dp[n][mask] < dp[n][ans]) ans = mask;
    ROF(i, n, 1) {
        b[i] = pre[i][ans]._1;
        ans = pre[i][ans]._2;
    }
    FOR(i, 1, n) printf("%d ", b[i]);
}