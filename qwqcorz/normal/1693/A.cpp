#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int a[N];
bool work()
{
	ll sum=0;
	int n=read(),mx=0;
	for (int i=1;i<=n;i++)
	{
		sum+=a[i]=read();
		mx=max(mx,a[i]);
	}
	if (sum) return 0;
	if (mx==0) return 1;
	if (a[1]<0) return 0;
	a[1]--;
	for (int i=n;i>=1;i--) if (a[i])
	{
		if (a[i]>0) return 0;
		a[i]++;
		break;
	}
	for (int i=n;i>=1;i--) if ((sum+=a[i])>0) return 0;
	return 1;
}

signed main()
{
	int T=read();
	while (T--) puts(work()?"YES":"NO"); 
	
	return 0;
}