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

const int maxn = 212345;

vector<int> G[maxn], lis[maxn];
int a[maxn], n, ans;
map<int, int> dp[maxn];

void dfs(int u, int p) {
    for (int v : G[u]) if (v != p) dfs(v, u);
    if (a[u] == 1) return;
    for (int f : lis[a[u]]) dp[u][f] = 1;
    ans = max(ans, 1);
    for (int v : G[u]) if (v != p) for (const auto &ch : dp[v]) {
                if (dp[u].count(ch._1)) {
                    ans = max(ans, dp[u][ch._1] + ch._2);
                    dp[u][ch._1] = max(dp[u][ch._1], ch._2 + 1);
                }
            }
}

int main() {
    FOR(i, 2, 2e5 + 1) if (lis[i].empty()) for (int j = i; j <= int(2e5); j += i) lis[j].eb(i);
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", a + i);
    REP(i, n - 1) {
        int x, y;
        scanf("%d%d", &x, &y);
        G[x].eb(y);
        G[y].eb(x);
    }
    dfs(1, 0);
    printf("%d", ans);
}