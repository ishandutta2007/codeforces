#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

void GreenDay()
{
	int n=read(),ans=0,mn=114514;
	for (int i=1;i<=n;i++)
	{
		int x=read(),y=read();
		ans+=(mn=min(mn,y))*x;
	}
	print(ans);
}

signed main()
{
	int T=1;
//	int T=read();
	while (T--) GreenDay();
	
	return 0;
}