#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+1e3;
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
void print(ll x,char c='\n')
{
	write(x);
	putchar(c);
}
ll a[N],fact[N],inv[N],base[N],ans=0;//fact[i]:i!,inv[i]:i!,base[i]:10^i 
ll power(ll a,ll b)
{
	ll ans=1;
	while (b)
	{
		if (b&1) ans=ans*a%p;
		a=a*a%p;
		b/=2;
	}
	return ans;
}
ll C(ll n,ll m)
{
	if (n>m) return 0;
	return fact[m]*inv[n]%p*inv[m-n]%p;
}

int main()
{
	ll n=read(),k=read();
	for (ll i=1;i<=n;i++)
	{
		char c=getchar();
		while (c<'0'||'9'<c) c=getchar();
		a[i]=(a[i-1]+c-'0')%p;//a 
	}
	fact[0]=base[0]=1;
	for (ll i=1;i<=n;i++) fact[i]=fact[i-1]*i%p;
	inv[n]=power(fact[n],p-2);
	for (ll i=n-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%p;
	for (ll i=1;i<=n;i++) base[i]=base[i-1]*10ll%p;
	for (ll i=0;i<n;i++)
	{
		ans=(ans+a[n-i-1]*base[i]%p*C(k-1,n-i-2)%p)%p;
		ans=(ans+(a[n-i]-a[n-i-1]+p)%p*base[i]%p*C(k,n-i-1)%p)%p; 
	} 
	print(ans);

	return 0;
}
/*
ij
Vi*10^j
C(k-1,i-1+n-i-j-1)=C(k-1,n-j-2)
*=Vi*10^j*C(k-1,n-j-2)
ij 
 
*/