#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
long long in[110];
long long dp[110][100010];
inline long long cnt(long long n,long long c){
    if(c==0)return 0;
    if(n==0)return 0;
    if(n<=100000&&dp[c][n]!=-1)return dp[c][n];
    long long r=cnt(n,c-1)-cnt(n/in[c-1],c-1)+n/in[c-1];
    if(n<=100000)dp[c][n]=r;
    return r;
}
int main(){
    memset(dp,-1,sizeof(dp));
    long long n;
    int k,i;
    scanf("%I64d%d",&n,&k);
    for(i=0;i<k;i++)scanf("%I64d",&in[i]);
    sort(in,in+k);
    printf("%I64d\n",n-cnt(n,k));
}