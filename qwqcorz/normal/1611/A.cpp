#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int a[15];
void GreenDay()
{
	int n=read(),m=0;
	for (int x=n;x;x/=10) a[++m]=x%10;
	if (n%2==0) return puts("0"),void();
	if (a[m]%2==0) return puts("1"),void();
	for (int i=1;i<=m;i++) if (a[i]%2==0) return puts("2"),void();
	puts("-1");
}

signed main()
{
//	int T=1;
	int T=read();
	while (T--) GreenDay();
	
	return 0;
}