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

const int nax = 1e5 + 5;
int a[nax];
int n;
int x;
int dp[nax][4];

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    cin >> x;

    for(int i=0;i<nax;i++){
        for(int j=0;j<4;j++) dp[i][j] = 1e9;
    }
    dp[1][0] = 1;
    dp[1][1] = 0;
    for(int i=2;i<=n;i++){
        int w = 1e9;
        for(int j=0;j<4;j++) w = min(w, dp[i-1][j]);
        dp[i][0] = w + 1;

        dp[i][1] = dp[i - 1][0];

        if(a[i] + a[i - 1] >= x * 2){
            dp[i][2] = dp[i - 1][1];
        }

        if(i >= 3 && a[i] + a[i - 1] + a[i - 2] >= x * 3 && a[i] + a[i - 1] >= x * 2){
            dp[i][3] = min(dp[i - 1][3], dp[i - 1][2]);
        }

    }
    int w = 1e9;
    for(int i=0;i<4;i++) w = min(w, dp[n][i]);
    cout << n - w << "\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}