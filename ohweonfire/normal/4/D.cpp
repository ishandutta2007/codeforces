#include<cstdio>
using namespace std;
const int maxn=5005;
int dp[maxn],w[maxn],h[maxn],n,p[maxn];
int dfs(int i)
{
	if(dp[i])return dp[i];
	int best=0;
	for(int j=1;j<=n;j++)
		if(w[i]<w[j]&&h[i]<h[j])
		{
			int t=dfs(j);
			if(t>best)
			{
				best=t;
				p[i]=j;
			}
		}
	return dp[i]=best+1;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<=n;i++)scanf("%d%d",w+i,h+i);
	dfs(0);
	printf("%d\n",dp[0]-1);
	int t=p[0];
	while(t!=0)
	{
		printf("%d ",t);
		t=p[t];
	}
	return 0;
}