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
inline bool solve(long long a,long long b){
    //a>=b;
    if(b==0)return 0;
    if(!solve(b,a%b))return 1;
    long long x=0;
    a/=b;
    if(b%2==1)return !(a%2);
    a--;
    a%=(b+1);
    if(a==b)return 1;
    return a%2;
}
int dp[5000];
int dp2[5000];
int main(){
    int t,i,j;
    dp[0]=1;
    int x=11;
    for(i=1;i<5000;i++){
        for(j=1;j<=x&&j<=i;j*=x)if(dp[i-j]==0)break;
        if(j<=i&&j<=x){
            dp[i]=1;
        }else{
            dp[i]=0;
        }
    }
    dp2[0]=1;
    for(i=1;i<5000;i++){
        for(j=1;j<=i;j*=x)if(dp2[i-j]==0)break;
        if(j<=i){
            dp2[i]=1;
        }else{
            dp2[i]=0;
        }
        if(dp2[i]!=dp[i])printf("%d\t",i);
    }
    scanf("%d",&t);
    while(t--){
        long long a,b;
        scanf("%I64d%I64d",&a,&b);
        if(a<b)swap(a,b);
        puts(solve(a,b)?"First":"Second");
    }
}