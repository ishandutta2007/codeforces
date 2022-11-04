#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const ll INF = 1e18;
const int MAXN = (int) 3e5;

vector < pair <int, int> > g[MAXN + 1];
int w[MAXN + 1];
ll dp[MAXN + 1], ans;

void dfs(int nod, int par) {
    ll mx1 = -INF, mx2 = -INF;
    dp[nod] = w[nod];
    for(auto it : g[nod]) {
        if(it.first != par) {
            dfs(it.first, nod);
            if(dp[it.first] >= it.second) {
                dp[nod] = max(dp[nod], dp[it.first] + w[nod] - it.second);
                ll cur = dp[it.first] - it.second;
                if(cur >= mx1) {
                    mx2 = mx1;
                    mx1 = cur;
                }
                else if(cur > mx2) {
                    mx2 = cur;
                }
            }
        }
    }
    ans = max(ans, mx1 + mx2 + w[nod]);
    ans = max(ans, dp[nod]);
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> w[i];
    }
    for(i = 1; i < n; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        g[x].push_back({y, c});
        g[y].push_back({x, c});
    }
    ans = -INF;
    dfs(1, 0);
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}