#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define int long long

bool cmp(const pair<int,int> &a, const pair<int,int> &b){
    return a.first + a.second > b.first + b.second;
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, r;
    cin >> n >> r;
    vector<int> a(n), b(n);
    vector<pair<int,int>> v, u;
    for (int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
        if (b[i] >= 0){
            v.pb({a[i], b[i]});
        }
        else{
            u.pb({a[i], b[i]});
        }
    }
    sort(v.begin(), v.end());
    int pl = 0;
    for (int i = 0; i < v.size(); i++){
        if (r >= v[i].first){
            r += v[i].second;
            pl++;
        }
    }
    int dp[n + 1][r + 1];
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= r; j++){
            dp[i][j] = 0;
        }
    }
    sort(u.begin(), u.end(), cmp);
    for (int i = 0; i < u.size(); i++){
        for (int j = 0; j <= r; j++){
            dp[i + 1][j] = max(dp[i][j], dp[i + 1][j]);
            if (j >= u[i].first && j + u[i].second >= 0){
                dp[i + 1][j + u[i].second] = max(dp[i + 1][j + u[i].second], dp[i][j] + 1);
            }
        }
    }
    int ans = 0;
    for (int j = 0; j <= r; j++){
        ans = max(ans, dp[(int)u.size()][j]);
    }
    cout << ans + pl << endl;
    return 0;
}