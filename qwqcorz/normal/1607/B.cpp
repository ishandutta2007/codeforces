#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

void GreenDay()
{
	int x=read(),n=read();
	if (n==0) return print(x);
	int m=(n-1)/4*4+1,delta=m;
	for (int i=m+1;i<=n;i++) delta+=i-m<=2?-i:i;
	print(x+((x&1)?delta:-delta));
}

signed main()
{
//	int T=1;
	int T=read();
	while (T--) GreenDay();
	
	return 0;
}