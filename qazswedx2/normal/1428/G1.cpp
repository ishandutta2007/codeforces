#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,m,a[15],pw[15],pn=999999;
int q[10000005],head,tail;
ll dp[1000005],dp2[1000005];
int main()
{
	memset(dp,0xcf,sizeof(dp));
	dp[0]=0;
	scanf("%d",&n);
	for(int i=0;i<6;i++)
		scanf("%d",&a[i]);
	pw[0]=1;
	for(int i=1;i<6;i++)
		pw[i]=pw[i-1]*10;
	for(int i=0;i<6;i++)
	{
		memset(dp2,0xcf,sizeof(dp2));
		for(int j=0;j<3*pw[i];j++)
		{
			head=1,tail=0;
			for(int k=j;k<=pn;k+=3*pw[i])
			{
				while(head<=tail&&dp[q[tail]]-1ll*(q[tail]-j)/(3*pw[i])*a[i]<dp[k]-1ll*(k-j)/(3*pw[i])*a[i])
					tail--;
				while(head<=tail&&(k-q[head])/(3*pw[i])>3*(n-1))
					head++;
				q[++tail]=k;
				for(int l=0;l<=9;l++)
				{
					if(k+l*pw[i]>pn) continue;
					ll v=1ll*(l%3==0?l/3:0)*a[i];
				/*	if(k+l*pw[i]<=10&&dp2[k+l*pw[i]]<v+dp[q[head]]+1ll*(k-q[head])/(3*pw[i])*a[i])
					{
						printf("i=%d,j=%d,k=%d,l=%d,q=%d,v=%lld,%lld\n",i,j,k,l,q[head],dp2[k+l],v+dp[q[head]]+1ll*(k-q[head])/(3*pw[i])*a[i]);
					}*/
					dp2[k+l*pw[i]]=max(dp2[k+l*pw[i]],v+dp[q[head]]+1ll*(k-q[head])/(3*pw[i])*a[i]);
				}
			}
		}
	/*	printf("i=%d\n",i);
		for(int i=0;i<50;i++)
			if(dp2[i]<0) printf("- ");
			else printf("%lld ",dp2[i]);
		printf("\n");*/
		memcpy(dp,dp2,sizeof(dp2));
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int x;
		scanf("%d",&x);
		printf("%lld\n",dp[x]);
	}
	return 0;
}