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
void print(ll x)
{
	write(x);
	putchar('\n');
}

int main()
{
	bool flag=0;
	ll n=read(),ans=0,now=1;
	for (int i=1;i<=n;i++)
	{
		ll a=read();
		if (a==0)
		{
			ans++;
			flag=1;
		}
		else
		if (a<0)
		{
			ans+=-a-1;
			now=-now;
		}
		else ans+=a-1;
	}
	if (now<0&&!flag) ans+=2;
	print(ans);

	return 0;
}