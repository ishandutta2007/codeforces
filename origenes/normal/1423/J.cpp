#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LC k<<1
#define RC k<<1|1

typedef long long LL;

const int N=110000;
const int M=1100000;
const LL mod=1e9+7;

int T;
LL m;
int tmp[16];
LL inv2;
LL pow_mod(LL a,LL e)
{
	LL res=1;
	for (;e;a=a*a%mod,e>>=1) if (e&1) res=res*a%mod;
	return res;
}
int main()
{
	scanf("%d",&T);
	inv2=pow_mod(2,mod-2);
	while (T--)
	{
		scanf("%I64d",&m);
		m>>=1;
		LL x=m/2LL+1;
		LL t1=x%mod,t2=(x+1)%mod;
		LL t=t1*t2%mod;
		if (m%2==0) t=(t+mod-(x%mod))%mod;
		printf("%I64d\n",t);
	}
	return 0;
}