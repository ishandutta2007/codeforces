#include<bits/stdc++.h>
#define MAXN 200010
#define inf 1000000000
#define LL long long
using namespace std;
LL n,ans,dp[110][110][2];
LL solve(int x,int y,int z,LL tot){
    for (int i=0;i<=x;i++)
    for (int j=0;j<2;j++) dp[0][i][j]=0;
    dp[0][0][0]=1;
    for (int i=0;(1LL<<i)<=tot;i++){
        for (int j=0;j<=x;j++)
        for (int k=0;k<2;k++) dp[i+1][j][k]=0;
        for (int j=0;j<2;j++)
        for (int k=0;k<2;k++){
            if ((i>=y&&j)||(i>=z&&k)) continue;
            for (int h=0;h<2;h++){
                if (((j+k+h)&1)!=((tot>>i)&1)) continue;
                for (int g=0;g<=x-k-j;g++){
                    dp[i+1][g+k+j][(j+k+h)/2]+=dp[i][g][h];
                }
            }
        }
        if ((1LL<<i)>(tot>>1)) return dp[i+1][x][0];
    }
    return dp[0][x][0];
}
int main(){
    scanf("%lld",&n);
    for (int i=0;i<50;i++)
    for (int j=0;j<50;j++){
        LL a=(1LL<<(i+1))+(1LL<<(j+1))-3;
        if (n<a) continue;
        LL rest=n-n/a*a-(1LL<<j)+1;
        for (int k=0;k<=i+j;k++){
            if ((rest+k<0)||(rest+k)%2) continue;
            ans+=solve(k,max(i-1,0),max(j-1,0),(rest+k)/2);
        }
    }
    printf("%lld\n",ans);
}