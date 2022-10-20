#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
using namespace std;
const ll N=30;
const ll inf=1e18;

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
void print(ll x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
ll a[N][3],ans=-inf,st=0;
map<pair<ll,ll>,pair<ll,ll>>mp;
void dfs1(ll now,ll up,ll x,ll y,ll z,ll s)
{
	if (now>up)
	{
		auto xxx=mk(x-y,x-z);
		if (mp.count(xxx)) mp[xxx]=max(mp[xxx],mk(x,s));
					  else mp[xxx]=mk(x,s);
		return;
	}
	dfs1(now+1,up,x,y+a[now][1],z+a[now][2],s);
	dfs1(now+1,up,x+a[now][0],y,z+a[now][2],s|(1LL<<(now*2-2)));
	dfs1(now+1,up,x+a[now][0],y+a[now][1],z,s|(2LL<<(now*2-2)));
}
void dfs2(ll now,ll up,ll x,ll y,ll z,ll s)
{
	if (now>up)
	{
		auto xxx=mk(y-x,z-x);
		if (mp.count(xxx)&&mp[xxx].first+x>ans)
		{
			ans=mp[xxx].first+x;
			st=s|mp[xxx].second;
		}
		return;
	}
	dfs2(now+1,up,x,y+a[now][1],z+a[now][2],s);
	dfs2(now+1,up,x+a[now][0],y,z+a[now][2],s|(1LL<<(now*2-2)));
	dfs2(now+1,up,x+a[now][0],y+a[now][1],z,s|(2LL<<(now*2-2)));
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	ll n=read()+1;
	for (ll i=1;i<n;i++)
		a[i][0]=read(),
		a[i][1]=read(),
		a[i][2]=read();
	dfs1(1,n/2,0,0,0,0);
	dfs2(n/2+1,n,0,0,0,0);
	if (ans==-inf) return puts("Impossible"),0;
	for (ll i=1;i<n;i++,st>>=2) puts((char[][8]){"MW","LW","LM","wcakioi"}[st&3]);
	
	return 0;
}