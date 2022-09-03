#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
struct edge{
	int u,v,id;
	double dist;
	void scan()
	{
		scanf("%d%d%lf",&u,&v,&dist);
	}
	bool operator <(const edge &b)const
	{
		return dist<b.dist;
	}
}es[maxn];
bool cmp(edge x,edge y)
{
	return x.id<y.id;
}
int n,m,k;
int ans[5005],sz;
int f[5005];
int gf(int x)
{
	if(f[x]==x)return x;
	return f[x]=gf(f[x]);
}
int check(double x)
{
	for(int i=1;i<=m;i++)
		if(es[i].u==1||es[i].v==1)
			es[i].dist+=x;
	sort(es+1,es+m+1);
	for(int i=1;i<=n;i++)f[i]=i;
	int ret=0;
	sz=0;
	for(int i=1;i<=m;i++)
	{
		int x=gf(es[i].u),y=gf(es[i].v);
		if(x==y)continue;
		f[x]=y;
		if(es[i].u==1||es[i].v==1)ret++;
		ans[++sz]=es[i].id;
	}
	for(int i=1;i<=m;i++)
		if(es[i].u==1||es[i].v==1)
			es[i].dist-=x;
	sort(es+1,es+m+1,cmp);
	return ret;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		es[i].scan();
		es[i].id=i;
	}
	double l=-10000000.0,r=10000000.0;
	for(int i=1;i<=100;i++)
	{
		double mid=(l+r)/2;
		int tt=check(mid);
		if(tt==k)
		{
			printf("%d\n",sz);
			for(int i=1;i<=sz;i++)printf("%d ",ans[i]);
			return 0;
		}
		if(tt<k)r=mid;
		else l=mid;
	}
	puts("-1");
	return 0;
}