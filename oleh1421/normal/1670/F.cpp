#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
using namespace std;
typedef long double ld;
typedef long long ll;
//#define int ll
const int N=3010;
const int L=60;
const ll mod=1000000007;
ll C[N][N];
ll dp[L+1][N][2][2];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,l,r,z;cin>>n>>l>>r>>z;
    C[0][0]=1;
    for (int i=1;i<=n;i++){
        C[i][0]=1;
        for (int j=1;j<=i;j++){
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
        }
    }
    dp[0][0][0][0]=1;
    for (int i=0;i<L;i++){
        int dL=l%2;
        int dR=r%2;
        int dZ=z%2;
        for (int add=0;add<=n;add++){
            for (int x=0;x<2;x++){
                for (int y=0;y<2;y++){
//                    cout<<i<<" "<<add<<" "<<x<<" "<<y<<" "<<dp[i][add][x][y]<<endl;
                    for (int cn=0;cn<=n;cn++){
                        int d=(cn+add)%2;
                        if (cn%2!=dZ) continue;
                        int nadd,nx=x,ny=y;
                        nadd=(add+cn)/2;
                        if (d>dL) nx=0;
                        else if (d<dL) nx=1;
                        if (d<dR) ny=0;
                        else if (d>dR) ny=1;
//                        if (i==1 && add==1 && x==1 && y==0 && cn==0) cout<<"AAAAA "<<nx<<" "<<ny<<" "<<nadd<<" "<<dp[i][add][x][y]<<" "<<C[n][cn]<<endl;
                        dp[i+1][nadd][nx][ny]+=dp[i][add][x][y]*C[n][cn];
                        dp[i+1][nadd][nx][ny]%=mod;

                    }

                }
            }
        }



        l/=2;
        r/=2;
        z/=2;
    }
    cout<<dp[L][0][0][0]<<endl;
    return 0;
}

/**
3 3
30 10 40
20 50 60
60 60 50

1001110110

1
5
1 2 4 2 1
4 2 2 1 1
  ,        .
**/