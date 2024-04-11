#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll __int128
#define int long long

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

void solve(){
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; i++){
        cin >> c[i];
    }
    int ans = c[0] * n + c[1] * n;
    int mn0 = c[0], mn1 = c[1], cnt0 = 1, cnt1 = 1, sum0 = c[0], sum1 = c[1];
    for (int i = 2; i < n; i++){
        if (i % 2 == 0) {
            mn0 = min(mn0, c[i]);
            cnt0++;
            sum0 += c[i];
        }
        else {
            mn1 = min(mn1, c[i]);
            cnt1++;
            sum1 += c[i];
        }
        ans = min(ans, mn0 * (n - cnt0) + sum0 + mn1 * (n - cnt1) + sum1);
    }
    cout << ans << endl;
}

int32_t main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}