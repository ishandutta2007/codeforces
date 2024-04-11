#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a,b,mn[2000005],mx[2000005],cnt[2000005],vis[1005],m=20;
int c[1005],p[1005],rp[1005],t;
bool f[2000005];
char s[100005],ans[105];
bool check(int x)
{
	return 1ll*a*(mx[x]-mn[x]+1)<=1ll*cnt[x]*b;
}
bool cmp(const int x,const int y)
{
	return c[x]>c[y];
}
inline int lowbit(int x)
{
	return x&-x;
}
int main()
{
	memset(mn,0x3f,sizeof(mn));
	for(int i='a';i<='z';i++)
		vis[i]=1;
	vis['t']=vis['r']=vis['y']=vis['g']=vis['u']=vis['b']=0;
	for(int i='a';i<='z';i++)
		vis[i]+=vis[i-1];
	scanf("%d%d%d",&n,&a,&b);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
	{
		int u=vis[s[i]];
		c[u]=max(c[u],i);
	}
	for(int i=1;i<=m;i++)
		p[i]=i;
	sort(p+1,p+m+1,cmp);
	for(int i=1;i<=m;i++)
		rp[p[i]]=i;
	for(int i=1;i<=n;i++)
	{
		int u=(1<<(rp[vis[s[i]]]-1));
		mx[u]=max(mx[u],i);
		mn[u]=min(mn[u],i);
		cnt[u]++;
		//printf("i=%d,u=%d\n",i,u);
	}
	for(int i=1;i<(1<<m);i++)
	{
		int u=lowbit(i),v=i-u;
		if(!v) continue;
		mx[i]=max(mx[u],mx[v]);
		mn[i]=min(mn[u],mn[v]);
		cnt[i]=cnt[u]+cnt[v];
	}
	for(int i=1;i<(1<<m);i++)
	{
		if(lowbit(i)==i)
		{
			f[i]=check(i);
			continue;
		}
		if(check(i))
		{
			for(int j=1;j<=m;j++)
				if(i&(1<<(j-1)))
					f[i]|=f[i-(1<<(j-1))];
		}
		for(int j=1;j<=m;j++)
			f[i]|=f[i&((1<<j)-1)]&f[(i>>j)<<j];
	}
	for(int i='a';i<='z';i++)
	{
		int u=(1<<(rp[vis[i]]-1));
		if(vis[i]==vis[i-1]||!cnt[u]) continue;
		if(f[(1<<m)-1-u]) ans[++t]=i;
	}
	printf("%d ",t);
	for(int i=1;i<=t;i++)
		printf("%c ",ans[i]);
	return 0;
}