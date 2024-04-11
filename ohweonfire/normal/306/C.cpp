#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=4005;
const LL mod=1000000009;
LL fact[maxn],invfact[maxn];
int w,b,n;
LL power(LL x,LL y)
{
	LL res=1;
	while(y)
	{
		if(y&1)res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
LL C(int x,int y)
{
	if(x<y)return 0;
	return fact[x]*invfact[y]%mod*invfact[x-y]%mod;
}
int main()
{
	scanf("%d%d%d",&n,&w,&b);
	fact[0]=invfact[0]=1;
	for(int i=1;i<maxn;i++)
	{
		fact[i]=fact[i-1]*i%mod;
		invfact[i]=power(fact[i],mod-2);
	}
	LL ans=0;
	for(int i=1;i<=n-2;i++)
		ans=(ans+C(b-1,i-1)*C(w-1,n-i-1)%mod*(n-i-1)%mod)%mod;
	printf("%I64d\n",ans*fact[w]%mod*fact[b]%mod);
	return 0;
}