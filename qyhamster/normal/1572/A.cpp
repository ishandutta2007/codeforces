#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int inf = 1e9;
int dp[maxn];
vector<int> e[maxn];
int get_dp(int x) {
    if(dp[x] >= 0) return dp[x];
    dp[x] = inf;
    int mx = 1;
    for(auto k:e[x]) {
        if(get_dp(k) == inf) return inf;
        if(k < x) mx = max(mx, dp[k]);
        else {
            mx = max(mx, dp[k]+1);
        }
    }
    dp[x] = mx;
    return mx;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        for(int i = 0; i <= n; i++) {
            e[i].clear();
            dp[i] = -1;
        }
        for(int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            for(int j = 0; j < x; j++) {
                int u;
                cin >> u;
                e[i].push_back(u);
            }
        }
        bool ok = 1;
        for(int i = 1; i <= n; i++) {
            if(get_dp(i) == inf){
                ok = 0;
                cout << -1 << endl;
                break;
            }
        }
        if(ok) {
            int mx = 0;
            for(int i = 1; i <= n; i++) mx = max(mx, dp[i]);
            cout << mx << endl;
        }
    }
    return 0;
}