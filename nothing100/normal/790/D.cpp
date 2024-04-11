#include<bits/stdc++.h>
#define LL long long
#define inf 100000000
using namespace std;
int n,ans,a[2][300010],ne[2][2][300010],nem[2][2][300010];
pair<int,int> dp[2][300010];
map<LL,int> pre[2][2];
int main(){
	scanf("%d",&n);
	for (int j=0;j<2;j++)
	for (int i=1;i<=n;i++) scanf("%d",&a[j][i]);
	for (int i=0;i<2;i++)
	for (int j=i;j<2;j++){
		LL now=0;
		pre[i][j][0]=n+1;
		for (int k=n;k;k--){
			for (int h=i;h<=j;h++) now+=a[h][k];
			if (pre[i][j].count(now)) ne[i][j][k]=pre[i][j][now]-1;
			else ne[i][j][k]=n+1;
			pre[i][j][now]=k;
		}
		nem[i][j][n]=n+1;
		for (int k=n-1;k>=0;k--)nem[i][j][k]=min(nem[i][j][k+1],ne[i][j][k+1]);
	}
	for (int i=0;i<=n;i++)
	for (int j=0;j<2;j++){
		ans=max(ans,dp[j][i].first);
		int o=dp[j][i].first,p=nem[j^1][j^1][dp[j][i].second],t=i;
		o++;
		if (p>=i&&(dp[j^1][p].first<o||(dp[j^1][p].first==o&&dp[j^1][p].second>i))) dp[j^1][p]=make_pair(o,i);
		t=nem[j][j][i]; p=dp[j][i].second;
		if (dp[j][t].first<o||(dp[j][t].first==o&&dp[j][t].second>p)) dp[j][t]=make_pair(o,p);
		t=p=nem[0][1][i];
		if (dp[0][t].first<o||(dp[0][t].first==o&&dp[0][t].second>p)) dp[0][t]=make_pair(o,p);
		if (dp[1][t].first<o||(dp[1][t].first==o&&dp[1][t].second>p)) dp[1][t]=make_pair(o,p);
	}
	printf("%d\n",ans);
}