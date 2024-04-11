#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+60;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int a[N];
void GreenDay()
{
	int n=read(),ans=0;
	for (int i=1;i<=n;i++) a[read()]++;
	for (int i=0;i<=1e6+50;i++) ans+=a[i]%2,a[i+1]+=a[i]/2;
	print(ans);
}

signed main()
{
	int T=1;
//	int T=read();
	while (T--) GreenDay();
	
	return 0;
}