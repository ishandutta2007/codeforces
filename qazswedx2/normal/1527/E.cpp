#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,m,a[100005],L[100005],R[100005],vis[100005],c[100005][3],l,r;
ll nans,dp[105][100005];
void insl(int x)
{
	if(!c[a[x]][0])
	{
		c[a[x]][1]=c[a[x]][2]=x; 
	}
	else
	{
		nans+=c[a[x]][1]-x;
		c[a[x]][1]=x;
	}
	c[a[x]][0]++;
}
void insr(int x)
{
	if(!c[a[x]][0])
	{
		c[a[x]][1]=c[a[x]][2]=x; 
	}
	else
	{
		nans+=x-c[a[x]][2];
		c[a[x]][2]=x;
	}
	c[a[x]][0]++;
}
void dell(int x)
{
	c[a[x]][0]--;
	if(c[a[x]][0])
	{
		nans-=R[x]-x;
		c[a[x]][1]=R[x];
	}
}
void delr(int x)
{
	c[a[x]][0]--;
	if(c[a[x]][0])
	{
		nans-=x-L[x];
		c[a[x]][2]=L[x];
	}
}
void getans(int ql,int qr)
{
	while(r<qr) insr(++r);
	while(l>ql) insl(--l);
	while(r>qr) delr(r--);
	while(l<ql) dell(l++);
}
void solve(int L,int R,int ql,int qr,ll *f,ll *g)
{
	if(L>R) return;
	int mid=(L+R)/2;
	getans(ql,mid);
	int id=-1;
	for(int i=ql;i<=min(mid,qr);i++)
	{
	//	printf("solve:l=%d,r=%d,ql=%d,qr=%d,i=%d,mid=%d\n",l,r,ql,qr,i,mid);
		if(g[mid]>nans+f[i-1])
		{
			g[mid]=nans+f[i-1];
			id=i;
		}
		dell(l++);
	}
	solve(L,mid-1,ql,id,f,g);
	solve(mid+1,R,id,qr,f,g);
}
int main()
{
	memset(dp,0x3f,sizeof(dp));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		if(vis[a[i]])
		{
			R[vis[a[i]]]=i;
			L[i]=vis[a[i]];
		}
		vis[a[i]]=i;
	}
	dp[0][0]=0;
	for(int i=1;i<=m;i++)
	{
		l=1,r=0;
		for(int j=1;j<=n;j++)
			c[j][0]=c[j][1]=c[j][2]=0;
		nans=0;
		solve(1,n,1,n,dp[i-1],dp[i]);
		
	}
	printf("%lld\n",dp[m][n]);
	return 0;
}