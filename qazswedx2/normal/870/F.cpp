#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,prime[10000005],p[10000005],phi[10000005],c[10000005],pt;
int main()
{
	scanf("%d",&n);
	phi[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(!p[i]) prime[++pt]=i,phi[i]=i-1,c[pt]=1;
		for(int j=1;j<=pt&&i*prime[j]<=n;j++)
		{
			int u=i*prime[j];
			p[i*prime[j]]=1;
			c[j]++;
			if(i%prime[j]==0)
			{
				phi[u]=phi[i]*prime[j];
				break;
			}
			phi[u]=phi[i]*(prime[j]-1);
		}
	}
	ll ans0,ans1,ans2,ans3;
	int ct=1,ct2;
	for(int i=1;i<=pt;i++)
		if(prime[i]*2>n) ct++;
	ans0=2ll*ct*(n-1)-1ll*(ct-1)*ct;
	ans1=0;
	for(int i=1;i<=n;i++)
		ans1+=phi[i];
	ans1=(1ll*n*(n-1)/2+1-ans1)*2;
	ans3=0;
	int nw=pt-ct+1;
	ct2=0;
	for(int i=1;i<=pt-ct+1;i++)
	{
		while(nw>i&&1ll*prime[i]*prime[nw]>n)
		{
			ct2+=c[nw];
			nw--;
		}
		while(nw<i)
		{
			nw++;
			ct2-=c[nw];
		}
	//	printf("i=%d,nw=%d,ct2=%d\n",i,nw,ct2);
		ans3+=1ll*ct2*c[i];
	}
	ans3*=2;
	ans2=1ll*n*(n-1)-ans0-ans1-ans3;
//	printf("%lld %lld %lld %lld\n",ans0,ans1,ans2,ans3);
	ll ans=ans1+2*ans2+3*ans3;
	printf("%lld\n",ans/2);
	return 0;
}