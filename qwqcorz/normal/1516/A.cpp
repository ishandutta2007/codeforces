#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=105;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int a[N];
void GreenDay()
{
	int n=read(),k=read(),sum=0;
	for (int i=1;i<=n;i++)
	{
		a[i]=read();
		int tmp=min(a[i],k);
		k-=tmp,a[i]-=tmp,sum+=tmp;
	}
	a[n]+=sum;
	for (int i=1;i<=n;i++) print(a[i]," \n"[i==n]);
}

signed main()
{
	int T=read();
	while (T--) GreenDay();
	
	return 0;
}