#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
typedef long long ll;
int t,n,a[1000005],b[1000005][2],bt,c[1000005][2],ct;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		bt=0;
		ll tans=0;
		for(int i=n;i>0;i--)
		{
			int s=1;
			while(1ll*(s+1)*(s+1)<=a[i]) s++;
			ct=0;
			int nw=1,sum=0;
			for(int j=1;j<=s;j++)
			{
				int x=a[i]/j,y=(a[i]+j-1)/j;
				sum=0;
				while(nw<=bt&&b[nw][0]>=y)
				{
					sum+=b[nw][1];
					nw++;
				}
				if(j==1) sum++;
				c[++ct][0]=x;
				c[ct][1]=sum;
			//	printf("i=%d,j=%d,sum=%d\n",i,j,sum);
				tans+=1ll*(j-1)*sum*i;
				tans%=mod;
			}
			for(int j=c[ct][0]-1;j>0;j--)
			{
				int x=j;
				sum=0;
				while(nw<=bt&&b[nw][0]>=j+1)
				{
					sum+=b[nw][1];
					nw++;
				}
			//	printf("i=%d,j=%d,%d,%d\n",i,j,(a[i]/(j+1)),sum);
				tans+=1ll*(a[i]/(j+1))*sum*i;
				tans%=mod;
				if(a[i]%j==0)
				{
					while(nw<=bt&&b[nw][0]==j)
					{
						sum+=b[nw][1];
						tans+=1ll*(a[i]/j-1)*b[nw][1]*i;
						tans%=mod;
						nw++;
					}
				}
				c[++ct][0]=x;
				c[ct][1]=sum;
			}
		/*	printf("i=%d,tans=%lld,ct=%d,c=",i,tans,ct);
			for(int j=1;j<=ct;j++)
				printf("(%d,%d) ",c[j][0],c[j][1]);
			printf("\n");*/
			for(int j=1;j<=ct;j++)
				b[j][0]=c[j][0],b[j][1]=c[j][1];
			bt=ct;
		}
		printf("%lld\n",tans);
	}
	return 0;
}