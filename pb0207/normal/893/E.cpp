#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

const int N=2e6+1e3+7,LIM=2e6,P=1e9+7;

ll fac[N],inv[N];

int n,x,y;

ll qpow(ll a,ll b)
{
	ll ret=1;
	while(b)
	{
		if(b&1)
			ret=ret*a%P;
		b>>=1;
		a=a*a%P;
	}
	return ret;
}

void pre()
{
	fac[0]=1;
	for(int i=1;i<=LIM;i++)
		fac[i]=fac[i-1]*i%P;
	inv[LIM]=qpow(fac[LIM],P-2);
	for(int i=LIM-1;i>=0;i--)
		inv[i]=inv[i+1]*(i+1)%P;
}

ll C(ll n,ll m)
{
	if(n<m||n<0||m<0)
		return 0;
	return fac[n]*inv[m]%P*inv[n-m]%P;
}

ll calc(int x)
{
	ll ret=1;
	for(int j=2;j*j<=x;j++)
		if(x%j==0)
		{
			int tot=0;
			while(x%j==0)
				tot++,x/=j;
			ret=ret*C(tot+y-1,tot)%P;
		}
	if(x!=1)
		ret=ret*C(1+y-1,1)%P;
	return ret;
} 

int main()
{
	pre();
	cin>>n;
	while(n--)
	{
		scanf("%d%d",&x,&y);
		printf("%lld\n",calc(x)*qpow(2,y-1)%P);
	}
}