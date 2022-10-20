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
inline void add(ll &x,ll y)
{
	x+=y;
	if (x>=p) x-=p;
}
inline ll lowbit(ll x)
{
	return x&-x;
}
inline ll calc(ll x1,ll x2,ll y1,ll y2,ll k)
{
	if (x2-x1<y2-y1) swap(x1,y1),swap(x2,y2);
	ll tmp=x2-x1;
	x2=(x1=(x1^y1)&~(tmp-1))+tmp;
	x1++;
	x2=min(x2,k);
	if (x1>x2||y1>y2) return 0;
	return (x1+x2)*(x2-x1+1)/2%p*(y2-y1)%p;
}
inline ll solve(ll x,ll y,ll k)
{
	ll ret=0;
	for (ll i=x;i;i&=i-1)
	for (ll j=y;j;j&=j-1)
	add(ret,calc(i-lowbit(i),i,j-lowbit(j),j,k));
	return ret;
}

signed main()
{
	ll q=read();
	while (q--)
	{
		ll x1=read(),y1=read(),x2=read(),y2=read(),k=read();
		print((solve(x2,y2,k)-solve(x1-1,y2,k)-solve(x2,y1-1,k)+solve(x1-1,y1-1,k)+p+p)%p);
	}

	return 0;
}