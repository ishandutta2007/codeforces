#include<bits/stdc++.h>
#define ll long long
using namespace std;
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

int main()
{
	ll n=read(),m=read(),l=read(),r=read();
	ll tot=n*m,len=r-l+1,ans=power(len,tot),two=power(2,p-2);
	if (tot&1) print(ans);
	else if (len&1) print((ans+1)*two%p);
	else print(ans*two%p);

	return 0;
}