#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long
#define int long long

mt19937 rnd(51);

const int N = 1e4 + 10;

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> a(N);
    for (int i = 0; i < n; i++){
        int b;
        cin >> b;
        a[b].pb(i);
    }
    vector<int> dp(N, n);
    dp[0] = -1;
    for (int i = 0; i < N; i++){
        if (a[i].size() == 0) continue;
        vector<int> dpp = dp;
        for (int j = 0; j < N; j++){
            int ind = upper_bound(a[i].begin(), a[i].end(), dp[j]) - a[i].begin();
            if (ind != a[i].size()){
                dpp[j ^ i] = min(dpp[j ^ i], a[i][ind]);
            }
        }
        dp = dpp;
    }
    vector<int> ans;
    for (int i = 0; i < N; i++){
        if (dp[i] != n){
            ans.pb(i);
        }
    }
    cout << ans.size() << endl;
    for (auto to : ans) cout << to << ' ';
    cout << endl;
    return 0;
}