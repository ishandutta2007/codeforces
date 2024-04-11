#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+1e3;

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
ll a[N];
ll gcd(ll x,ll y)
{
	return y==0?x:gcd(y,x%y);
}

int main()
{
	ll n=read(),g=0,sum=0;
	for (int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++) a[i]=a[n]-a[i];
	for (int i=1;i<n;i++)
	{
		g=gcd(g,a[i]);
		sum+=a[i];
	}
	write(sum/g);
	putchar(' ');
	write(g);

	return 0;
}