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

const int nax = 3005;
string s, t;
const int mod = 998244353;
int dp[nax][nax * 2];


void solve(){
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    for(int i=0;i<nax;i++){
        if(i < m){
            dp[1][i] = (t[i] == s[0]) * 2;
        }
        else dp[1][i] = 2;
    }
    int ans = 0;
    for(int i=1;i<n;i++){
        char cur = s[i];
        for(int from=0;from<nax;from++){
            int to = from + i - 1;
            if(from > 0){
                bool ok = (from - 1 >= m || (t[from - 1] == cur));
                if(ok){
                    dp[i + 1][from - 1] += dp[i][from];
                    dp[i + 1][from - 1] %= mod;
                }
            }
            bool ok = (to + 1 >= m || (t[to + 1] == cur));
            if(ok){
                dp[i + 1][from] += dp[i][from];
                dp[i + 1][from] %= mod;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(i < m) continue;
        ans += dp[i][0];
        ans %= mod;
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    // cin >> tt;
    while(tt--) solve();

    return 0;
}