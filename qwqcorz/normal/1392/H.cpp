#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=4e6+5;
const int p=998244353;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int fact[N],invf[N],inv[N],F[N];
void ysgs(int n)
{
	inv[0]=inv[1]=1;
	for (int i=2;i<=n;i++) inv[i]=1LL*inv[p%i]*(p-p/i)%p;
	for (int i=fact[0]=1;i<=n;i++) fact[i]=1LL*fact[i-1]*i%p;
	for (int i=invf[0]=1;i<=n;i++) invf[i]=1LL*invf[i-1]*inv[i]%p;
}
int C(int n,int m)
{
	if (n<m||m<0) return 0;
	return 1LL*fact[n]*invf[m]%p*invf[n-m]%p;
}

signed main()
{
	int n=read(),m=read(),T=0,ans=0;
	ysgs(n+m);
	for (int i=1,sum=0;i<=n+1;i++)
	{
		F[i]=(1LL-sum+p)*m%p*inv[n+m-i+1]%p;
		T=(T+1LL*i*F[i])%p;
		sum=(sum+F[i])%p;
	}
	for (int i=1;i<=n;i++) ans=(ans+((i&1)?1LL:p-1LL)*C(n,i)%p*(i+m)%p*inv[i])%p;
	print(1LL*T*ans%p);
	
	return 0;
}