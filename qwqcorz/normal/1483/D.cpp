#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=6e2+5;

ll read()
{
	ll s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(ll x)
{
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x<10) putchar(x+'0');
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
}
void print(ll x,char c='\n')
{
	write(x);
	putchar(c);
}
ll e[N][N],dis[N][N],l[N][N],Max[N][N];

signed main()
{
	memset(e,0x3f,sizeof(e));
	memset(l,0xc0,sizeof(l));
	memset(Max,0xc0,sizeof(Max));
	ll n=read(),m=read(),ans=0;
	for (ll i=1;i<=m;i++)
	{
		ll u=read(),v=read(),w=read();
		e[u][v]=e[v][u]=w;
	}
	ll q=read();
	for (ll i=1;i<=q;i++)
	{
		ll u=read(),v=read(),w=read();
		l[u][v]=l[v][u]=w;
	}
	memcpy(dis,e,sizeof(dis));
	for (ll k=1;k<=n;k++) dis[k][k]=0;
	for (ll k=1;k<=n;k++)
	for (ll i=1;i<=n;i++)
	for (ll j=1;j<=n;j++)
	dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for (ll u=1;u<=n;u++)
	for (ll y=1;y<=n;y++)
	for (ll v=1;v<=n;v++)
	Max[u][y]=max(Max[u][y],l[u][v]-dis[y][v]);
	for (ll x=1;x<=n;x++)
	for (ll y=x+1;y<=n;y++)
	{
		bool flag=0;
		for (ll u=1;u<=n;u++)
		flag|=Max[u][y]>=dis[u][x]+e[x][y];
		ans+=flag;
	}
	print(ans);

	return 0;
}