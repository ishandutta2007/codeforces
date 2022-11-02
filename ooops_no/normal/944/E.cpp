#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 1e5 + 10;

vector<int> dp(N), dpp(N);

int func(vector<int> a){
    vector<int> d(N, 1e18), dd(N, 1e18);
    d[0] = -1e18;
    dd[0] = -1e18;
    for (int i = 0; i < a.size(); i++){
        int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        dp[i] = j;
        if (d[j - 1] <= a[i] && a[i] <= d[j]){
            d[j] = a[i];
        }
    }
    for (int i = a.size() - 1; i >= 0; i--){
        int j = upper_bound(dd.begin(), dd.end(), a[i]) - dd.begin();
        dpp[i] = j;
        if (dd[j - 1] <= a[i] && a[i] <= dd[j]){
            dd[j] = a[i];
        }
    }
    int ans = 0;
    for (int i = 0; i < a.size() - 1; i++){
        ans = max(ans, dp[i] + dpp[i + 1]);
    }
    return max(ans, dp[a.size() - 1]);
}

int32_t main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> v(n);
    vector<int> a(m), pl(m + 1);
    for (int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
        v[i].first--, v[i].second--;
        pl[v[i].first]++, pl[v[i].second + 1]--;
    }
    int now = 0;
    for (int i = 0; i < m; i++){
        now += pl[i];
        a[i] = now;
    }
    int ans = func(a);
    cout << ans << endl;
    return 0;
}