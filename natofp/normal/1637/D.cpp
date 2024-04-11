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

const int nax = 105;
int a[nax];
int b[nax];
int dp[nax][nax * nax];
int n;

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];
    ll ans = 0;
    for(int i=1;i<=n;i++){
        ll cur = a[i] * a[i];
        cur *= (n - 1);
        ans += cur;
        cur = b[i] * b[i];
        cur *= (n - 1);
        ans += cur;
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n*100;j++) dp[i][j] = 1e9;
    }
    dp[0][0] = 0;
    for(int i=0;i<n;i++){
        int sumAll = 0;
        for(int k=1;k<=i;k++){
            sumAll += a[k];
            sumAll += b[k];
        }
        for(int j=0;j<=i*100;j++){
            int v1 = a[i + 1];
            int v2 = b[i + 1];
            int suma = j;
            int sumb = sumAll - suma;
            dp[i + 1][j + v1] = min(dp[i + 1][j + v1], dp[i][j] + suma * v1 + sumb * v2);
            dp[i + 1][j + v2] = min(dp[i + 1][j + v2], dp[i][j] + suma * v2 + sumb * v1);
        }
    }
    int bonus = 1e9;
    for(int i=0;i<=n*100;i++) bonus = min(bonus, dp[n][i]);
    bonus *= 2;
    cout << ans + bonus << "\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}