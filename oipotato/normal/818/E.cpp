#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,k,a[100010],s[100010][33],prime[33],num[33],tot,tmp[33],len;
long long ans;
int main()
{
	scanf("%d%d",&n,&k);
	len=(int)sqrt(k);
	for(int i=2;i<=len;i++)
	if(k%i==0)
	{
		prime[++tot]=i;
		num[tot]=0;
		for(;k%i==0;num[tot]++,k/=i);
	}
	if(k>1)
	{
		prime[++tot]=k;
		num[tot]=1;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		for(int j=1;j<=tot;j++)
		if(a[i]%prime[j]==0)
		{
			int p=a[i];
			for(;a[i]%prime[j]==0;s[i][j]++,a[i]/=prime[j]);
		}
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=tot;j++)
	s[i][j]+=s[i-1][j];
	for(int i=1;i<=tot;i++)tmp[i]=1;
	for(int i=1;i<=n;i++)
	{
		int tans=i;
		for(int j=1;j<=tot;j++)
		{
			for(;tmp[j]<n&&s[tmp[j]][j]-s[i-1][j]<num[j];tmp[j]++);
			if(s[tmp[j]][j]-s[i-1][j]<num[j])
			{
				printf("%I64d",ans);
				return 0;
			}
			tans=max(tans,tmp[j]);
		}
		ans+=(n-tans+1);
	}
	printf("%I64d",ans);
	return 0;
}