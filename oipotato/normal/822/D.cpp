#include<cstdio>
#include<algorithm>
using namespace std;
const int MOD=1E9+7;
int ans,t,l,r,prime[1000010],tot;
long long f[5000010];
bool notp[5000010];
int main()
{
	scanf("%d%d%d",&t,&l,&r);
	for(int i=2;i<=r;i++)
	{
		if(!notp[i])
		{
			prime[++tot]=i;
			f[i]=(long long)i*(i-1)/2;
		}
		for(int j=1;j<=tot;j++)
		{
			if((long long)prime[j]*i>r)break;
			if(!f[prime[j]*i]||f[i]+f[prime[j]]*i<f[prime[j]*i])f[prime[j]*i]=f[i]+f[prime[j]]*i;
			notp[prime[j]*i]=1;
		}
	}
	for(int i=r;i>=l;i--)ans=((long long)ans*t+f[i])%MOD;
	printf("%d",ans);
	return 0;
}