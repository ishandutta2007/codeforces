#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
const int p=1e9+7;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int power(int a,int b)
{
	int ret=1;
	while (b)
	{
		if (b&1) ret=1LL*ret*a%p;
		a=1LL*a*a%p;
		b/=2;
	}
	return ret;
}
int fact[N],invf[N],inv[N],dp[N],sum[N];
void ysgs(int n)
{
	for (int i=fact[0]=1;i<=n;i++) fact[i]=1LL*fact[i-1]*i%p;
	invf[n]=power(fact[n],p-2);
	for (int i=n;i>=1;i--) invf[i-1]=1LL*invf[i]*i%p;
	for (int i=1;i<=n;i++) inv[i]=1LL*fact[i-1]*invf[i]%p;
	inv[0]=1;
}
void GreenDay()
{
	ysgs(1e6);
	int n=read(),k=read();
	sum[1]=dp[1]=fact[n-1];
	for (int i=2;i<=n;i++)
	{
		dp[i]=1LL*inv[i-1]*(sum[i-1]-sum[max(i-k-1,0)]+p)%p;
		sum[i]=(sum[i-1]+dp[i])%p;
	}
	print((fact[n]-sum[n]+p)%p);
}

signed main()
{
	int T=1;
//	int T=read();
	while (T--) GreenDay();
	
	return 0;
}