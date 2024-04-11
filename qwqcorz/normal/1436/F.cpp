#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
const int N=1e5+5;
const int p=998244353;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int power(int a,int b)
{
	int ret=1;
	while (b)
	{
		if (b&1) ret=ret*a%p;
		a=a*a%p;
		b/=2;
	}
	return ret;
}
int a[N],mu[N],m=0,ans=0;
int f(int x)
{
	int tot=0,sum=0,sum0=0;
	for (int i=x;i<=m;i+=x) if (a[i])
	{
		tot+=a[i];
		sum=(sum+a[i]%p*i)%p;
		sum0=(sum0+a[i]%p*i%p*i)%p;
	}
	if (tot<=1) return 0;
	int ret=(tot-1)%p*sum0%p*power(2,tot-2)%p;
	int val=tot==2?1:tot%p*power(2,tot-3)%p;
	ret=(ret+(sum*sum-sum0+p)%p*val)%p;
	return ret;
}

signed main()
{
	int n=read();
	for (int i=1;i<=n;i++)
	{
		int x=read();
		a[x]+=read();
		m=max(m,x);
	}
	for (int i=mu[1]=1;i<=m;i++)
	for (int j=i+i;j<=m;j+=i) mu[j]-=mu[i];
	for (int i=1;i<=m;i++) ans=(ans+(mu[i]+p)*f(i))%p;
	print(ans);
	
	return 0;
}