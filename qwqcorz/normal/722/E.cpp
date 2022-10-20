#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define x first
#define y second
using namespace std;
const ll N=2e5+5;
const ll K=2e3+5;
const ll p=1e9+7;

inline ll read()
{
	register ll s=0;
	register char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(register ll x)
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
inline void print(const register ll x,const register char c='\n')
{
	write(x);
	putchar(c);
}
pair<int,int>a[K];
ll fac[N],inv[N];
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
ll C(ll n,ll m)
{
	return fac[m]*inv[n]%p*inv[m-n]%p;
}
ll val[105],dp[K][105];

int main()
{
	ll n=read(),m=read(),k=read(),s=read(),cnt=0,ans=0;
	for (ll i=1;i<=k;i++)
	{
		ll X=read(),Y=read();
		a[i]=mk(X,Y);
	}
	a[0]=mk(1,1);
	a[k+1]=mk(n,m);
	sort(a+1,a+1+k);

	fac[0]=1;
	for (ll i=1;i<=n+m;i++) fac[i]=fac[i-1]*i%p;
	inv[n+m]=power(fac[n+m],p-2);
	for (ll i=n+m-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%p;

	for (ll now=s;1;now=int(now/2.0+0.5))
	{
		val[cnt++]=now;
		if (now==1) break;
	}
	dp[0][0]=1;
	for (ll i=1;i<=k+1;i++)
	{
		for (ll num=1;num<=cnt;num++)
		for (ll j=0;j<i;j++)
		if (a[j].x<=a[i].x&&a[j].y<=a[i].y)
		(dp[i][num]+=dp[j][num-1]*C(a[i].x-a[j].x,a[i].x-a[j].x+a[i].y-a[j].y))%=p;
		for (ll num=1;num<cnt;num++) dp[i][num]=(dp[i][num]-dp[i][num+1]+p)%p;
	}
//	for (ll i=0;i<=k+1;i++)
//	{
//		for (ll num=0;num<=cnt;num++) print(dp[i][num],' ');
//		puts("");
//	} 
//	for (ll i=1;i<=cnt;i++) print(val[i-1]);
	for (ll i=1;i<=cnt;i++) ans=(ans+dp[k+1][i]*val[i-1]%p)%p;
	print(ans*power(C(n-1,n+m-2),p-2)%p);

	return 0;
}