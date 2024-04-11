#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
int n,sn,sum[1000005],a[1000005],at;
short f[82000005];
int g[82000005];
char s[1000005];
ll tans=0;
int main()
{
	//freopen("cf1270f.in","r",stdin);
	scanf("%s",s+1);
	n=strlen(s+1);
	sn=min((int)sqrt(n),400);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+s[i]-'0';
		if(s[i]=='1') a[++at]=i;
	}
	a[at+1]=n+1;
	for(int i=1;i<=sn;i++)
	{
		for(int j=0;j<=n;j++)
		{
			int v=j-sum[j]*i+81000000;
			//if(v<=0)printf("v=%d\n",v);
			if(f[v]==i) tans+=g[v],g[v]++;
			else f[v]=i,g[v]=1;
		}
	}
//	printf("tans=%lld\n",tans);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n/sn;j++)
		{
			if(sum[i-1]+j>at) continue;
			int v=sum[i-1]+j;
			int l=max(a[v],i+j*sn)-i+1,r=a[v+1]-1-i+1;
			if(l>r) continue;
			//printf("i=%d,j=%d,l=%d,r=%d\n",i,j,l,r);
			tans+=r/j-(l-1)/j;
		}
	printf("%I64d\n",tans);
	return 0;
}