#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<assert.h>
#include<stdarg.h>
#include<time.h>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
char x[1010],y[2010];
int a,b,k;
const int mod=1000000007;
long long dp[100100][2];
inline int solve(){
    if(a!=b){
        return 0;
    }
    int i,j;
    for(i=0;i<b;i++)y[i+b]=y[i];
    dp[0][0]=1;
    dp[0][1]=0;
    for(i=1;i<=k;i++){
        dp[i][0]=(dp[i-1][1]*(a-1))%mod;
        dp[i][1]=(dp[i-1][0]+dp[i-1][1]*(a-2))%mod;
    }
    long long ans=0;
    for(i=0;i<b;i++)if(strncmp(x,y+i,a)==0){
        ans=(ans+(i==0?dp[k][0]:dp[k][1]))%mod;
    }
    return ans;
}
int main(){
    scanf("%s%s%d",x,y,&k);
    a=strlen(x);b=strlen(y);
    printf("%d\n",solve());
}