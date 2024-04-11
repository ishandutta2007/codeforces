#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define ll long long
#define int long long
#define pb push_back

mt19937 rnd(51);

const int INF = 1e18;

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), u;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        a[i] -= i;
        u.pb(a[i]);
    }
    sort(u.begin(), u.end());
    u.erase(unique(u.begin(), u.end()), u.end());
    vector<int> dp(u.size());
    for (int i = 0; i < u.size(); i++){
        dp[i] = abs(u[i] - a[0]);
    }
    for (int i = 1; i < n; i++){
        int mn = INF;
        vector<int> dpp(u.size());
        for (int j = 0; j < u.size(); j++){
            mn = min(mn, dp[j]);
            dpp[j] = mn + abs(u[j] - a[i]);
        }
        dp = dpp;
    }
    cout << *min_element(dp.begin(), dp.end()) << endl;
    return 0;
}