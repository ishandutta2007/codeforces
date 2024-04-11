#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
inline int addmod(int x)
{
	return x>=mod?x-mod:x;
}
inline int submod(int x)
{
	return x<0?x+mod:x;
}
struct pt
{
	int a,b,id;
	bool operator<(const pt p) const
	{
		return a<p.a;
	}
}p[200005];
int n,m,c[200005],rk[200005],tmp[200005],rk2[200005],f[200005],g[200005],q[200005];
bool cmp(const int x,const int y)
{
	return p[x].b<p[y].b;
}
int sum[1000005],sum2[1000005];
inline int lowbit(int x)
{
	return x&-x;
}
void modify(int x,int v)
{
	for(int i=x;i;i-=lowbit(i))
		sum[i]=addmod(sum[i]+v);
}
int query(int x)
{
	int ans=0;
	for(int i=x;i<=n;i+=lowbit(i))
		ans=addmod(ans+sum[i]);
	return ans;
}
void modify2(int x,int v)
{
	for(int i=x;i;i-=lowbit(i))
		sum2[i]=max(sum2[i],v);
}
int query2(int x)
{
	int ans=0;
	for(int i=x;i<=n;i+=lowbit(i))
		ans=max(ans,sum2[i]);
	return ans;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&p[i].a,&p[i].b),p[i].id=i,c[i]=i;
	sort(p+1,p+n+1);
	sort(c+1,c+n+1,cmp);
	for(int i=1;i<=n;i++)
		rk[c[i]]=i,rk2[p[i].id]=i;
	for(int i=1;i<=n;i++)
	{
		int u=c[i];
		f[i]=addmod(1+query(u));
		modify(u,f[i]);
		g[i]=addmod(g[i-1]+f[i]);
		//printf("i=%d,a=%d,%d,%d,u=%d,f=%d,g=%d\n",i,p[u].a,p[u].b,p[u].id,u,f[i],g[i]);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&q[i]);
		q[i]=rk2[q[i]];
	}
	sort(q+1,q+m+1,cmp);
	//for(int i=1;i<=m;i++)
	//	printf("i=%d,q=%d,rk=%d\n",i,q[i],rk[q[i]]);
	int ans=0;//addmod(g[rk[q[m]]-1]+1);
	modify2(q[m],rk[q[m]]);
	for(int i=m-1;i>0;i--)
	{
		int u=q[i];
		int nw=query2(u);
		modify2(u,rk[u]);
/*		printf("ans=%d,u=%d,nw=%d,f=%d\n",ans,u,nw,f[rk[u]]);
		if(rk[u]<=nw) continue;
		ans=addmod(ans+f[rk[u]]);*/
	}
	for(int i=1;i<=n;i++)
		if(rk[i]<=query2(i))
			ans=addmod(ans+f[rk[i]]);
	printf("%d\n",ans);
	return 0;
}