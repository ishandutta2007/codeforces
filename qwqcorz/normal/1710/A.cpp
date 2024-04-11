#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

void work()
{
	ll sum1=0,mx1=0,sum2=0,mx2=0;
	int n=read(),m=read(),k=read();
	for (int i=1;i<=k;i++)
	{
		int x=read();
		if (x>=n*2) sum1+=x/n,mx1=max(mx1,1LL*x/n);
		if (x>=m*2) sum2+=x/m,mx2=max(mx2,1LL*x/m);
	}
	if (!(sum1<m||(sum1%2!=m%2&&mx1==2))) return puts("Yes"),void();
	if (!(sum2<n||(sum2%2!=n%2&&mx2==2))) return puts("Yes"),void();
	puts("No");
}

signed main()
{
	int T=read();
	while (T--) work(); 
	
	return 0;
}