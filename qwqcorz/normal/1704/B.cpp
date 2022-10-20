#include<bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N=2e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int a[N];
void work()
{
	int n=read(),x=read(),ans=0;
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1,l=1,r=0;i<=n;i++)
	{
		l=max(l,a[i]-x);
		r=min(r,a[i]+x);
		if (l>r) ans++,l=a[i]-x,r=a[i]+x;
	}
	print(ans-1);
}

signed main()
{
	int T=read();
	while (T--) work();
	
	return 0;
}