#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e6+5;
const ll mod=1e9+7;

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
int a[N],t[N],ans[N],p[N],k[N],b[N],w[N];
ll n,m,seed,base;
ll rnd()
{
	ll ret=seed;
	seed=(seed*base+233)%mod;
	return ret;
}
void input()
{
	n=read(),m=read();
	for (ll i=1;i<=m;i++)
	{
		p[i]=read(),k[i]=read(),b[i]=read(),w[i]=read();
		seed=b[i];
		base=w[i];
		for (ll j=p[i-1]+1;j<=p[i];j++)
		{
			t[j]=(rnd()%2)+1;
			a[j]=(rnd()%k[i])+1;
		}
	}
}
void output()
{
	ll res=1;
	for (ll i=1;i<=n;i++) res=res*((ans[i]^(i*i))%mod+1)%mod;
	print(res);
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	input();
	ll sum1=0,sum2=0,now=1;
	for (ll i=1;i<=n;i++) t[i]==1?sum1+=a[i]:sum2+=a[i];
	if (sum1>sum2) for (ll i=1;i<=n;i++) t[i]^=3;
	if (t[1]>1)
	{
		a[1]--,ans[1]++;
		for (ll i=2;i<=n;i++) if (t[i]==1) {now=i; break;}
	}
	for (ll i=1,tot=0;i<=n*2;i++,now=now%n+1)
	if (t[now]==1)
	{
		ans[now]+=a[now];
		tot+=a[now];
		a[now]=0;
	}
	else
	{
		ll tmp=min((ll)a[now],tot);
		a[now]-=tmp,tot-=tmp,ans[now]+=tmp;
	}
	output();
	
	return 0;
}