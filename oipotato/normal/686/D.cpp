#include<cstdio>
#include<algorithm>
using namespace std;
int n,q,head[300010],next[300010],to[300010],ans[300010],fa[300010],size[300010],num,x;
void add(int x,int y){next[++num]=head[x];to[head[x]=num]=y;}
void dfs(int p)
{
	size[p]=1;
	int maxs=0,maxp;
	for(int i=head[p];i;i=next[i])
	{
		dfs(to[i]);
		if(size[to[i]]>maxs)maxs=size[to[i]],maxp=to[i];
		size[p]+=size[to[i]];
	}
	if(!maxs){ans[p]=p;return;}
	ans[p]=ans[maxp];
	for(;!(size[p]-size[ans[p]]<=size[p]/2);ans[p]=fa[ans[p]]);
}
int main()
{
	//freopen("4.in","r",stdin);
	//freopen("4.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=2;i<=n;i++){scanf("%d",&fa[i]);add(fa[i],i);}
	dfs(1);
	for(int i=1;i<=q;i++)
	{
		scanf("%d",&x);
		printf("%d\n",ans[x]);
	}
	return 0;
}