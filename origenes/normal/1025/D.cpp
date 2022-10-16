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

const int maxn = 712;

int a[maxn], n;
bool dp[maxn][maxn][2], vis[maxn][maxn][2];
vector<int> G[maxn][2];

int gcd(int a, int b) {
    return !b ? a : gcd(b, a % b);
}

void init() {
    FOR(i, 1, n) FOR(j, i + 1, n)
            if (gcd(a[i], a[j]) > 1) {
                G[i][0].pb(j);
                G[j][1].pb(i);
            }
    FOR(i, 1, n) G[0][0].pb(i);
}

bool dfs(int l, int r, bool lft) {
    if (r < l) return true;
    if (vis[l][r][lft]) return dp[l][r][lft];
    vis[l][r][lft] = true;
    bool &ret = dp[l][r][lft];
    if (lft) {
        ROF(i, int(G[r + 1][1].size()) - 1, 0) {
            if (G[r + 1][1][i] < l) return ret;
            if (dfs(l, G[r + 1][1][i] - 1, true) && dfs(G[r + 1][1][i] + 1, r, false)) return ret = true;
        }
    } else {
        REP(i, int(G[l - 1][0].size())) {
            if (G[l - 1][0][i] > r) return ret;
            if (dfs(l, G[l - 1][0][i] - 1, true) && dfs(G[l - 1][0][i] + 1, r, false)) return ret = true;
        }
    }
    return ret;
}

int main() {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &a[i]);
    init();
    puts(dfs(1, n, false) ? "Yes" : "No");
    return 0;
}