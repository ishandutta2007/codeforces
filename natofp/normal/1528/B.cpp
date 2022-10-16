#include <bits/stdc++.h>
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

const int nax = 1e6 + 5;
const int mod = 998244353;
ll dp[nax];
ll pref[nax];

int dd[nax];

void prep(){
    for(int i=1;i<nax;i++){
        for(int j=i;j<nax;j+=i){
            dd[j]++;
        }
    }
}

void solve(){
    int n; cin >> n;
    // dp[i] - ile opcji jak mamy 2i punktow
    dp[0] = 1;
    dp[1] = 1;
    pref[0] = 1;
    pref[1] = 2;
    for(int i=2;i<=n;i++){
        dp[i] = pref[i - 1] + dd[i] - 1;
        dp[i] %= mod;
        pref[i] = pref[i - 1];
        pref[i] += dp[i];
        pref[i] %= mod;
    }
    cout << dp[n] << "\n";


}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    prep();
    int tt = 1;
    //cin >> tt;
    while(tt--) solve();


    return 0;
}