#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+1e3;

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
ll l[N],sum[N];
//l[i]:
//sum[i]: 

int main()
{
	l[0]=0;
	sum[0]=0;
	ll n=read(),ans=0;
	sum[n+1]=0;
	for (int i=1;i<=n;i++)
	{
		ll a=read();
		l[i]=l[i-1]+(a<0);
	}
	for (int i=1;i<=n;i++) sum[i]=(sum[i-1]+(l[i]-l[i-1]))%2;
	for (int i=n;i>=0;i--) sum[i]=sum[i+1]+sum[i];
	for (int i=1;i<=n;i++) l[i]%=2;
	for (int i=1;i<=n;i++) ans+=l[i-1]?sum[i]:n-i+1-sum[i];
	write(n*(n+1)/2-ans);
	putchar(' ');
	write(ans);

	return 0;
}