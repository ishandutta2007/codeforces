#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int mod;
inline int addmod(int x)
{
	return x>=mod?x-mod:x;
}
inline int submod(int x)
{
	return x<0?x+mod:x;
}
int fpow(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=1ll*ans*x%mod;
		x=1ll*x*x%mod;
		y/=2;
	}
	return ans;
}
int n,m,f[100005],g[205][205],pt,a[100005];
char s[205][205];
int gauss()
{
	int ans=1,fl=1;
	for(int i=1;i<=pt;i++)
	{
		int nw=i;
		while(nw<=pt&&g[nw][i]==0) nw++;
		if(nw>pt) return 0;
		if(nw!=i)
		{
			fl*=-1;
			for(int j=1;j<=pt;j++)
				swap(g[i][j],g[nw][j]);
		}
		for(int j=i+1;j<=pt;j++)
		{
			int mul=1ll*g[j][i]*fpow(g[i][i],mod-2)%mod;
			for(int k=i;k<=pt;k++)
				g[j][k]=submod(g[j][k]-1ll*g[i][k]*mul%mod);
		}
	}
	for(int i=1;i<=pt;i++)
		ans=1ll*ans*g[i][i]%mod;
	if(fl==-1) ans=(mod-ans)%mod;
	return ans;
}
void add(int u,int v)
{
//	printf("add:u=%d,v=%d\n",u,v);
	g[u][u]=addmod(g[u][u]+1);
	g[v][v]=addmod(g[v][v]+1);
	g[u][v]=submod(g[u][v]-1);
	g[v][u]=submod(g[v][u]-1);
}
#define id(x,y) ((x)*(m+1)+(y)+1)
int find(int x)
{
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void link(int x,int y)
{
//	printf("link:x=%d,y=%d\n",x,y);
	x=find(x),y=find(y);
	if(x==y) return;
	f[x]=y;
}
int main()
{
	scanf("%d%d%d",&n,&m,&mod);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf(" %c",&s[i][j]);
	for(int i=1;i<=(n+1)*(m+1);i++)
		f[i]=i;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(s[i][j]=='/') link(id(i,j-1),id(i-1,j));
			else if(s[i][j]=='\\') link(id(i-1,j-1),id(i,j));
	int ans=0;
	pt=0;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
			if((i+j)%2==0)
			{
				int nw=id(i,j);
				if(f[nw]==nw)
					a[nw]=++pt;
			}
	if(pt<=201)
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(s[i][j]=='*')
				{
					if((i+j)%2==0) add(a[find(id(i-1,j-1))],a[find(id(i,j))]);
					else add(a[find(id(i-1,j))],a[find(id(i,j-1))]);
				}
		pt--;
		ans=addmod(ans+gauss());
	}
	//printf("ans=%d\n",ans);
	memset(g,0,sizeof(g));
	pt=0;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
			if((i+j)%2==1)
			{
				int nw=id(i,j);
				if(f[nw]==nw)
					a[nw]=++pt;
			}
	if(pt<=201)
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(s[i][j]=='*')
				{
					if((i+j)%2==1) add(a[find(id(i-1,j-1))],a[find(id(i,j))]);
					else add(a[find(id(i-1,j))],a[find(id(i,j-1))]);
				}
		pt--;
		ans=addmod(ans+gauss());
	}
	printf("%d\n",ans);
	return 0;
}