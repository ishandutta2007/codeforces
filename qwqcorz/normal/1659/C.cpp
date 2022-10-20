#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

void work()
{
	ll ans=0;
	int n=read(),a=read(),b=read(),now=0;
	for (int i=1;i<=n;i++)
	{
		int x=read();
		ans+=1LL*(x-now)*b;
		if (a<1LL*b*(n-i)) ans+=1LL*(x-now)*a,now=x;
	}
	print(ans);
}

signed main()
{
	int T=read();
	while (T--) work();
	
	return 0;
}