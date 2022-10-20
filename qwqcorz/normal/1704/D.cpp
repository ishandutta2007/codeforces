#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

ll a[N];
void work()
{
	int n=read(),m=read();
	for (int i=1;i<=n;i++)
	{
		a[i]=0;
		for (int j=1;j<=m;j++) a[i]+=1LL*j*read();
	}
	ll mn=*min_element(a+1,a+1+n);
	for (int i=1;i<=n;i++) if (a[i]>mn) return print(i,' '),print(a[i]-mn);
	assert(false);
}

signed main()
{
	int T=read();
	while (T--) work();
	
	return 0;
}