#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
inline int addmod(int x)
{
	return x>=mod?x-mod:x;
}
inline int submod(int x)
{
	return x<0?x+mod:x;
}
int fpow(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=1ll*ans*x%mod;
		x=1ll*x*x%mod;
		y/=2;
	}
	return ans;
}
int n,m,l,r,a,b;
int main()
{
	int inv2=fpow(2,mod-2);
	scanf("%d%d%d%d",&n,&m,&l,&r);
	r=r-l+1;
	a=r/2,b=r-a;
	if(n%2==1&&m%2==1)
	{
		printf("%d",fpow(r,1ll*n*m%(mod-1)+mod-1));
		return 0;
	}
	int ans=fpow(r,1ll*n*m%(mod-1)+mod-1),nw=1ll*n*m/2%(mod-1)+mod-1,f1,f2;
	int q1,q2;
	f1=fpow(addmod(a+b),nw);
	f2=fpow(submod(b-a),nw);
	q1=1ll*addmod(f1+f2)*inv2%mod;
	q2=1ll*addmod(f1-f2)*inv2%mod;
	ans=submod(ans-2ll*q1*q2%mod);
	printf("%d",ans);
	return 0;
}