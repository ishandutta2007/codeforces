#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=255;
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
void prll(ll x=-1,char c='\n')
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
ll C[N][N],n,k,ans=0;
ll calc(ll i,ll j)
{
	ll tot1=i*n+j*n-i*j,tot2=n*n-tot1;
	return C[n][i]*C[n][j]%p*power(k-1,tot1)%p*power(k,tot2)%p;
}

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	n=read(),k=read();
	for (ll i=C[0][0]=1;i<=n;i++)
	for (ll j=C[i][0]=1;j<=i;j++)
	C[i][j]=(C[i-1][j-1]+C[i-1][j])%p;
	for (ll i=0;i<=n;i++)
	for (ll j=0;j<=n;j++)
	ans=(ans+calc(i,j)*((i+j)%2?-1:1)+p)%p;
	prll(ans);
	
	return 0;
}