#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,p,k,a[1000005],sum[1000005];
bool check(int x)
{
	return sum[x]<=p;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&p,&k);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		for(int i=1;i<=k-1;i++)
			sum[i]=a[i]+sum[i-1];
		for(int i=k;i<=n;i++)
			sum[i]=a[i]+sum[i-k];
		for(int i=n-1;i>0;i--)
			if(sum[i]>sum[i+1]) sum[i]=sum[i+1];
		/*for(int i=1;i<=n;i++)
			printf("%d ",sum[i]);
		printf("\n");*/
		int l=0,r=n,mid;
		while(l<=r)
		{
			mid=(l+r)/2;
			if(check(mid)) l=mid+1;
			else r=mid-1;
		}
		printf("%d\n",r);
	}
	return 0;
}