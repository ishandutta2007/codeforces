#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

bool win(ll s,ll e)
{
	if (e&1) return s%2==0;
	if (s>e/2) return s&1;
	if (s>e/4) return 1;
	return win(s,e/4);
}
bool lose(ll s,ll e)
{
	if (s>e/2) return 1;
	return win(s,e/2);
}

signed main()
{
	int T=read();
	bool f[2]={1,0};
	while (T--)
	{
		ll s=read(),e=read();
		bool can1=win(s,e),can0=lose(s,e);
		bool g[2]={0,0};
		g[0]|=f[0]&&can0;
		g[1]|=f[0]&&can1;
		g[0]|=f[1]&&!can0;
		g[1]|=f[1]&&!can1;
		swap(f,g);
	}
	print(f[1],' '),print(f[0]);
	
	return 0;
}