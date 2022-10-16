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
int dp[nax][4];
int a[2][nax];

int cost[4] = {0, 1, 0, 2};

void solve(){
    int n; cin >> n;
    for(int i=0;i<=n;i++){
        for(int j=0;j<4;j++) dp[i][j] = -1e9;
    }
    string s1, s2;
    cin >> s1 >> s2;
    for(int i=0;i<n;i++){
        a[0][i + 1] = s1[i] - '0';
        a[1][i + 1] = s2[i] - '0';
    }
    int ans = 0;
    dp[0][0] = 0;
    for(int i=0;i<n;i++){
        int v1 = a[0][i + 1];
        int v2 = a[1][i + 1];
        if(v1 > v2) swap(v1, v2);
        int msk = 3;
        if(v1 == v2){
            if(v1 == 0) msk = 1;
            else msk = 2;
        }
        for(int j=0;j<4;j++){
            dp[i + 1][0] = max(dp[i + 1][0], dp[i][j] + cost[j | msk]);
            dp[i + 1][j | msk] = max(dp[i + 1][j | msk], dp[i][j]);
        }
    }
    for(int j=0;j<4;j++){
        ans = max(ans, dp[n][j] + cost[j]);
    }
    cout<<ans<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}