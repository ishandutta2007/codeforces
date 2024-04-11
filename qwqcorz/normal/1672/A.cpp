#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

void work()
{
	int n=read(),sum=0;
	for (int i=1;i<=n;i++) sum+=read()-1;
	puts(sum%2?"errorgorn":"maomao90");
}

signed main()
{
	int T=read();
	while (T--) work();
	
	return 0;
}