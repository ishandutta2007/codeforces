#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+5;
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
ll a[N],fact[N],inv[N];
inline ll C(ll n,ll m)
{
	return fact[n]*inv[m]%p*inv[n-m]%p;
}
map<ll,ll>cnt;

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	ll n=read(),sum=0;
	for (ll i=1;i<=n;i++) sum+=a[i]=read();
	for (ll i=1;i<=n;i++) cnt[a[i]]++;
	for (ll i=fact[0]=1;i<=n;i++) fact[i]=fact[i-1]*i%p;
	inv[n]=power(fact[n],p-2);
	for (ll i=n;i>=1;i--) inv[i-1]=inv[i]*i%p;
	if (sum%n) puts("0");
	else
	{
		sum/=n;
		ll cnt0=0,cnt1=0,cnt2=0,ans;
		for (ll i=1;i<=n;i++)
		{
			if (a[i]>sum) cnt1++;
			if (a[i]==sum) cnt0++;
			if (a[i]<sum) cnt2++;
		}
		if (cnt1<=1||cnt2<=1) ans=fact[n]%p;
						 else ans=fact[cnt1]*fact[cnt2]%p*fact[cnt0]%p*C(n,cnt0)%p*2LL%p;
		for (auto i:cnt) ans=ans*inv[i.second]%p;
		print(ans);
	}
	
	return 0;
}