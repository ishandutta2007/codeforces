#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

void work()
{
	int n=read(),z=read(),ans=0;
	for (int i=1;i<=n;i++) ans=max(ans,(int)read()|z);
	print(ans);
}

signed main()
{
	int T=read();
	while (T--) work();
	
	return 0;
}