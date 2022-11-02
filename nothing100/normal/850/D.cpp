 #include<bits/stdc++.h>
 using namespace std;
 int m,a[33],dp[65][35][2020],edge[65][65],jo[65],ans,que[65];
 int cmp(int x,int y){
 	return jo[x]>jo[y];
}
 void dfs(int x,int y,int z){
 	if (x==0) return;
 	jo[x]=ans-1-a[dp[x][y][z]];
 	//printf("%d %d\n",x,jo[x]);
	dfs(x-1,dp[x][y][z],z-a[dp[x][y][z]]);
	int tmp=a[dp[x][y][z]];
	for (int i=1;i<x;i++)
	if (!edge[i][x]) edge[x][i]=1,tmp--;
	for (int i=x+1;i<=ans;i++) que[i-x-1]=i;
	sort(que,que+ans-x,cmp);
	for (int i=0;i<tmp;i++){
		edge[x][que[i]]=1;
		jo[que[i]]--;
	}
}
 int main(){
 	scanf("%d",&m);
 	for (int i=1;i<=m;i++) scanf("%d",&a[i]);
 	sort(a+1,a+m+1);
 	dp[0][1][0]=1;
 	for (int i=0;i<2*a[m]+4;i++){
 		for (int j=1;j<=m;j++)
 		for (int k=(i)*(i-1)/2;k<=a[m]*i;k++)
 		if (dp[i][j][k]){
 			dp[i+1][j][k+a[j]]=j;
 			dp[i+1][j+1][k+a[j]]=j;
 		}
 	}
 	for (int i=1;i<2*a[m]+4;i++)
 	if (dp[i][m+1][(i-1)*i/2]){
 		ans=i;
 		dfs(i,m,(i-1)*i/2);
 		printf("%d\n",i);
 		for (int j=i;j>=1;j--){
 			for (int k=i;k>=1;k--) printf("%d",edge[j][k]);
 			printf("\n");
 		}
 		return 0;
 	}
 	printf("=(\n");
}