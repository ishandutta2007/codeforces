#include<bits/stdc++.h>
using namespace std;
int t,n,dp[100010],a[11];
int dfs(int x,int y){
	if (x==n) return 0;
	if (y==a[x]) return 1;
	int res=0;
	res|=dfs(x+1,y+a[x]);
	res|=dfs(x+1,y-a[x]);
	res|=dfs(x+1,y);
	return res;
}
int main(){
	scanf("%d",&t);
	while (t--){
		memset(dp,0,sizeof(dp));
		scanf("%d",&n);
		dp[0]=1;
		for (int i=0;i<n;i++)
			scanf("%d",&a[i]);
		if (dfs(0,0)) printf("YES\n");
		else printf("NO\n");
	}
}