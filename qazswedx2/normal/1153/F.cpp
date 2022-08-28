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
int n,k,l,f[5005][5005],fr[100005],pn=1e5;
int main()
{
	fr[0]=1;
	for(int i=1;i<=pn;i++)
		fr[i]=1ll*fr[i-1]*i%mod;
	scanf("%d%d%d",&n,&k,&l);
	f[0][0]=1;
	for(int i=1;i<=2*n;i++)
		for(int j=0;j<=i;j++)
		{
			if(j) f[i][j]=addmod(f[i][j]+f[i-1][j-1]);
			f[i][j]=addmod(f[i][j]+1ll*f[i-1][j+1]*(j+1)%mod);
	//		printf("i=%d,j=%d,f=%d\n",i,j,f[i][j]);
		}
	int ans=0;
	for(int i=1;i<=2*n;i++)
		for(int j=k;j<=i;j++)
			ans=addmod(ans+1ll*f[i][j]*f[2*n-i][j]%mod*fr[j]%mod);
//	printf("ans=%d\n",ans);
	ans=1ll*ans*fpow(f[2*n][0],mod-2)%mod*l%mod*fpow(2*n+1,mod-2)%mod;
	printf("%d\n",ans);
	return 0;
}