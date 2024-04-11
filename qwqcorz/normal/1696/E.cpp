#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=4e5+5;
const int p=1e9+7;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int power(int a,int b)
{
	int ret=1;
	for (;b;a=1LL*a*a%p,b/=2) if (b&1) ret=1LL*ret*a%p;
	return ret;
}
int fact[N],inv[N],a[N];
void ysgs(int n)
{
	for (int i=fact[0]=1;i<=n;i++) fact[i]=1LL*fact[i-1]*i%p;
	inv[n]=power(fact[n],p-2);
	for (int i=n;i>=1;i--) inv[i-1]=1LL*inv[i]*i%p;
}
int C(int n,int m)
{
	if (n<m||m<0) return 0;
	return 1LL*fact[n]*inv[m]%p*inv[n-m]%p;
}

signed main()
{
	ysgs(400004);
	int n=read(),ans=0;
	for (int i=0;i<=n;i++) a[i]=read();
	for (int i=0;i<=n;i++) ans=(ans+C(a[i]+i,i+1))%p;
	print(ans);
	
	return 0;
}