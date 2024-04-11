#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e3+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int a[N];

signed main()
{
	ll ans=1e18;
	int n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int k=1;k<=n;k++)
	{
		ll now=0,lst=0;
		for (int i=k+1;i<=n;i++)
		{
			ll p=lst/a[i]+1;
			now+=p;
			lst=a[i]*p;
		}
		lst=0;
		for (int i=k-1;i>=1;i--)
		{
			ll p=lst/a[i]+1;
			now+=p;
			lst=a[i]*p;
		}
		ans=min(ans,now);
	}
	print(ans);
	
	return 0;
}