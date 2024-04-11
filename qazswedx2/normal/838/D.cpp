#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
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
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	printf("%lld\n",1ll*fpow(2*(n+1),m)*(n+1-m)%mod*fpow(n+1,mod-2)%mod);
	return 0;
}