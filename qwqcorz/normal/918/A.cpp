#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

signed main()
{
	int n=read();
	static int f[1000]={0,1};
	static bool is[5005]={};
	for (int i=2;f[i-1]<=1000;i++) is[f[i]=f[i-1]+f[i-2]]=1;
	for (int i=1;i<=n;i++) putchar("oO"[is[i]]);
	
	return 0;
}