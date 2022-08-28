#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
using namespace std;
inline int read()
{
	int x=0,ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch))
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x;
}
struct pt
{
	int v[1505],id;
}a[1505],b[1505];
int n,m,deg[1505],vis[1505],q[100005],head,tail;
bool cmp(const pt x,const pt y)
{
	for(int i=1;i<=tail;i++)
		if(x.v[q[i]]!=y.v[q[i]])
			return x.v[q[i]]<y.v[q[i]];
	return x.id<y.id;
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			a[i].v[j]=read();
		a[i].id=i;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			b[i].v[j]=read();
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<n;j++)
			if(b[j].v[i]>b[j+1].v[i])
				deg[i]++;
		if(!deg[i]) q[++tail]=i;
	}
	while(head<tail)
	{
		head++;
		int u=q[head];
		for(int j=1;j<n;j++)
			if(b[j].v[u]<b[j+1].v[u]&&!vis[j])
			{
				vis[j]=1;
				for(int i=1;i<=m;i++)
					if(b[j].v[i]>b[j+1].v[i])
					{
						deg[i]--;
						if(!deg[i]) q[++tail]=i;
					}
			}
	}
/*	if(n==1500)
	{
		printf("tail=%d\n",tail);
		return 0;
	}*/
	sort(a+1,a+n+1,cmp);
	int fl=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i].v[j]!=b[i].v[j]) fl=0;
	if(!fl)
	{
		printf("-1\n");
		return 0;
	}
	printf("%d\n",tail);
	for(int i=tail;i;i--)
		printf("%d ",q[i]);
	return 0;
}