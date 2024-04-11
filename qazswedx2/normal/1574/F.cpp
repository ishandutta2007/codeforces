#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
int n,m,k,L[1000005],R[1000005],vis[1000005],a[1000005];
int c[1000005],b[1000005][2],bt,f[1000005];
void dfs(int x)
{
	if(vis[x]) return;
	vis[x]=1;
	if(L[x]) dfs(L[x]);
	if(R[x]) dfs(R[x]);
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		int len;
		scanf("%d",&len);
		for(int j=1;j<=len;j++)
			scanf("%d",&a[j]);
		int fl=1;
		for(int j=2;j<=len;j++)
		{
			int u=a[j-1],v=a[j];
			if(vis[u]||vis[v]||(R[u]&&R[u]!=v)||(L[v]&&L[v]!=u))
			{
				fl=0;
				break;
			}
			R[u]=v,L[v]=u;
		}
		if(!fl)
		{
			for(int j=1;j<=len;j++)
				dfs(a[j]);
		}
	}
	for(int i=1;i<=k;i++)
	{
	//	printf("i=%d,L=%d,R=%d,vis=%d\n",i,L[i],R[i],vis[i]); 
		if(!vis[i]&&!L[i])
		{
			int u=i,ct=0;
			while(u)
			{
				ct++;
				u=R[u];
			}
		//	printf("i=%d,ct=%d\n",i,ct);
			c[ct]++;
		}
	}
	for(int i=1;i<=k;i++)
		if(c[i])
		{
			b[++bt][0]=i;
			b[bt][1]=c[i];
		}
/*	for(int j=1;j<=bt;j++)
		printf("(%d,%d) ",b[j][0],b[j][1]);
	printf("\n");*/
	f[0]=1;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=bt&&b[j][0]<=i;j++)
			f[i]=(f[i]+1ll*f[i-b[j][0]]*b[j][1])%mod;
	}
	printf("%d\n",f[m]);
	return 0;
}