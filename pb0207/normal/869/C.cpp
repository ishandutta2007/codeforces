#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
typedef long long ll;

const int N=5e3+1e1+7,P=998244353;

ll a,b,c,fac[N],rev[N];

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
	for(int i=1;i<N;i++)
		fac[i]=fac[i-1]*i%P;
	rev[N-1]=qpow(fac[N-1],P-2);
	for(int i=N-2;i>=0;i--)
		rev[i]=rev[i+1]*(i+1)%P;
}

ll C(ll n,ll m)
{
	return fac[n]*rev[m]%P*rev[n-m]%P;
}

ll calc(ll x,ll y)
{
	ll ret=0;
	if(x>y)
		swap(x,y);
	for(int i=0;i<=x;++i)
		ret=(ret+C(x,i)*C(y,i)%P*fac[i]%P)%P;
	return ret;
}


int main()
{
	pre();
	cin>>a>>b>>c;
	cout<<calc(a,b)*calc(b,c)%P*calc(a,c)%P;
}