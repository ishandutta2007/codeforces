#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>

using namespace std;

const int nax = 505;
int n,m,k;
int dp[nax][nax][22]; // powrot po k krokach :))

int poziom[nax][nax];
int pion[nax][nax];

void solve(){
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<m;j++){
            cin >> poziom[i][j];
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<=m;j++){
            cin >> pion[i][j];
        }
    }

    if(k & 1){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout << -1 << " ";
            }
            cout<<"\n";
        }
        return;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j][2] = 1e9;
            if(j < m) dp[i][j][2] = min(dp[i][j][2], 2 * poziom[i][j]);
            if(j > 1) dp[i][j][2] = min(dp[i][j][2], 2 * poziom[i][j - 1]);
            if(i < n) dp[i][j][2] = min(dp[i][j][2], 2 * pion[i][j]);
            if(i > 1) dp[i][j][2] = min(dp[i][j][2], 2 * pion[i - 1][j]);
        }
    }
    for(int c=4;c<=k;c+=2){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j][c] = dp[i][j][c - 2] + dp[i][j][2];
                if(j < m) dp[i][j][c] = min(dp[i][j][c], dp[i][j + 1][c - 2] + 2 * poziom[i][j]);
                if(j > 1) dp[i][j][c] = min(dp[i][j][c], dp[i][j - 1][c - 2] + 2 * poziom[i][j - 1]);
                if(i < n) dp[i][j][c] = min(dp[i][j][c], dp[i + 1][j][c - 2] + 2 * pion[i][j]);
                if(i > 1) dp[i][j][c] = min(dp[i][j][c], dp[i - 1][j][c - 2] + 2 * pion[i - 1][j]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<dp[i][j][k]<<" ";
        }
        cout<<"\n";
    }


}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
   // cin >> tt;
    while(tt--) solve();

    return 0;
}