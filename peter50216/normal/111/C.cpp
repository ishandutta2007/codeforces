#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int dp[50][70][70];
const int INF=1000000000;
int n,m;
inline int lr(int np){
    int r=(1<<np);
    if(np!=n-1)r|=(1<<(np+1));
    if(np)r|=(1<<(np-1));
    return r;
}
inline void dfs(int np,int i,int j,int k,int c,int nc){
    if(np==n){
	dp[i][k][nc]=min(dp[i][k][nc],c);
	return;
    }
    dfs(np+1,i,j,k|lr(np),c+1,nc|(1<<np));
    if(j&(1<<np))dfs(np+1,i,j,k,c,nc);
}
inline int c2(int x,int y){
    int i,r=0;
    for(i=0;i<n;i++){
	if((x&(1<<i))==0){
	    x|=(1<<i);
	    y|=lr(i);
	    r++;
	}else if(i&&(y&(1<<(i-1)))==0){
	    x|=(1<<i);
	    y|=lr(i);
	    r++;
	}
    }
    if((y&(1<<(n-1)))==0)r++;
    return r;
}
inline int solve(){
    if(n>m)swap(n,m);
    if(n==1)return (m+2)/3;
    if(n==2)return m/2+1;
    int i,j,k;
    for(i=0;i<50;i++)for(j=0;j<70;j++)for(k=0;k<70;k++)dp[i][j][k]=INF;
    dp[0][(1<<n)-1][(1<<n)-1]=0;
    for(i=1;i<=m;i++){
	for(j=0;j<(1<<n);j++){
	    for(k=0;k<(1<<n);k++){
		if(dp[i-1][j][k]==INF)continue;
		dfs(0,i,j,k,dp[i-1][j][k],0);
	    }
	}
    }
    int ans=INF;
    for(j=0;j<(1<<n);j++)for(k=0;k<(1<<n);k++){
	if(dp[m][j][k]!=INF){
	    ans=min(ans,dp[m][j][k]+c2(j,k));
	   // printf("%d %d %d %d+%d %d\n",m,j,k,dp[m][j][k],c2(j,k),ans);
	}
    }
    return ans;
}
int main(){
    scanf("%d%d",&n,&m);
    printf("%d\n",n*m-solve());
}