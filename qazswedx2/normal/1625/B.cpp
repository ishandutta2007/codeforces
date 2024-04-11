#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,a[1000005],vis[1000005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int m=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			m=max(m,a[i]);
		}
		for(int i=0;i<=m+2;i++)
			vis[i]=0;
		int ans=-1;
		for(int i=1;i<=n;i++)
		{
			if(vis[a[i]])
			{
				ans=max(ans,vis[a[i]]+n-i);
			}
			vis[a[i]]=i;
		}
		printf("%d\n",ans); 
		
	}
}