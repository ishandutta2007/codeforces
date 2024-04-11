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

struct Env {
    int s, t, d, w;

    bool operator<(const Env &rhs) const {
        if (w != rhs.w) return w > rhs.w;
        return d > rhs.d;
    }
} e[maxn];

inline bool cmp(const Env& lhs, const Env &rhs) {
    if (lhs.s != rhs.s) return lhs.s < rhs.s;
    return lhs.t < rhs.t;
}

ll dp[maxn][205];
int n, m, k, lis[maxn];

int main() {
    scanf("%d%d%d", &n, &m, &k);
    FOR(i, 1, k) scanf("%d%d%d%d", &e[i].s, &e[i].t, &e[i].d, &e[i].w);
    sort(e + 1, e + k + 1, cmp);
    int p = 1;
    set<pair<Env, int>> s;
    FOR(i, 1, n) {
        while (p <= k && e[p].s == i) s.insert(mp(e[p], p)), p++;
        while (!s.empty() && (*s.begin())._1.t < i) s.erase(s.begin());
        if (s.empty()) continue;
        lis[i] = (*s.begin())._2;
    }
    reset(dp, 0x3f);
    dp[1][0] = 0;
    ll ans = 0x3f3f3f3f3f3f3f3f;
    FOR(i, 1, n - 1) {
        if (!lis[i]) {
            REP(j, m + 1) dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            continue;
        }
        int w = e[lis[i]].w, d = e[lis[i]].d;
        REP(j, m) {
            dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
            if (d + 1 <= n) dp[d + 1][j] = min(dp[d + 1][j], dp[i][j] + w);
            else ans = min(ans, dp[i][j] + w);
        }
        if (d + 1 <= n) dp[d + 1][m] = min(dp[d + 1][m], dp[i][m] + w);
        else ans = min(ans, dp[i][m] + w);
    }
    if (lis[n]) {
        REP(j, m) ans = min(ans, dp[n][j]);
        int w = e[lis[n]].w;
        ans = min(ans, dp[n][m] + w);
    } else {
        REP(j, m + 1) ans = min(ans, dp[n][j]);
    }
    printf("%lld", ans);
}