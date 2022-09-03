#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod=1000000007;
int n,m,k;
int f[12][12],use[12],c[12][12],lowbit[1024];
int dfs(int x,int y)
{
	if(y==m+1)
	{
		x++;
		y=1;
	}
	if(x==n+1)return 1;
	int m=(f[x-1][y]|f[x][y-1]),w=-1,ret=0;
	for(int mask=((1<<k)-1)^m,i;mask;)
	{
		i=lowbit[mask];
		mask-=1<<i;
		if(c[x][y]!=-1&&c[x][y]!=i)continue;
		f[x][y]=m|(1<<i);
		use[i]++;
		if(use[i]==1)
		{
			if(w==-1)w=dfs(x,y+1);
			ret+=w;
		}
		else ret+=dfs(x,y+1);
		use[i]--;
		if(ret>=mod)ret-=mod;
	}
	return ret;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	if(n+m-1>k)
	{
		puts("0");
		return 0;
	}
	for(int i=2;i<(1<<k);i++)if(i&1)lowbit[i]=0;else lowbit[i]=lowbit[i>>1]+1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&c[i][j]);
			c[i][j]--;
			if(c[i][j]>-1)use[c[i][j]]++;
		}
	
	printf("%d\n",dfs(1,1));
	return 0;
}