#include <bits/stdc++.h>
#include <random>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>
#define ld long double
#define ull unsigned long long

using namespace std;

const int mod = 998244353;
const int nax = 2e5 + 5;

int x[nax];
int y[nax];
bool s[nax];
int n;

ll dp[nax];
ll pref[nax];

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> x[i] >> y[i] >> s[i];
    vector<int> ez;
    ez.pb(0);
    for(int i=1;i<=n;i++){
        ez.pb(x[i]);
    }
    dp[0] = 0;
    dp[1] = x[1] - y[1];
    pref[0] = dp[0];
    pref[1] = dp[1];
    for(int i=2;i<=n;i++){
        int to = y[i];
        int id = (int)(lower_bound(ez.begin(), ez.end(), to) - ez.begin());
        dp[i] = x[i] - to;
        dp[i] += pref[i - 1];
        if(id > 0){
            dp[i] -= pref[id - 1];
        }
        if(dp[i] < 0) dp[i] += mod;
        dp[i] %= mod;
        pref[i] = pref[i - 1] + dp[i];
        pref[i] %= mod;
    }
    ll ans = x[n] + 1;
    for(int i=1;i<=n;i++){
        if(s[i]){
            ans += dp[i];
        }
    }
    cout << ans % mod;

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while(tt--) solve();

    return 0;
}