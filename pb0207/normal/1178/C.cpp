#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

typedef long long ll;

const int N=1e5+1e3+7,P=998244353;

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

int main()
{
	ll n,m;
	scanf("%lld%lld",&n,&m);
	printf("%lld",qpow(2,n+m));
}