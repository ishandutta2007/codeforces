#include<bits/stdc++.h>
#define ll long long
using namespace std;
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
void print(ll x=-1,char c='\n')
{
	write(x);
	putchar(c);
}

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	ll T=read();
	while (T--)
	{
		ll m=read();
		print((m/4+1)%p*((m/2-m/4+1)%p)%p);
	}
	
	return 0;
}