//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=410;
const int A=1000001;
const ll mod=998244353;
ll dp[N][N][2][2];

ll dp1[2][N][N][3][3];
int c[27];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=26;i++) cin>>c[i];
    ll res=26ll*26ll;
    for (int i=3;i<=n;i++){
        res*=25ll;
        res%=mod;
    }

    for (int i=0;i<2;i++){
        for (int j=0;j<2;j++){
            int cn=(i==1)+(j==1);
            dp[2][cn][i][j]=1ll;
            for (int t=1;t<=2-cn;t++){
                dp[2][cn][i][j]*=25ll;
                dp[2][cn][i][j]%=mod;
            }
        }
    }
    for (int i=2;i<n;i++){
        for (int j=0;j<=i;j++){
            for (int x=0;x<2;x++){
                for (int y=0;y<2;y++){
//                    cout<<"OK\n";
                    if (!x){
                        dp[i+1][j+1][y][1]=(dp[i+1][j+1][y][1]+dp[i][j][x][y])%mod;
                    }
                    dp[i+1][j][y][0]=(dp[i+1][j][y][0]+dp[i][j][x][y]*(24ll+x))%mod;
                }
            }
        }
    }
    for (int i=1;i<=26;i++){
        for (int j=c[i]+1;j<=n;j++){
            ll sum=0ll;
            for (int x=0;x<2;x++){
                for (int y=0;y<2;y++){
                    sum+=dp[n][j][x][y];
                    res+=mod-dp[n][j][x][y];
                    res%=mod;
                }
            }
        }
    }
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            int cn1=(i==1)+(j==1);
            int cn2=(i==2)+(j==2);
            dp1[0][cn1][cn2][i][j]=1ll;
            for (int t=1;t<=2-cn1-cn2;t++){
                dp1[0][cn1][cn2][i][j]*=24ll;
                dp1[0][cn1][cn2][i][j]%=mod;
            }
        }
    }
    for (int i=2;i<n;i++){
        for (int j=0;j<=i;j++){
            for (int t=0;t+j<=i;t++){
                for (int x=0;x<3;x++){
                    for (int y=0;y<3;y++){
                        dp1[(i+1)%2][j][t][x][y]=0ll;
                    }
                }
            }
        }
        for (int j=0;j<=i;j++){
            for (int t=0;t+j<=i;t++){
                for (int x=0;x<3;x++){
                    for (int y=0;y<3;y++){
                        if (x!=1){
                            dp1[(i+1)%2][j+1][t][y][1]=(dp1[(i+1)%2][j+1][t][y][1]+dp1[i%2][j][t][x][y])%mod;
                        }
                        if (x!=2){
                            dp1[(i+1)%2][j][t+1][y][2]=(dp1[(i+1)%2][j][t+1][y][2]+dp1[i%2][j][t][x][y])%mod;
                        }
                        dp1[(i+1)%2][j][t][y][0]=(dp1[(i+1)%2][j][t][y][0]+dp1[i%2][j][t][x][y]*(23ll+(x>0)))%mod;
                    }
                }
            }
        }
    }
    for (int i=1;i<=26;i++){
        for (int j=i+1;j<=26;j++){
            for (int cn1=c[i]+1;cn1<=n;cn1++){
                for (int cn2=c[j]+1;cn1+cn2<=n;cn2++){
                    for (int x=0;x<3;x++){
                        for (int y=0;y<3;y++){
                            res+=dp1[n%2][cn1][cn2][x][y];
//                            cout<<dp1[n%2][cn1][cn2][x][y]<<endl;
                            res%=mod;
                        }
                    }

                }
            }
        }
    }
    cout<<res<<endl;


}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;

    while (tt--){
        solve();
    }
    return 0;
}
//aabbaa
//
//abcabc
/**
6
2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2
2 2 2 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
**/