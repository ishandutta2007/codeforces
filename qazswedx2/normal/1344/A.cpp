#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,vis[1000005],a[1000005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			vis[i]=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			a[i]=(a[i]%n+n)%n;
			vis[(a[i]+i)%n]++;
		}
		int fl=1;
		for(int i=0;i<n;i++)
			if(vis[i]>1)
			{
				fl=0;break;
			}
		if(fl) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}