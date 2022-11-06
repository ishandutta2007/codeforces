#include <cstdio>
int combi[4010][4010];
int m=1e9+7;
int n;
int dp1[4010];
int dp2[4010];

int main()
{
    combi[0][0]=1;
    int i,j;
    for(i=1;i<=4000;++i){
        for(j=1;j<i;++j) combi[i][j]=(combi[i-1][j-1]+combi[i-1][j])%m;
        combi[i][0]=combi[i][i]=1;
    }
    int n;
    scanf("%d",&n);
    dp1[0]=dp2[0]=1;
    for(i=1;i<=n;++i){
        dp1[i]=dp1[i-1];
        dp2[i]=dp2[i-1]*2ll%m;
        for(j=2;j<=n;++j){
            dp1[i]=(dp1[i]+dp1[i-j]*1ll*combi[i-1][j-1]%m)%m;
            dp2[i]=(dp2[i]+dp2[i-j]*1ll*combi[i-1][j-1]%m)%m;
        }
    }
    printf("%d\n",(0ll+dp2[n]-dp1[n]+m)%m);
    return 0;
}