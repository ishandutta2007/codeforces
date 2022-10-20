#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
inline ll read()
{
    ll s=0;
    char c=getchar(),lc='+';
    while (c<'0'||c>'9') lc=c,c=getchar();
    while (c>='0'&&c<='9') s=s*10+c-'0',c=getchar();
    return lc=='-'?-s:s;
}
void write(ll n)
{
    if (n<0)
    {
        putchar('-');
        n=abs(n);
    }
    if (n<10)
    {
        putchar(n+'0');
        return;
    }
    write(n/10);
    putchar(n%10+'0');
}
ll gcd(ll x,ll y)
{
	return y==0?x:gcd(y,x%y);
}
ll get(ll a,ll b,ll x,ll y)
{
	if (x==1) return (y-1)/a;
		 else return (y-1)/b;
}
 
int main()
{
	ll n=read(),m=read(),q=read(),g=gcd(n,m),a=n/g,b=m/g;
	while (q--)
	{
		ll x1=read(),y1=read(),x2=read(),y2=read(),ans1=get(a,b,x1,y1),ans2=get(a,b,x2,y2);
		if (ans1==ans2) puts("YES");
				   else puts("NO");
	}
 
	return 0;
}