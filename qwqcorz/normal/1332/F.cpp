#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=3e5+5;
const ll p=998244353;

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
struct edge
{
	ll to,nxt;
}e[N*2];
ll head[N],cnt=0;
void add(ll u,ll v)
{
	e[++cnt].to=v;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
ll dp[N][2][2];//// 
void dfs(ll now,ll fa)
{
	ll tmp=1;
	dp[now][0][0]=dp[now][0][1]=dp[now][1][0]=dp[now][1][1]=1;
	for (ll i=head[now];i;i=e[i].nxt)
	if (e[i].to!=fa)
	{
		ll to=e[i].to;
		dfs(to,now);
		(dp[now][0][0]*=(dp[to][0][0]+dp[to][0][1]+dp[to][1][0]+dp[to][1][1])%p)%=p;
		(dp[now][0][1]*=(dp[to][0][0]+dp[to][0][1]+dp[to][1][0])%p)%=p;
		(tmp*=(dp[to][0][0]+dp[to][0][1])%p)%=p;
		(dp[now][1][0]*=(dp[to][0][0]+dp[to][0][1]+dp[to][1][0]+dp[to][1][1])%p)%=p;
		(dp[now][1][1]*=(dp[to][0][0]+dp[to][0][1]+dp[to][1][0])%p)%=p;
	}
	((dp[now][0][1]-=tmp)+=p)%=p;
}

int main()
{
	ll n=read();
	for (ll i=1;i<n;i++)
	{
		ll u=read(),v=read();
		add(u,v);
		add(v,u);
	}
	dfs(1,0);
	print((dp[1][0][1]+dp[1][0][0]-1+p)%p);

	return 0;
}