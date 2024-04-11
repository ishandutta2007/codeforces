#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,b[1000005],id;
double a[1000005],sum[1000005],ans;
int q[1000005],head,tail;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		a[i]=b[i];
		sum[i]=sum[i-1]+a[i];
	}
	head=1,tail=0;
	for(int i=1;i<=n;i++)
	{
		while(head<tail&&(sum[q[tail]]-sum[q[tail-1]])/(q[tail]-q[tail-1])>(sum[i]-sum[q[tail]])/(i-q[tail]))
			tail--;
		q[++tail]=i;
	}
	for(int i=1;i<=n;)
	{
		while(head<tail&&q[head]<i) head++;
		while(head<tail&&(sum[q[head]]-sum[i-1])/(q[head]-(i-1))>(sum[q[head+1]]-sum[i-1])/(q[head+1]-(i-1)))
			head++;
		double nw=(sum[q[head]]-sum[i-1])/(q[head]-(i-1));
		//printf("i=%d,q=%d\n",i,q[head]);
		for(int j=i;j<=q[head];j++)
			a[j]=nw;
		i=q[head]+1;
	}
	for(int i=1;i<=n;i++)
		printf("%.11f\n",a[i]);
	/*int nw=1;
	while(nw<=n)
	{
		double l=0,r=1e6;
		while(r-l>=1e-12)
		{
			double mid=(l+r)/2;
			if(check(mid,nw)) l=mid;
			else r=mid;
		}
		for(int i=1;i<=)
	}*/
}