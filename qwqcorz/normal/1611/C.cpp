#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int a[N];
void GreenDay()
{
	int n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	if (a[1]!=n&&a[n]!=n) return puts("-1"),void();
	for (int i=n;i>=1;i--) print(a[i]," \n"[i==1]);
}

signed main()
{
//	int T=1;
	int T=read();
	while (T--) GreenDay();
	
	return 0;
}