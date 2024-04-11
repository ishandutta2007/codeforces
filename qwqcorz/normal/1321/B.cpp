#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+5;
const ll M=6e5+5; 

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
ll a[N],Max[M];

int main()
{
	ll n=read(),ans=0;
	memset(Max,0,sizeof(Max));
	for (ll i=1;i<=n;i++) a[i]=read()-i+n;
	for (ll i=1;i<=n;i++) ans=max(ans,Max[a[i]]+=a[i]+i-n);
	print(ans);

	return 0;
}