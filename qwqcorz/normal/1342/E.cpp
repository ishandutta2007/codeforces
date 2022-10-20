#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+5;
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
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(ll x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
inline ll power(ll a,ll b)
{
	ll ret=1;
	while (b)
	{
		if (b&1) ret=ret*a%p;
		a=a*a%p;
		b/=2;
	}
	return ret;
}
ll fact[N],inv[N];
inline ll C(ll n,ll m)
{
	return fact[n]*inv[m]%p*inv[n-m]%p;
}

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	ll n=read(),k=read(),tot=0;
	if (k>=n) puts("0");
	else
	{
		for (ll i=fact[0]=1;i<=n;i++) fact[i]=fact[i-1]*i%p;
		inv[n]=power(fact[n],p-2);
		for (ll i=n;i>=1;i--) inv[i-1]=inv[i]*i%p;
		for (ll i=1;i<=n-k;i++) tot=(tot+power(i,n)*C(n-k,i)%p*(((n-k-i)&1)?-1:1)+p)%p;
		print(C(n,n-k)*tot%p*(k?2:1)%p);
	}
	
	return 0;
}