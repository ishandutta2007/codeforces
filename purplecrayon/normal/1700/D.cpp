#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll inf = 1e18;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<ll> v(n+1);
    for(int i = 1; i <= n; i++) cin >> v[i];
    vector<ll> dp(n+1), make(n+1); dp[0] = inf;
    ll tot = 0;
    for(int i = 1; i <= n; i++) tot += v[i];
    ll pre = 0;
    for(ll i = 1; i <= n; i++){
        pre += v[i];
        make[i] = make[i-1] + max(0LL, (pre - make[i-1]*i + i-1)/i);
        dp[i] = max(make[i], (tot+i-1)/i);
    }
    int q; cin >> q;
    reverse(dp.begin(), dp.end());
    for(int i = 0; i < q; i++){
        int t; cin >> t;
        int ans = upper_bound(dp.begin(), dp.end(), t) - dp.begin();
        ans = n-ans+1;
        if(ans > n) cout << "-1\n";
        else cout << ans << "\n";
    }
}