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

const int maxn = 112345;

char s[maxn];
ll a, dp[maxn][4];
int n;

int main() {
    scanf("%d", &n);
    scanf("%s", s + 1);
    FOR(i, 1, n) {
        scanf("%lld", &a);
        memcpy(dp[i], dp[i - 1], sizeof(dp[i]));
        if (s[i] == 'h') {
            dp[i][0] += a;
            dp[i][1] = min(dp[i - 1][1], dp[i - 1][0]);
        }
        else if (s[i] == 'a') {
            dp[i][1] = dp[i - 1][1] + a;
            dp[i][2] = min(dp[i - 1][1], dp[i - 1][2]);
        } else if (s[i] == 'r') {
            dp[i][2] = dp[i - 1][2] + a;
            dp[i][3] = min(dp[i - 1][2], dp[i - 1][3]);
        } else if (s[i] == 'd') dp[i][3] = dp[i - 1][3] + a;
    }
    printf("%lld", *min_element(dp[n], dp[n] + 4));
}