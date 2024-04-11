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

int n;
char s[maxn], vis[maxn][maxn][maxn][2];
ll a[maxn], dp[maxn][maxn][maxn][2];

ll dfs(int l, int r, int len, char flag) {
    if (l > r) return a[len];
    if (vis[l][r][len][flag - '0']) return dp[l][r][len][flag - '0'];
    vis[l][r][len][flag - '0'] = true;
    ll &ret = dp[l][r][len][flag - '0'];
    if (s[l] == flag) ret = max(ret, dfs(l + 1, r, len + 1, flag));
    FOR(i, l, r) {
        if (i == r && !len) break;
        ll now = 0;
        FOR(ff, '0', '1') now = max(now, dfs(l, i, 0, ff));
        ret = max(ret, now + dfs(i + 1, r, len, flag));
    }
    return ret;
}

int main() {
    scanf("%d%s", &n, s + 1);
    FOR(i, 1, n) scanf("%lld", a + i);
    printf("%lld", max(dfs(1, n, 0, '0'), dfs(1, n, 0, '1')));
}