#include<bits/stdc++.h>
#define inf 100000000
using namespace std;
int n,dp[3][80][80][80],qz[3][80],ys[3][80],ans;
char ch[80];
int main(){
	scanf("%d",&n);
	scanf("%s",ch);
	int tmp,mi;
	for (int i=0;i<3;i++)
	for (int j=0;j<=n;j++)
	for (int k=0;k<=n;k++)
	for (int h=0;h<=n;h++) dp[i][j][k][h]=inf;
	for (int i=0;i<=n;i++)
	for (int j=0;j<3;j++) ys[j][i]=-1;
	for (int i=0;i<n;i++){
		if (i) for (int j=0;j<3;j++) qz[j][i]=qz[j][i-1];
		if (ch[i]=='V') tmp=0;
		else if (ch[i]=='K') tmp=1;
		else tmp=2;
		qz[tmp][i]++;
		ys[tmp][qz[tmp][i]]=i;
	}
	if (ys[0][1]!=-1) dp[0][1][1][0]=qz[1][ys[0][1]]+qz[2][ys[0][1]];
	if (ys[1][1]!=-1) dp[1][1][0][1]=qz[0][ys[1][1]]+qz[2][ys[1][1]];
	if (ys[2][1]!=-1) dp[2][1][0][0]=qz[0][ys[2][1]]+qz[1][ys[2][1]];
	for (int i=1;i<n;i++)
	for (int j=0;j<=i;j++)
	for (int k=0;k<=i-j;k++){
		if (ys[0][j+1]!=-1){
			tmp=ys[0][j+1];
			mi=min(dp[0][i][j][k],min(dp[1][i][j][k],dp[2][i][j][k]));
			dp[0][i+1][j+1][k]=min(dp[0][i+1][j+1][k],mi+max(0,qz[1][tmp]-k)+max(0,qz[2][tmp]-i+j+k));
		}
		if (ys[1][k+1]!=-1){
			tmp=ys[1][k+1];
			mi=min(dp[1][i][j][k],dp[2][i][j][k]);
			dp[1][i+1][j][k+1]=min(dp[1][i+1][j][k+1],mi+max(0,qz[0][tmp]-j)+max(0,qz[2][tmp]-i+j+k));
		}
		if (ys[2][i-j-k+1]!=-1){
			tmp=ys[2][i-j-k+1];
			mi=min(dp[0][i][j][k],min(dp[1][i][j][k],dp[2][i][j][k]));
			dp[2][i+1][j][k]=min(dp[2][i+1][j][k],mi+max(0,qz[0][tmp]-j)+max(0,qz[1][tmp]-k));
		}
	}

	ans=inf;
	for (int i=0;i<=n;i++)
	for (int j=0;j<=n-i;j++)
	for (int k=0;k<3;k++)ans=min(ans,dp[k][n][i][j]);
	printf("%d\n",ans);
}