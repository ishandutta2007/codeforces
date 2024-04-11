#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+5;
const ll inf=1LL<<60;

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
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(ll x,char c='\n')
{
	write(x);
	putchar(c);
}
void up(ll &x,ll y){x=min(x,y);}
set<ll>pr;
void split(ll x)
{
	for (ll i=2;i*i<=x;i++)
	if (x%i==0)
	{
		pr.insert(i);
		while (x%i==0) x/=i;
	}
	if (x>1) pr.insert(x);
}
ll a[N],dp[N][3],ans=inf,n,x,y;
ll cost(ll x,ll p)
{
	if (x%p==0) return 0;
	if ((x-1)%p==0) return y;
	if ((x+1)%p==0) return y;
	return inf;
}
ll solve(ll p,ll l,ll r)
{
	memset(dp,0x3f,sizeof(dp));
	dp[l-1][0]=0;
	for (ll i=l;i<=r;i++)
	{
		up(dp[i][0],dp[i-1][0]+cost(a[i],p));
		up(dp[i][2],min(dp[i-1][1],dp[i-1][2])+cost(a[i],p));
		dp[i][1]=min(dp[i-1][0],dp[i-1][1])+x;
	}
	return min(min(dp[r][0],dp[r][1]),dp[r][2]);
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	n=read(),x=read(),y=read();
	for (ll i=1;i<=n;i++) a[i]=read();
	split(a[1]),split(a[1]-1),split(a[1]+1),split(a[n]),split(a[n]-1),split(a[n]+1);
	for (ll p:pr) ans=min(ans,min(solve(p,1,n-1)+cost(a[n],p),solve(p,2,n)+cost(a[1],p)));
	print(ans);
	
	return 0;
}