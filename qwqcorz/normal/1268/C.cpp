#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+5;

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
struct BIT
{
	ll tot[N],sum[N],n;
	void add(ll x,ll y)
	{
		for (;x<=n;x+=x&-x) tot[x]++,sum[x]+=y;
	}
	ll query_tot(ll x)
	{
		ll ret=0;
		for (;x;x=x&(x-1)) ret+=tot[x];
		return ret;
	}
	ll query_sum(ll x)
	{
		ll ret=0;
		for (;x;x=x&(x-1)) ret+=sum[x];
		return ret;
	}
	ll get_kth(ll k)
	{
		ll now=0,cnt=0;
		for (ll i=18;i>=0;i--)
		{
			now^=1<<i;
			if (now>n||cnt+tot[now]>=k) now^=1<<i;
			else cnt+=tot[now];
		}
		return now+1;
	}
}t;
ll np[N];

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	ll n=t.n=read(),ans=0,sum=0;
	for (ll i=1;i<=n;i++) np[read()]=i;
	for (ll i=1;i<=n;i++)
	{
		sum+=np[i];
		ans+=i-1-t.query_tot(np[i]);
		t.add(np[i],np[i]);
		ll pos=t.get_kth((i+1)/2);
		ll qtot=t.query_tot(pos),qsum=t.query_sum(pos);
		print(ans+qtot*pos-qsum+sum-qsum-(i-qtot)*pos-(qtot-1)*qtot/2-(i-qtot+1)*(i-qtot)/2,' ');
	}
	
	return 0;
}