#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e3;

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
int a[N],print[N];

int main()
{
	ll ans=0;
	int n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++)
	{
		int Max=0;
		for (int j=1;j<=n;j++) if (a[j]>a[Max]) Max=j;
		print[i]=Max;
		ans+=(i-1)*a[Max]+1;
		a[Max]=-2333;
	}
	write(ans);
	putchar('\n');
	for (int i=1;i<=n;i++)
	{
		write(print[i]);
		putchar(' ');
	}

	return 0;
}