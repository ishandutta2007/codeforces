#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#define endl '\n'
using namespace __gnu_pbds;
typedef long double ld;
//#define int ll
using namespace std;
mt19937 rnd(time(NULL));
typedef long long ll;
const ll mod=998244353;
const int N=300010;
int x[N];
bool dp[N][3];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>x[i];
    for (int i=0;i<=n+1;i++){
        for (int j=0;j<3;j++){
            dp[i][j]=0;
        }
    }
    for (int i=0;i<3;i++) dp[1][i]=1;
    for (int i=1;i<n;i++){
        for (int j=0;j<3;j++){
            for (int t=0;t<3;t++){
                if (x[i]+j==x[i+1]+t-1){
                    dp[i+1][t]|=dp[i][j];
                }
            }
        }
    }
    if (dp[n][0] || dp[n][1] || dp[n][2]){
        cout<<"YES\n";
    } else {
        cout<<"NO\n";
    }

}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}

/**
1
8
6 7
2 3
8 6
5 4
1 7
3 6
4 3
**/