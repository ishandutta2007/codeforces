#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
    int dp[10001]={0},k,n,m,o,t,u,v;
    scanf("%d%d%d%d%d%d%d",&k,&n,&m,&o,&t,&u,&v);
    for(int i=1;i<=k;i++){
        i>n?dp[i]=max(dp[i],dp[i-n]+t):0;
        i>m?dp[i]=max(dp[i],dp[i-m]+u):0;
        i>o?dp[i]=max(dp[i],dp[i-o]+v):0;
    }
    printf("%d\n",dp[k]+t+u+v);
}