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
void print(ll x,char c='\n')
{
	write(x);
	putchar(c);
}
ll gcd(ll x,ll y){return !y?x:gcd(y,x%y);}
ll a[N],st[N][20],Log[N];
ll query(ll l,ll r)
{
	ll k=Log[r-l+1];
	return gcd(st[l][k],st[r-(1<<k)+1][k]);
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	for (ll i=2;i<N;i++) Log[i]=Log[i/2]+1;
	ll T=read();
	while (T--)
	{
		ll n=read(),ans=1;
		for (ll i=1;i<=n;i++) a[i]=read();
		for (ll i=1;i<n;i++) st[i][0]=abs(a[i+1]-a[i]);
		for (ll j=1;j<=17;j++)
		for (ll i=1;i+(1<<j)-1<n;i++)
		st[i][j]=gcd(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		for (ll i=1,j=1;i<n;i++)
		{
			while (j<=i&&query(j,i)==1) j++;
			ans=max(ans,i-j+2);
		}
		print(ans);
	} 
	
	return 0;
}