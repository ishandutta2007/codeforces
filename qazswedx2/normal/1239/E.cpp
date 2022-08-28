#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,sum,a[105],tans[2][105],t1,t2,ans=1e9,p[4];
bool f[25][2500005],g[25][2500005];
void dfs(int dep,int lim,int fl,int sum,int ct)
{
	if(dep==lim+1)
	{
		if(!fl) f[ct][sum]=1;
		else g[ct][sum]=1;
		return;
	}
	dfs(dep+1,lim,fl,sum,ct);
	dfs(dep+1,lim,fl,sum+a[dep],ct+1);
}
int b[105],b2[105],ffl=0;
void dfs2(int dep,int lim,int c,int s,int sum,int ct,int ct2)
{
	if(dep==lim+1)
	{
		if(ct==c&&sum==s)
		{
			for(int i=1;i<=ct;i++)
				tans[0][++t1]=b[i];
			for(int i=1;i<=ct2;i++)
				tans[1][++t2]=b2[i];
			ffl=1;
		}
		return;
	}
	b2[ct2+1]=a[dep];
	dfs2(dep+1,lim,c,s,sum,ct,ct2+1);
	if(ffl) return;
	b[ct+1]=a[dep];
	dfs2(dep+1,lim,c,s,sum+a[dep],ct+1,ct2);
}
void upd(int i,int a,int j,int b)
{
	if(max(a+b,sum-(a+b))<ans)
	{
		ans=max(a+b,sum-(a+b));
		p[0]=i,p[1]=a,p[2]=j,p[3]=b;
	}
}
bool cmp(const int x,const int y)
{
	return x>y;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=2*n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+2*n+1);
	for(int i=3;i<=2*n;i++)
		sum+=a[i];
	dfs(3,n+1,0,0,0);
	dfs(n+2,2*n,1,0,0);
	for(int i=0;i<=n-1;i++)
	{
		int j=n-1-i;
		int nw=sum,las=1e9;
		for(int k=0;k<=sum;k++)
		{
			if(!f[i][k]) continue;
			while(nw&&nw+k>sum/2)
			{
				las=nw;
				nw--;
				while(nw&&!g[j][nw]) nw--;
			}
			if(g[j][nw]) upd(i,k,j,nw);
			upd(i,k,j,las);
		}
	}
	//printf("ans=%d,sum=%d,p=%d,%d,%d,%d\n",ans,sum,p[0],p[1],p[2],p[3]);
	t1=1;
	dfs2(3,n+1,p[0],p[1],0,0,0);
	ffl=0;
	dfs2(n+2,2*n,p[2],p[3],0,0,0);
	sort(tans[0]+2,tans[0]+n+1);
	sort(tans[1]+1,tans[1]+n,cmp);
	tans[0][1]=a[1];
	tans[1][n]=a[2];
	for(int i=0;i<=1;i++)
	{
		for(int j=1;j<=n;j++)
			printf("%d ",tans[i][j]);
		printf("\n");
	}
	return 0;
}