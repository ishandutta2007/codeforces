#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
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
int n,m,p,k,a[100005],f[2005][2005],s[2005][2005];
int main()
{
	int A,B;
	scanf("%d%d%d%d%d",&n,&m,&A,&B,&k);
	p=1ll*A*fpow(B,mod-2)%mod;
	int mul=1;
	for(int i=0;i<=min(k,m);i++)
	{
		a[i]=1ll*mul*fpow(p,i)%mod*fpow(submod(1-p),k-i)%mod;
		mul=1ll*mul*(k-i)%mod*fpow(i+1,mod-2)%mod;
	}
	f[0][m]=s[0][m]=1;
	for(int i=1;i<=n;i++)
	{
		int sum=0,sum2=0;
		for(int j=1;j<=m;j++)
		{
			sum=addmod(sum+a[j-1]);
			sum2=addmod(sum2+1ll*a[j-1]*s[i-1][j-1]%mod);
			f[i][j]=submod(1ll*a[m-j]*(s[i-1][m]-s[i-1][m-j]+mod)%mod*sum%mod-1ll*a[m-j]*sum2%mod);
		}
		for(int j=1;j<=m;j++)
			s[i][j]=addmod(s[i][j-1]+f[i][j]);
	}
	int ans=s[n][m];
	printf("%d\n",ans);
	return 0;
}