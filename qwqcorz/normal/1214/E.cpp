#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int d[N],p[N],a[N*2];

signed main()
{
	int n=read();
	for (int i=1;i<=n;i++) d[i]=read(),p[i]=i;
	sort(p+1,p+1+n,[&](int x,int y){return d[x]>d[y];});
	for (int i=1;i<n;i++) print(p[i]*2-1,' '),print(p[i+1]*2-1);
	for (int i=1;i<=n;i++) a[i]=p[i]*2-1;
	for (int i=1;i<=n;i++)
	{
		int x=a[i+d[p[i]]-1];
		print(x,' '),print(p[i]*2);
		if (!a[i+d[p[i]]]) a[i+d[p[i]]]=p[i]*2;
	}
	
	return 0;
}