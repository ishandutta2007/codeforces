#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
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
int n,m,f[1000005],g[1000005];
int tans[1000005],t;
int find(int x)
{
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void link(int x,int y,int id)
{
	x=find(x),y=find(y);
	if(x==y) return;
	tans[++t]=id;
	f[x]=y;
//	g[y]|=g[x];
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m+1;i++)
		f[i]=i,g[i]=0;
	for(int i=1;i<=n;i++)
	{
		int k,x,y;
		scanf("%d",&k);
		if(k==1)
		{
			scanf("%d",&x);
			link(x,m+1,i);
		}
		else
		{
			scanf("%d%d",&x,&y);
			link(x,y,i);
		}
	}
	printf("%d %d\n",fpow(2,t),t);
	for(int i=1;i<=t;i++)
		printf("%d ",tans[i]); 
	return 0;
}