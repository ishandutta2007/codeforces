#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

const ll P=1e9+7;

ll x,y;

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

int pf[21],cnt,bit[1000001];

int c[2]={1,-1};

int main()
{
	scanf("%lld%lld",&x,&y);
	for(int i=1;i<=1000000;i++)
		bit[i]=bit[i>>1]+(i&1);
	if(y%x!=0)
	{
		puts("0");
		return 0;
	}
	y/=x;
	ll t=y;
	for(int i=2;i*i<=t;i++)
		if(t%i==0)
		{
			pf[++cnt]=i;
			while(t%i==0)
				t/=i;
		}
	if(t!=1)
		pf[++cnt]=t;
	ll all=(1<<cnt)-1,ans=0;
	for(int S=0;S<=all;S++)
	{
		ll zz=1;
		for(int j=1;j<=cnt;j++)
			if(S&(1<<(j-1)))
				zz=zz*pf[j];
		ans=(ans+c[bit[S]&1]*qpow(2,y/zz-1)%P+P)%P;
	}
	printf("%lld",ans);
}