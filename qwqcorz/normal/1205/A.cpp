#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=4e5+1e3;

inline int read()
{
    int s=0;
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
void print(ll x)
{
	write(x);
	putchar(' ');
}
ll a[N],v1=0,v2=0;
void error()
{
	puts("NO");
	exit(0);
}

int main()
{
	a[0]=0;
	int n=read();
	for (int i=1;i<=n;i++)
	{
		a[i]=2*i-1;
		a[i+n]=2*i;
		if (i%2==0) swap(a[i],a[i+n]);
		a[i+2*n]=a[i];
		a[i+3*n]=a[i+n];
	}
	for (int i=1;i<=4*n;i++) a[i]+=a[i-1];
	for (int i=1;i<=2*n;i++)
	{
		ll now=a[i+n-1]-a[i-1];
		if (v1==0) v1=now;
		else if (v2==0&&v1!=now) v2=now;
		if (now!=v1&&now!=v2) error();
	}
	puts("YES");
	for (int i=1;i<=2*n;i++) print(a[i]-a[i-1]);

	return 0;
}