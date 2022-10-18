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

const int maxn = 1123456;

int cnt[maxn], dp[maxn][3][3], n, m;

int main() {
    scanf("%d%d", &n, &m);
    FOR(i, 1, n) {
        int a;
        scanf("%d", &a);
        cnt[a]++;
    }
    REP(i, m + 10) REP(fi, 3) REP(se, 3) {
                int rem = cnt[i + 1] - fi - se;
                REP(j, min(3, rem + 1)) dp[i + 1][se][j] = max(dp[i + 1][se][j], dp[i][fi][se] + (rem - j) / 3 + j);
            }
    printf("%d", dp[m + 10][0][0]);
}