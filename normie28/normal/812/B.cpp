#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
 
bool Matrix[20][105];
int dp[20][2],Left[20],Right[20];
int N,M;
 
bool IsEmpty(int i){
    for(register int j=1;j<=M+2;++j)
        if(Matrix[i][j]) return false;
    return true;
}
 
int main(){
    scanf("%d%d",&N,&M);
    for(register int i=N;i>=1;--i){
        Left[i]=M+2;
        Right[i]=1;
        for(register int j=1;j<=M+2;++j){
            char c;cin>>c;
            Matrix[i][j]=(c=='0')?0:1;
            if(Matrix[i][j]==1){
                Left[i]=min(Left[i],j);
                Right[i]=max(Right[i],j);
            }
        }
    }
    while(N>1 && IsEmpty(N)) --N;
    if(N==1 && IsEmpty(N)){cout<<0<<endl;return 0;}
    dp[1][0]=0;dp[1][1]=0x3f3f3f3f;
    for(register int i=2;i<=N;++i){
        dp[i][0]=min(dp[i-1][0]+1+2*(Right[i-1]-1),dp[i-1][1]+1+M+1);
        dp[i][1]=min(dp[i-1][1]+1+2*(M+2-Left[i-1]),dp[i-1][0]+1+M+1);
    }
    int Ans=min(dp[N][0]+Right[N]-1,dp[N][1]+M+2-Left[N]);
    printf("%d\n",Ans);
    return 0;
}