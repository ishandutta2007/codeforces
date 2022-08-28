#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[1000005],tans[1000005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int nw=a[(n+1)/2],l=(n+1)/2,r=(n+1)/2;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==nw)
		{
			l=min(l,i);
			r=max(r,i);
		}
	}
//	printf("l=%d,r=%d\n",l,r);
	int ans=-1;
	for(int i=1;i<n-i;i++)
	{
		int nw1=max(0,i-l+1),nw2=max(0,r-(n-i)+1);
		//printf("i=%d,nw1=%d,nw2=%d\n",i,nw1,nw2);
		if(nw1+nw2>i&&!(nw1==0&&nw2==i+1))
		{
			ans=i-1;
			break;
		}
	}
	if(ans==-1) ans=(n-1)/2;
	printf("%d\n",ans);
	for(int i=1,j=n-ans;j<=n;j++,i+=2)
		tans[i]=a[j];
	for(int i=2,j=1;j<=ans;j++,i+=2)
		tans[i]=a[j];
	for(int i=ans*2+2,j=ans+1;j<=n-ans-1;j++,i++)
		tans[i]=a[j];
	for(int i=1;i<=n;i++)
		printf("%d ",tans[i]);
	return 0;
}