#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=3e5;

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
ll fact[N];

int main()
{
	fact[0]=1;
	ll n=read(),m=read(),ans=0;
	for (ll i=1;i<=n;i++) fact[i]=fact[i-1]*i%m;
	for (ll i=1;i<=n;i++) (ans+=fact[i]*fact[n-i]%m*(n-i+1)%m*(n-i+1)%m)%=m;
	print(ans);

	return 0;
}