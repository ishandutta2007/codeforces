#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,ans=0,mod=1e9+7,c[1005][1005];
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
inline int addmod(int x)
{
	return x>=mod?x-mod:x;
}
inline int submod(int x)
{
	return x<0?x+mod:x;
}
int main()
{
	scanf("%d%d",&n,&m);
	if(m==1)
	{
		printf("1");
		return 0;
	}
	for(int i=0;i<=n;i++)
		c[i][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			c[i][j]=addmod(c[i-1][j]+c[i-1][j-1]);
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
		{
			int nw=1ll*c[n][i]*c[n][j]%mod*fpow(m,(n-i)*(n-j))%mod*fpow(m-1,i*n+j*(n-i))%mod;
			if((i+j)%2) ans=submod(ans-nw);
			else ans=addmod(ans+nw);
		}
	printf("%d",ans);
	return 0;
}