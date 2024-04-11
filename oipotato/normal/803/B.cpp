#include<cstdio>
#include<algorithm>
using namespace std;
int ans[200010],a[200010],n,last;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	last=-2*n;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0)last=i;
		ans[i]=i-last;
	}
	last=3*n;
	for(int i=n;i>=1;i--)
	{
		if(a[i]==0)last=i;
		ans[i]=min(ans[i],last-i);
	}
	for(int i=1;i<n;i++)printf("%d ",ans[i]);
	printf("%d",ans[n]);
	return 0;
}