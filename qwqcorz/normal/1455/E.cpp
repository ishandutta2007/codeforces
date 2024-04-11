#include<bits/stdc++.h>
#define ll long long
using namespace std;

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
ll x[4],y[4],ans,p[4];
ll dis(ll x0,ll y0,ll x1,ll y1)
{
	return abs(x0-x1)+abs(y0-y1);
}
void solve(ll x0,ll y0,ll kx,ll ky)
{
	ll tx[2]={x0,x0+kx},ty[2]={y0,y0+ky};
//	print(tx[0],' ');
//	print(ty[0],' ');
//	print(tx[1],' ');
//	print(ty[1]);
	for (ll i=0;i<4;i++) p[i]=i;
	do
	{
		ll now=0;
		for (ll i=0;i<4;i++) now+=dis(tx[i>>1],ty[i&1],x[p[i]],y[p[i]]);
		ans=min(ans,now);
	}while (next_permutation(p,p+4));
}

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	ll T=read();
	while (T--)
	{
		ans=1e18;
		for (ll i=0;i<4;i++) x[i]=read(),y[i]=read();
		for (ll i=0;i<4;i++)
		for (ll j=0;j<4;j++)
		{
			ll x0=x[i],y0=y[j];
			for (ll k=0;k<4;k++)
			for (ll u=-1;u<=1;u+=2)
			for (ll v=-1;v<=1;v+=2)
			{
				ll Max=max(abs(x0-x[k]),abs(y0-y[k]));
				if (Max) solve(x0,y0,Max*u,Max*v);
			}
		}
		print(ans);
	}
	
	return 0;
}