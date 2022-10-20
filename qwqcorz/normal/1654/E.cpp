#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
const int M=N*400;
const int B=300;
const int BB=N/B;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int a[N],t[M*2];

signed main()
{
	int n=read(),ans=min(n,2);
	for (int i=1;i<=n;i++) a[i]=read();
	for (int d=-B;d<=B;d++)
	{
		for (int i=1;i<=n;i++) t[a[i]-i*d+M]++;
		for (int i=1;i<=n;i++) ans=max(ans,t[a[i]-i*d+M]),t[a[i]-i*d+M]=0;
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=max(i-BB,1);j<=min(i+BB,n);j++)
		if (i!=j&&(a[j]-a[i])%(j-i)==0) t[(a[j]-a[i])/(j-i)+M]++;
		for (int j=max(i-BB,1);j<=min(i+BB,n);j++)
		if (i!=j&&(a[j]-a[i])%(j-i)==0) ans=max(ans,t[(a[j]-a[i])/(j-i)+M]+1),t[(a[j]-a[i])/(j-i)+M]=0;
	}
	print(n-ans);
	
	return 0;
}