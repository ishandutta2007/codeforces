#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3e5+5;
const int p=998244353;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int power(int a,int b)
{
	int ret=1;
	for (;b;a=1LL*a*a%p,b/=2) if (b&1) ret=1LL*ret*a%p;
	return ret;
}
int a[N],sum[N];

signed main()
{
	int n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n,greater<int>());
	for (int i=n;i>=1;i--) sum[i]=(sum[i+1]+a[i])%p;
	for (int k=1;k<=n;k++)
	{
		int ans=0;
		for (int i=1,j=k+1;j<=n;j+=k,i++) ans=(ans+sum[j])%p;
		print(1LL*ans*power(n,p-2)%p," \n"[k==n]);
	}
	
	return 0;
}