#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+5;
const ll p=1e9+7;

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
ll power(ll a,ll b)
{
	ll ret=1;
	while (b)
	{
		if (b&1) ret=1LL*ret*a%p;
		a=1LL*a*a%p;
		b/=2;
	}
	return ret;
}
ll fact[N],inv[N],pw[N];
void ysgs(ll n)
{
	for (ll i=pw[0]=1;i<=n;i++) pw[i]=pw[i-1]*2%p;
	for (ll i=fact[0]=1;i<=n;i++) fact[i]=fact[i-1]*i%p;
	inv[n]=power(fact[n],p-2);
	for (ll i=n;i>=1;i--) inv[i-1]=inv[i]*i%p;
}
ll C(ll n,ll m)
{
	if (n<0||m<0||n<m) return 0;
	return fact[n]*inv[m]%p*inv[n-m]%p;
}
struct Ca
{
	ll n,m,ans;
	void set(ll _m)
	{
		ans=1;
		n=0,m=_m;
	}
	void setn()
	{
		if (ans) ans=(ans*2-C(n++,m)+p)%p;
	}
	void setm(ll _m)
	{
		for (ll i=min(m,n);i>=max(_m+1,0LL);i--) ans=(ans-C(n,i)+p)%p;
		m=_m;
		if (m<0) ans=0;
	}
}t1,t2,t3;
ll a[N];

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	ysgs(200001);
	ll n=read(),T=read(),ans=0;
	for (ll i=1;i<=n;i++) a[i]=read(); a[n+1]=T+1;
	ll l=T-a[1],r=T,x=T-a[1]-1;
	t1.set(l),t2.set(r),t3.set(x);
	for (ll i=1;i<=n;i++)
	{
		t1.setn(),t2.setn(),t3.setn();
		t1.setm(l-=a[i+1]),t2.setm(r-=a[i]),t3.setm(x-=a[i+1]);
		if (l<r) ans=(ans+(t2.ans-t1.ans+p)*power(pw[i+1],p-2)%p*i)%p;
		if (x<r) ans=(ans+(t2.ans-t3.ans+p)*power(pw[i+1],p-2)%p*i)%p;
//		print(l,' '),print(r,' '),print(x);
//		print(t1.ans,','),print(t2.ans,','),print(t3.ans);
//		print(ans);
	}
	print(ans);
	
	return 0;
}