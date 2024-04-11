#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+5;

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
ll Max(ll x)
{
	return x<0ll?0ll:x;
}
ll calc(ll l,ll r)
{
	if (r<l) return 0;
	return (l+r)*(r-l+1)/2;
}
ll s[N];

int main()
{
	ll a=read(),b=read(),c=read(),d=read(),ans=0ll;
/*	for (ll i=a;i<=b;i++)
	{
		ll lst=d-i+1ll;
		ans+=(d-c+1ll)*Max(c-max(lst,b)+1);print(ans);
//		if (lst>c) d2=d-(lst-c);
//			  else d2=d;
//		ll b2=Max(b-(c-i+1))+1;
//		ans+=(b2+(d2-c))*(d2-c+1-b2)/2;print(ans);
		ll l=c-i+1;
		ans+=calc(min(lst-1,c)-max(l,b)-,Max(min(lst-1,c)-max(l,b)+1));print(ans);
	}*/
	s[b+c+1]=0;
	for (ll i=b+c;i>=c;i--)
	{
		ll yn=max(i-b,b),ym=max(min(i-a,c),yn-1);
		s[i]=s[i+1]+ym-yn+1;
		if (i<=d) ans+=s[i+1];
	}
	print(ans);

	return 0;
}