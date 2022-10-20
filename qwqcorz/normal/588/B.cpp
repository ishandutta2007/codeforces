#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

void GreenDay()
{
	ll n=read(),ans=1;
	for (ll i=2;i*i<=n;i++)
	if (n%i==0)
	{
		ans*=i;
		while (n%i==0) n/=i;
	}
	print(ans*=n);
}

signed main()
{
	int T=1;
//	int T=read();
	while (T--) GreenDay();
	
	return 0;
}