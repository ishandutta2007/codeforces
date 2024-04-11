#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
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
int n,a[1000005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=2*n;i++)
		scanf("%d",&a[i]);
	int mul=1,mul2=1;
	for(int i=1;i<=2*n;i++)
		mul=1ll*mul*i%mod;
	for(int i=1;i<=n;i++)
		mul2=1ll*mul2*i%mod;
	mul2=fpow(mul2,mod-2);
	mul=1ll*mul*mul2%mod*mul2%mod;
	sort(a+1,a+2*n+1);
	int ans=0;
	for(int i=1;i<=n;i++)
		ans=(ans-a[i]+mod)%mod;
	for(int i=n+1;i<=2*n;i++)
		ans=(ans+a[i])%mod;
	ans=1ll*ans*mul%mod;
	printf("%d\n",ans);
	return 0;
}