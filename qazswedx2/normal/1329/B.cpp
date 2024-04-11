#include<cstdio>
#include<cstring>
#include<algorithm>
int t,mod,n,f[105][105],a[105];
int main() 
{
	scanf("%d",&t);
	while(t--)
	{
		memset(f,0,sizeof(f));
		scanf("%d%d",&n,&mod);
		int len=0,lim=1;
		while(lim<=n) lim<<=1,len++;
		a[0]=1;
		for(int i=1;i<len-1;i++)
			a[i]=a[i-1]*2%mod;
		a[len-1]=n-lim/2+1;
		for(int i=0;i<len;i++)
			f[1][i]=a[i];
		for(int i=2;i<=len;i++)
			for(int j=1;j<len;j++)
				for(int k=0;k<j;k++)
					f[i][j]=(f[i][j]+1ll*a[j]*f[i-1][k]%mod)%mod;
		int ans=0;
		for(int i=1;i<=len;i++)
			for(int j=0;j<len;j++)
				ans=(ans+f[i][j])%mod;
		printf("%d\n",ans);
	}
	return 0;
}