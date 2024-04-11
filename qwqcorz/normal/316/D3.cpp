#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+5;
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
void print(ll x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
ll power(ll a,ll b)
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
inline void add(ll &x,ll y)
{
	x+=y;
	if (x>=p) x-=p;
}
ll fact[N],inv[N];
ll A(ll n,ll m)
{
	return inv[n-m]*fact[n]%p;
}
ll dp[N];

signed main()
{
	ll n=read(),cnt1=0,cnt2=0;
	fact[0]=1;
	for (ll i=1;i<=n;i++) fact[i]=fact[i-1]*i%p;
	inv[n]=power(fact[n],p-2);
	for (ll i=n;i>=1;i--) inv[i-1]=inv[i]*i%p;
	for (int i=1;i<=n;i++)
	{
		int x=read();
		if (x==1) cnt1++;
			 else cnt2++;
	}
	dp[0]=1;
	dp[1]=1;
	for (int i=2;i<=n;i++) dp[i]=(dp[i-1]+(i-1)*dp[i-2]%p)%p;
	print(A(n,cnt2)*dp[cnt1]%p);

	return 0;
}