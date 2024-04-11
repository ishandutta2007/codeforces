#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 2e5;

vector <int> g[MAXN + 1];
int cnt[MAXN + 1][2];
ll dp[MAXN + 1][2], ans;

void dfs(int nod, int par) {
    int nr = 0;
    cnt[nod][0]++;
    for(auto it : g[nod]) {
        if(it != par) {
            nr++;
            dfs(it, nod);
            ans += 1LL * (dp[nod][0] / 2) * (cnt[it][0] + cnt[it][1]);
            ans += 1LL * ((dp[nod][1] + cnt[nod][1]) / 2) * (cnt[it][0] + cnt[it][1]);
            ans += 1LL * ((dp[it][0] + 2 * cnt[it][0]) / 2) * (cnt[nod][0] + cnt[nod][1]);
            ans += 1LL * ((dp[it][1] + cnt[it][1]) / 2) * (cnt[nod][0] + cnt[nod][1]);

            dp[nod][0] += dp[it][1] + cnt[it][1];
            cnt[nod][0] += cnt[it][1];
            dp[nod][1] += dp[it][0] + cnt[it][0];
            cnt[nod][1] += cnt[it][0];
        }
    }
    ll cur = 0;
    for(auto it : g[nod]) {
        if(it != par) {
            cur += 1LL * cnt[it][0] * (cnt[nod][1] - cnt[it][0]);
        }
    }
    ans -= cur / 2;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, x, y;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i < n; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0);
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}