#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int a[6];

void GreenDay()
{
	for (int i=0;i<6;i++) a[i]=read();
	for (int i=0;i<(1<<6);i++)
	if (__builtin_popcount(i)==3)
	{
		int sum=0;
		for (int j=0;j<6;j++) if (i>>j&1) sum+=a[j]; else sum-=a[j];
		if (sum==0) return puts("YES"),void();
	}
	puts("NO");
}

signed main()
{
	int T=1;
//	int T=read();
	while (T--) GreenDay();
	
	return 0;
}