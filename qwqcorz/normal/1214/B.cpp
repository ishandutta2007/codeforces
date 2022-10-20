#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

signed main()
{
	int b=read(),g=read(),n=read(),ans=0;
	for (int i=0;i<=b;i++)
	for (int j=0;j<=g;j++)
	ans+=i+j==n;
	print(ans);
	
	return 0;
}