#include <bits/stdc++.h>

typedef long long ll;
//#define endl '\n'
using namespace std;
//#define int ll
const int N=510;
ll mod;
ll f[N];
ll C[N][N];
ll dp[2][N*(N+1)*2][3];
ll tot[2][N*(N+1)*2];
void solve(){
    int n;cin>>n>>mod;
    C[0][0]=1;
    f[0]=1;
    for (int i=1;i<=n;i++){
        f[i]=(f[i-1]*(i*1ll))%mod;
        C[i][0]=1;
        for (int j=1;j<=i;j++){
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
        }
    }
    ll res=0ll;

    int Z=N*N;
    dp[0][Z][1]=1;
    tot[0][Z]=1;
    for (int i=0;i<n;i++){
//        for (int j=0;j<=Z*2;j++){
//            for (int t=0;t<3;t++){
//                dp[i][j][t]=0;
//            }
//        }
        for (int j=-i*(i+1)/2;j<=i*(i+1)/2;j++){
            dp[(i+1)%2][j+Z][0]=0;
            for (int k=-i;k<0;k++){
                dp[(i+1)%2][j+Z][0]+=tot[i%2][j-k+Z]*(i-abs(k)+1ll);
                dp[(i+1)%2][j+Z][0]%=mod;
            }
            dp[(i+1)%2][j+Z][1]=tot[i%2][j+Z]*(i+1ll)%mod;

            dp[(i+1)%2][j+Z][2]=0;
            for (int k=1;k<=i;k++){
                dp[(i+1)%2][j+Z][2]+=tot[i%2][j-k+Z]*(i-abs(k)+1ll);
                dp[(i+1)%2][j+Z][2]%=mod;
            }
            tot[(i+1)%2][j+Z]=(dp[(i+1)%2][j+Z][0]+dp[(i+1)%2][j+Z][1]+dp[(i+1)%2][j+Z][2])%mod;
        }
        for (int j=1;j<=i*(i+1)/2;j++){
            res+=((dp[(i+1)%2][j+Z][0]*C[n][i+1]%mod)*f[n-i-1])%mod;
            res%=mod;
        }
//        if (i==1) cout<<(dp[(i+1)%2][Z-1][0])<<endl;
    }

    cout<<res<<endl;


}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;


    while (tt--){
        solve();
    }
    return 0;
}
//3 1 2
//2 3 1
//(f[n]/f[l])*dp[>0][2]