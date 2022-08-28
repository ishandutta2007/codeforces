#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,m,k,mat[105],g[105][105],vis[105],a[105][2],mn[105],id[105];
int tans[100005],t,f[105];
int dfs(int u)
{
	for(int i=1;i<=n;i++)
		if(!vis[i]&&g[u][i])
		{
			vis[i]=1;
			if(!mat[i]||dfs(mat[i]))
			{
				mat[i]=u;
			//	matl[u]=i;
				return 1;
			}
		}
	return 0;
}
int dfs2(int u)
{
	for(int i=1;i<=n;i++)
		if(!vis[i]&&g[u][i])
		{
			vis[i]=1;
			if(!mat[i]||dfs2(mat[i]))
				return 1;
		}
	return 0;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u][v]=1;
	}
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		dfs(i);
	}
	for(int i=1;i<=n;i++)
	{
		if(mat[i])
		{
			memset(vis,0,sizeof(vis));
			vis[i]=1;
			if(!dfs2(mat[i])) tans[++t]=-i;
			else tans[++t]=mat[i];
		//	printf("i=%d,mat=%d\n",i,mat[i]);
		}
	}
	mn[0]=2e9;
	for(int i=1;i<=k;i++)
		scanf("%d%d",&a[i][0],&a[i][1]);
	ll nww=0;
	for(int i=1;i<=n;i++)
	{
		mn[i]=mn[i-1],id[i]=id[i-1];
		if(mn[i]>a[i][1]) mn[i]=a[i][1],id[i]=i;
		nww+=a[i][0];
	}
	ll nans=0;
	ll ans=-1;
	int qid=-1;
	for(int i=1;i<n-t;i++)
	{
		ll nw=nww-a[i][0]+max(0ll,a[i][0]-1ll*t*a[i][1]);
		if(nw>ans)
		{
			ans=nw;
			qid=i;
		}
	}
	for(int i=n-t;i<=n;i++)
	{
		ll nw=nans+nww-a[i][0]+max(0ll,a[i][0]-1ll*(n-i)*a[i][1]);
		if(nw>ans)
		{
			ans=nw;
			qid=i;
		}
		nans-=mn[i];
	}
	if(qid<n-t)
	{
		f[qid]=t;
	}
	else
	{
		for(int i=n-t;i<qid;i++)
			f[id[i]]++;
		f[qid]+=(n-qid);
	}
/*	printf("k=%d,t=%d,qid=%d\n",k,t,qid);
	for(int i=1;i<=t;i++)
		printf("%d ",tans[i]);
	printf("\n");*/
	int sum=k;
	for(int i=1;i<=k;i++)
		sum+=f[i];
	printf("%d\n",sum);
	int p=0;
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=f[i];j++)
			printf("%d ",tans[++p]);
		printf("0 ");
	}
	return 0;
}