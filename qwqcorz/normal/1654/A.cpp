#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e3+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int a[N];
void GreenDay()
{
	int n=read();
	for (int i=1;i<=n;i++) a[i]=read(); 
	sort(a+1,a+1+n,greater<int>());
	print(a[1]+a[2]);
}

signed main()
{
//	int T=1;
	int T=read();
	while (T--) GreenDay();
	
	return 0;
}