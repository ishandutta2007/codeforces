#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int dp[2][2][201];
int main(){
	int n;scanf("%d",&n);int cr=0;
	for(int j=0;j<=200;j++)dp[0][1][j]=1;
	for(int i=0;i<n;i++){
		cr^=1;
		for(int j=0;j<2;j++)for(int k=0;k<=200;k++)dp[cr][j][k]=0;
		int x;scanf("%d",&x);
		for(int j=1;j<=200;j++){
			if(x!=-1&&j!=x)continue;
			dp[cr][0][j]=dp[cr^1][0][200]-dp[cr^1][0][j-1];
			if(dp[cr][0][j]<0)dp[cr][0][j]+=mod;
			dp[cr][0][j]+=dp[cr^1][1][j]-dp[cr^1][1][j-1];
			if(dp[cr][0][j]<0)dp[cr][0][j]+=mod;
			if(dp[cr][0][j]>=mod)dp[cr][0][j]-=mod;
			for(int k=0;k<2;k++){
				dp[cr][1][j]+=dp[cr^1][k][j-1];
				if(dp[cr][1][j]>=mod)dp[cr][1][j]-=mod;
			}
		}
		for(int k=0;k<2;k++)for(int j=1;j<=200;j++){
			dp[cr][k][j]+=dp[cr][k][j-1];
			if(dp[cr][k][j]>=mod)dp[cr][k][j]-=mod;
		}
	}
	printf("%d\n",dp[cr][0][200]);
}