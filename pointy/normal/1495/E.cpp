// By: Little09
// Problem: CF1495E Qingshan and Daniel
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1495E
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e6+5,M=2e5+5;
const ll mod=1000000007;
int n,m;
int t[N];
ll a[N],c[N],ans[N];
ll b[3];
inline int read()
{
    int F=1,ANS=0;
	char C=getchar();
    while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
    while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
    return F*ANS;
}
namespace IO
{
	ll seed = 0,base = 0;
	ll rnd()
	{
		ll ret = seed;
		seed = (seed * base + 233) % mod;
		return ret;
	}
	ll p[N];
	void init()
	{
		n=read(),m=read();
		p[0]=0;
		for (int i=1;i<=m;i++)
		{
			p[i]=read();
			ll k=read();
			seed=read();
			base=read();
			for (int j=p[i-1]+1;j<=p[i];j++)
			{
				t[j]=(rnd()%2)+1;
				a[j]=(rnd()%k)+1;
			}
		}
	}
	void print(int op,int tp)
	{
		if (op==0)
		{
			for (int i=1;i<=n;i++) ans[i]=0;
			ans[1]=1;
		}
		else if (op==1)
		{
			for (int i=1;i<=n;i++)
			{
				ans[i]=c[i]-a[i];
			}
		}
		else
		{
			for (int i=1;i<=n;i++)
			{
				ans[i]=c[i];
			}
		}
		ll res=1;
		for (ll i=1;i<=n;i++)
		{
			res=res*(((ans[i]^(i*i))+1)%mod)%mod;
		}
		printf("%lld\n",res);
	}
}
ll work(int x,ll y,int tp)
{
	for (int i=x+1;i<=n;i++)
	{
		if (t[i]==tp) y+=a[i],a[i]=0;
		else
		{
			ll u=min(y,a[i]);
			y-=u,a[i]-=u;
		}
	}
	for (int i=1;i<x;i++)
	{
		if (t[i]==tp) y+=a[i],a[i]=0;
		else
		{
			ll u=min(y,a[i]);
			y-=u,a[i]-=u;
		}
	}
	return y;
}
int main()
{
	IO::init();
	for (int i=1;i<=n;i++) c[i]=a[i];
	for (int i=1;i<=n;i++) b[t[i]]+=a[i];
	if (b[1]==0||b[2]==0)
	{
		ans[1]=1;
		IO::print(0,0);
		return 0;
	}
	int tp=2;
	if (b[2]==b[1])
	{
		IO::print(2,0);
		return 0;
	}
	if (b[2]>b[1]) tp=1;
	if (t[1]!=tp) a[1]--;
	for (int i=1;i<=n;i++)
	{
		if (t[i]==tp)
		{
			a[i]=work(i,a[i],tp);
			a[i]=work(i,a[i],tp);
			IO::print(1,tp);
			return 0;
		}
	}
	return 0;
}