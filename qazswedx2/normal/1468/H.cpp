#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,m,k,a[200005],vis[200005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&k,&m);
		for(int i=1;i<=n;i++)
			vis[i]=0;
		k--;
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&a[i]);
			vis[a[i]]++;
		}
		if((n-m)%k!=0)
		{
			printf("NO\n");
			continue;
		}
		int ct=0,fl=0;
		for(int i=1;i<=n;i++)
		{
			if(vis[i])
			{
				if(ct>=k/2&&n-m-ct>=k/2)
				{
					fl=1;
					break;
				}
			}
			else ct++;
		}
		if(fl) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}