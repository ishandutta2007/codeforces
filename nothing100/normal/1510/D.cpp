#include<bits/stdc++.h>
using namespace std;
double dp[100010][10]; 
int pre[100010][10],n,d,a[100010];
vector<int> ans;
int main(){
	scanf("%d%d",&n,&d);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	dp[0][1]=1;
	for (int i=0;i<n;i++){
		for (int j=0;j<10;j++){
			dp[i+1][j]=dp[i][j];
			pre[i+1][j]=j;
		}
		for (int j=0;j<10;j++)
		if (dp[i][j]>0.5){
			int tmp=j*a[i+1]%10;
			if (dp[i+1][tmp]<0.5||dp[i+1][tmp]<dp[i][j]+log(a[i+1])){
				dp[i+1][tmp]=dp[i][j]+log(a[i+1]);
				pre[i+1][tmp]=j;
			}
		}
	}
	for (int i=n;i;i--){
		if (dp[i][d]>0.5&&(pre[i][d]*a[i]%10)==d) ans.push_back(a[i]);
		d=pre[i][d];
	}
	if (ans.size()==0) printf("-1\n");
	else printf("%d\n",ans.size());
	for (int i=0;i<ans.size();i++) printf("%d ",ans[i]);
}