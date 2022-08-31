#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int mod=1e9+7;
int n,mu[100005],p[100005],prime[100005],pt,f[100005],ninv;
vector<int> a[100005],b[100005];
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
	scanf("%d",&n);
	ninv=fpow(n,mod-2);
	mu[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(!p[i]) prime[++pt]=i,mu[i]=-1;
		for(int j=1;j<=pt&&i*prime[j]<=n;j++)
		{
			p[i*prime[j]]=1;
			if(i%prime[j]==0)
			{
				mu[i*prime[j]]=0;
				break;
			}
			mu[i*prime[j]]=-mu[i];
		} 
	}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j+=i)
			a[j].push_back(i);
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j+=i)
		{
			int nw=0,nww=j/i;
			for(int k=0;k<a[j/i].size();k++)
			{
				int val=a[nww][k];
				if(mu[val]==1) nw=addmod(nw+n/i/val);
				else if(mu[val]==-1) nw=submod(nw-n/i/val);
			}
			b[j].push_back(nw);
		}
	/*for(int i=1;i<=n;i++)
	{
		for(int j=0;j<b[i].size();j++)
			printf("%d ",b[i][j]);
		printf("\n");
	}*/
	f[1]=0;
	for(int i=2;i<=n;i++)
	{
		f[i]=n;
		for(int j=0;j<a[i].size();j++)
		{
			int val=a[i][j];
			if(val==i) break;
			f[i]=addmod(f[i]+1ll*f[val]*b[i][j]%mod);
		}
		//printf("%d ",f[i]);
		f[i]=1ll*f[i]*fpow(n-b[i][a[i].size()-1],mod-2)%mod;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		ans=addmod(ans+f[i]);
	ans=addmod(1ll*ans*ninv%mod+1);
	printf("%d",ans);
	return 0;
}