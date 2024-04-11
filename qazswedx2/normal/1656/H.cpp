#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
using namespace std;
typedef __int128 ll;
inline ll read()
{
	ll x=0;
	int ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch))
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x;
}
void print(ll x)
{
	if(x>=10) print(x/10);
	printf("%d",(int)(x%10));
}
ll gcd(ll a,ll b)
{
	if(!b) return a;
	return gcd(b,a%b);
}
ll lcm(ll a,ll b)
{
	return a/gcd(a,b)*b;
}
struct SGT
{
	ll sum[4005];
	void pushup(int x)
	{
		sum[x]=lcm(sum[x*2],sum[x*2+1]);
	}
	void build(int x,int l,int r)
	{
		if(l==r)
		{
			sum[x]=1;
			return;
		}
		int mid=(l+r)/2;
		build(x*2,l,mid);
		build(x*2+1,mid+1,r);
		pushup(x);
	}
	void modify(int x,int l,int r,int qx,ll v)
	{
		if(l>qx||r<qx) return;
		if(l==r)
		{
			sum[x]=v;
			return;
		}
		int mid=(l+r)/2;
		modify(x*2,l,mid,qx,v);
		modify(x*2+1,mid+1,r,qx,v);
		pushup(x);
	}
}T[2][1005];
int TT,n,m,vis[2][1005];
ll a[100005],b[100005];
int main()
{
	scanf("%d",&TT);
	while(TT--)
	{
		memset(vis,0,sizeof(vis));
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			a[i]=read(),T[0][i].build(1,1,m);
		for(int j=1;j<=m;j++)
			b[j]=read(),T[1][j].build(1,1,n);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				ll x=gcd(a[i],b[j]);
				T[0][i].modify(1,1,m,j,x);
				T[1][j].modify(1,1,n,i,x);
			}
		int cnta=0,cntb=0;
		while(1)
		{
			int fl=0;
			for(int i=1;i<=n;i++)
			{
				if(!vis[0][i]&&T[0][i].sum[1]!=a[i])
				{
					for(int j=1;j<=m;j++)
					{
						T[1][j].modify(1,1,n,i,1);
					}
					fl=1;
					vis[0][i]=1;
					cnta++;
				}
			}
			for(int j=1;j<=m;j++)
			{
				if(!vis[1][j]&&T[1][j].sum[1]!=b[j])
				{
					for(int i=1;i<=n;i++)
					{
						T[0][i].modify(1,1,m,j,1);
					}
					fl=1;
					vis[1][j]=1;
					cntb++;
				}
			}
			if(!fl) break;
		}
		if(cnta==n||cntb==m)
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		printf("%d %d\n",n-cnta,m-cntb);
		for(int i=1;i<=n;i++)
			if(!vis[0][i]) print(a[i]),printf(" ");
		printf("\n");
		for(int i=1;i<=m;i++)
			if(!vis[1][i]) print(b[i]),printf(" ");
		printf("\n");
	}
	return 0;
}