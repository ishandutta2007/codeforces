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
inline ll calc(ll n)
{
	if (n<0) return -2333;
	int ans=0;
	while (n)
	{
		ans+=n&1;
		n>>=1;
	}
	return ans;
}

int main()
{
	ll n=read(),p=read(),ans=0;
	for (int i=1;i<=10000;i++)
	{
		if (calc(n-ans*p)<=ans&&n-ans*p>=ans)
		{
			write(ans);
			return 0;
		}
		ans++;
	}
	write(-1);

	return 0;
}