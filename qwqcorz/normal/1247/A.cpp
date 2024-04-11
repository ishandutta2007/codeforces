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
void print(ll x,ll y)
{
	write(x);
	putchar(' ');
	write(y);
}

int main()
{
	ll a=read(),b=read();
	if (a==9&&b==1) print(9,10);
	else if (a>b||b-a>1) puts("-1");
	else if (a==b) print(a*10,b*10+1);
	else print(a,b);

	return 0;
}