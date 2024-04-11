#include<cstdio>
#include<algorithm>
using namespace std;
int par[100010],n,m,a[100010],x,y;
long long ans;
bool v[100010];
int find(int x){return x==par[x]?x:par[x]=find(par[x]);}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		par[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		x=find(x);y=find(y);
		par[x]=y;
	}
	for(int i=1;i<=n;i++)
	{
		a[find(i)]=min(a[find(i)],a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(!v[find(i)])
		{
			ans+=a[find(i)];
			v[find(i)]=1;
		}
	}
	printf("%I64d\n",ans);
	return 0;
}