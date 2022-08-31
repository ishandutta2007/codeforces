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
int T,n,a[100005],b[100005],fr[100005],infr[100005],pn=1e5,f[5005][5005];
int main()
{
	fr[0]=infr[0]=1;
	for(int i=1;i<=pn;i++)
		fr[i]=1ll*fr[i-1]*i%mod;
	infr[pn]=fpow(fr[pn],mod-2);
	for(int i=pn-1;i>0;i--)
		infr[i]=1ll*infr[i+1]*(i+1)%mod; 
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=0;i<=n+1;i++)
			b[i]=0;
		for(int i=1;i<=n;i++)
			b[a[i]]++;
		int sum=0;
		for(int i=0;i<=n+1;i++)
			for(int j=0;j<=n+1;j++)
				f[i][j]=0;
		f[0][0]=1;
		for(int i=1;i<=n;i++)
		{
			if(!b[i])
			{
				for(int j=0;j<=i;j++)
					f[i][j]=f[i-1][j];
				continue;
			}
			for(int j=0;j<=i;j++)
			{
				f[i][j]=1ll*f[i-1][j]*infr[b[i]]%mod;
				if(!j) continue;
				int v=sum-j+1-max(j-2,0);
				if(j==1||j==n/2+1) f[i][j]=addmod(f[i][j]+1ll*f[i-1][j-1]*infr[b[i]-1]%mod);
				else if(v>0) f[i][j]=addmod(f[i][j]+1ll*f[i-1][j-1]*v%mod*infr[b[i]-1]%mod);	
			//	printf("i=%d,j=%d,f=%d,v=%d\n",i,j,f[i][j],v);
			}
			sum+=b[i];
		}
		/*for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=i;j++)
			{
				int u=n/2-1-max(j-1,0),v=i-j-1-max(j-2,0);
				if(j&&(i==1||a[i]!=a[i-1]))
				{
					if(j==)
					f[i][j]=addmod(f[i][j]+1ll*f[i-1][j-1]*v%mod);
				}
				f[i][j]=addmod(f[i][j]+1ll*f[i-1][j]);
				printf("i=%d,j=%d,f=%d,u=%d,v=%d\n",i,j,f[i][j],u,v);
			}
		}*/
		printf("%d\n",f[n][n/2+1]);
	/*	for(int i=1;i<=n;i++)
		{
			sum+=b[i];
			
		}*/
	}
	return 0;
}