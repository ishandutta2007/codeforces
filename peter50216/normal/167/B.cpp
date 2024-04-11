#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
double dp[210][210][410];
double pi[210];
int ai[210];
int main(){
    int n,l,k,i,j,q,w;
    scanf("%d%d%d",&n,&l,&k);
    for(i=1;i<=n;i++){
        int p;
        scanf("%d",&p);
        pi[i]=p/100.0;
    }
    for(i=1;i<=n;i++)scanf("%d",&ai[i]);
    if(k>n)k=n;
    dp[0][0][n+k]=1;
    for(i=1;i<=n;i++){
        for(j=0;j<i;j++){
            for(q=-n;q<=n;q++){
                dp[i][j][q+n]+=dp[i-1][j][q+n]*(1-pi[i]);
                if(ai[i]==-1){
                    dp[i][j+1][q+n-1]+=dp[i-1][j][q+n]*pi[i];
                }else{
                    int r=q+ai[i];
                    if(r>n)r=n;
                    dp[i][j+1][r+n]+=dp[i-1][j][q+n]*pi[i];
                }
            }
        }
    }
    /*for(i=0;i<=n;i++){
        for(j=0;j<=i;j++){
            for(q=-n;q<=n;q++){
                printf("%d %d %d %.10lf\n",i,j,q,dp[i][j][q+n]);
            }
        }
    }*/
    double ans=0;
    for(i=l;i<=n;i++){
        for(j=0;j<=n;j++){
            ans+=dp[n][i][j+n];
        }
    }
    printf("%.10lf\n",ans);
}