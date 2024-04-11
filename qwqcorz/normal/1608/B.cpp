#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

void GreenDay()
{
	int n=read(),a=read(),b=read();
	if (a+b>n-2||abs(a-b)>1) return puts("-1"),void();
	if (a==b+1)
	{
		int l=1,r=n;
		for (int i=1;i<=a;i++) print(l++,' '),print(r--,' ');
		for (int i=r;i>=l;i--) print(i,' ');
		puts("");
	}
	else if (a==b-1)
	{
		int l=1,r=n;
		for (int i=1;i<=b;i++) print(r--,' '),print(l++,' ');
		for (int i=l;i<=r;i++) print(i,' ');
		puts("");
	}
	else
	{
		int l=1,r=n;
		for (int i=1;i<=a;i++) print(l++,' '),print(r--,' ');
		for (int i=l;i<=r;i++) print(i,' ');
		puts("");
	}
}

signed main()
{
//	int T=1;
	int T=read();
	while (T--) GreenDay();
	
	return 0;
}