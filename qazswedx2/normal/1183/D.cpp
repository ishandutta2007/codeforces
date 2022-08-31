#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,a[1000005],vis[1000005],vvis[1000005];
long long ans;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			vis[a[i]]++;
		}
		for(int i=1;i<=n;i++)
			vvis[vis[i]]++;
		for(int i=n;i>0;i--)
		{
			if(vvis[i]) vvis[i-1]+=(vvis[i]-1),ans+=i;
		}
		for(int i=1;i<=n;i++)
			vvis[i]=0;
		for(int i=1;i<=n;i++)
			vis[i]=0;
		printf("%I64d\n",ans);
	}
	return 0;
}