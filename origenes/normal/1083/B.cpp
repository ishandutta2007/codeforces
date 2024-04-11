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

const int maxn = 512345;

ll dp[maxn];
char s[maxn], t[maxn];
int n, k;

int main() {
    scanf("%d%d", &n, &k);
    scanf("%s%s", s + 1, t + 1);
    dp[0] = 1;
    ll ans = 0;
    FOR(i, 1, n) {
        if (dp[i - 1] > 2) {
            dp[i] = (dp[i - 1] - 2) * 2;
            dp[i - 1] = 2;
        } else dp[i] = 0;
        if (dp[i - 1] == 2) {
            dp[i] += 'b' - s[i] + 1;
            dp[i] += t[i] - 'a' + 1;
        } else if (dp[i - 1] == 1) {
            dp[i] += t[i] - s[i] + 1;
        }
        dp[i] = min(ll(1e9), dp[i]);
        ans += min(dp[i], ll(k));
    }
    printf("%lld", ans);
}