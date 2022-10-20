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
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(ll x,char c='\n')
{
	write(x);
	putchar(c);
}
ll p[N];

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	ll n=read(),k=read(),l=0,r=0,sum=0;
	for (ll i=1;i<=n;i++) l+=i,r+=max(i,n-i+1);
	if (k<l) puts("-1");
	else
	{
		sum=l,l=1,r=n;
		for (ll i=1;i<=n;i++)
		if (sum+max(i,r)-i<=k) sum+=max(i,p[i]=r--)-i;
						  else sum+=max(i,p[i]=l++)-i;
		print(sum);
		for (ll i=1;i<=n;i++) print(i," \n"[i==n]);
		for (ll i=1;i<=n;i++) print(p[i]," \n"[i==n]);
	}
	
	return 0;
}