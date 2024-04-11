#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
int n,m,k,s[5005][5005];
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
int main()
{
	for(int i=0;i<=5000;i++)
		s[0][0]=1;
	for(int i=1;i<=5000;i++)
		for(int j=1;j<=i;j++)
			s[i][j]=addmod(s[i-1][j-1]+1ll*j*s[i-1][j]%mod);
	scanf("%d%d%d",&n,&m,&k);
	int ans=0,nw=1;
	for(int i=1;i<=min(n,k);i++)
	{
		nw=1ll*nw*(n-i+1)%mod;
		ans=addmod(ans+1ll*s[k][i]*nw%mod*fpow(m,n-i)%mod);
	}
	ans=1ll*ans*fpow(fpow(m,n),mod-2)%mod;
	printf("%d",ans);
	return 0;
}