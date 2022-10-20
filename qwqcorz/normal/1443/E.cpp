#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=20;

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
bool vis[N];
ll p[N],fact[N];
void turn(ll n,ll x)
{
	memset(vis,0,sizeof(vis));
	for (ll i=1;i<=n;i++)
	{
		ll num=x/fact[n-i]+1;
		x%=fact[n-i];
		for (ll j=1;j<=n;j++) if (!vis[j]) if (!--num) p[i]=j,vis[j]=1;
	}
}

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	ll n=read(),m=read(),len=min(n,15LL),rk=0;
	for (ll i=fact[0]=1;i<=len;i++) fact[i]=fact[i-1]*i;
	for (ll T=1;T<=m;T++)
	{
		ll opt=read();
		if (opt==1)
		{
			ll l=read(),r=read(),ans=0;
			turn(len,rk);
			for (ll i=max(l,n-len+1)-(n-len);i<=r-(n-len);i++) ans+=p[i]+n-len;
			l=min(l,n-len+1);
			r=min(r,n-len);
			print(ans+(l+r)*(r-l+1)/2);
		}
		else rk+=read();
	}
	
	return 0;
}