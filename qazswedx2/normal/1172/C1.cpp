#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,f[105][105][105],a[100005],b[100005],sum0,sum1,inv[100005];
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
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		if(a[i]==0) sum0+=b[i];
		else sum1+=b[i];
	}
	for(int i=1;i<=100000;i++)
		inv[i]=fpow(i,mod-2);
	for(int i=1;i<=n;i++)
	{
		memset(f,0,sizeof(f));
		f[0][0][0]=1;
		if(a[i]==0) sum0-=b[i];
		else sum1-=b[i];
		if(a[i]==0)
		{
			for(int j=0;j<m;j++)
				for(int k=0;k<=min(j,b[i]);k++)
					for(int l=0;l<=m;l++)
					{
						if(j-l-k<0) continue;
						int nw=j-l-k,nwinv=inv[sum0+sum1+b[i]-k-l+nw];
						if(k<b[i]) f[j+1][k+1][l]=(f[j+1][k+1][l]+
						1ll*(b[i]-k)*nwinv%mod*f[j][k][l]%mod)%mod;
						if(l<sum0) f[j+1][k][l+1]=(f[j+1][k][l+1]+
						1ll*(sum0-l)*nwinv%mod*f[j][k][l]%mod)%mod;
						f[j+1][k][l]=(f[j+1][k][l]+
						1ll*(nw+sum1)*nwinv%mod*f[j][k][l]%mod)%mod;
					}
		}		
		else
		{
			for(int j=0;j<m;j++)
				for(int k=0;k<=j;k++)
					for(int l=0;l<=m;l++)
					{
						if(j-l-k<0) continue;
						int nw=j-l-k,nwinv=inv[sum0+sum1+b[i]+k+l-nw];
						f[j+1][k+1][l]=(f[j+1][k+1][l]+
						1ll*(b[i]+k)*nwinv%mod*f[j][k][l]%mod)%mod;
						f[j+1][k][l+1]=(f[j+1][k][l+1]+
						1ll*(sum1+l)*nwinv%mod*f[j][k][l]%mod)%mod;
						if(sum0>nw) f[j+1][k][l]=(f[j+1][k][l]+
						1ll*(sum0-nw)*nwinv%mod*f[j][k][l]%mod)%mod;
					}
		}
		int ans=0;
		for(int j=0;j<=m;j++)
			for(int k=0;k<=m;k++)
			{
				if(m-j-k<0) continue;
				if(a[i]==0&&b[i]-j<0) continue;
				if(a[i]==0) ans=(ans+1ll*(b[i]-j)*f[m][j][k])%mod;
				else ans=(ans+1ll*(b[i]+j)*f[m][j][k])%mod;
			}
		printf("%d\n",ans);
		if(a[i]==0) sum0+=b[i];
		else sum1+=b[i];
	}
	return 0;
}