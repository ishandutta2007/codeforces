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

const int nax = 405;
int a[nax][nax];
int pref[nax][nax];
int n, m;

void solve(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char x; cin >> x;
            a[i][j] = x - '0';
            pref[i][j] = pref[i][j - 1] + a[i][j];
        }
    }
    int ans = 222;
    for(int L=1;L<=m;L++){
        for(int R=L+3;R<=m;R++){
            vector<int> dp(5, 222);
            dp[1] = R - L - 1 - (pref[1][R - 1] - pref[1][L]);
            for(int i=2;i<=n;i++){
                int cost = R - L - 1 - pref[i][R - 1] + pref[i][L];
                ans = min(ans, cost + dp[4]);
                int cost2 = pref[i][R - 1] - pref[i][L] + 2 - a[i][L] - a[i][R];
                dp[4] = min(dp[4], dp[3]) + cost2;
                for(int j=3;j>=2;j--){
                    dp[j] = dp[j - 1] + cost2;
                }
                dp[1] = cost;
            }
        }
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}