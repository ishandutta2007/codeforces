#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 5e3+10, MOD = 1e9+7;
 
int n, dp[MAXN], a[MAXN];
bool vis[MAXN], first[MAXN], last[MAXN];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++) {
        if (!vis[a[i]]) first[i] = 1;
        vis[a[i]] = 1;
    }
    memset(vis, 0, sizeof(vis));
    for (int i = n-1; i >= 0; i--) {
        if (!vis[a[i]]) last[i] = 1;
        vis[a[i]] = 1;
    }
    for (int i = 0; i < n; i++) {
        if (i) dp[i] = dp[i-1];

        memset(vis, 0, sizeof(vis));

        int cost = 0;
        int cnt_first = 0, cnt_last = 0;
        int cnt_dif = 0;
        for (int j = i; j >= 0; j--) {
            if (!vis[a[j]]) cnt_dif++, cost ^= a[j], vis[a[j]] = 1;
            if (first[j]) cnt_first++;
            if (last[j]) cnt_last++;

            if (cnt_first == cnt_dif && cnt_last == cnt_dif) {
                dp[i] = max(dp[i], cost + (j ? dp[j-1] : 0));
            }
        }
    }
    cout << dp[n-1] << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}