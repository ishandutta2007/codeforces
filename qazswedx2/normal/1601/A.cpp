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
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
			vis[i]=1;
		for(int i=0;i<=30;i++)
		{
			int ct=0;
			for(int j=1;j<=n;j++)
				if(a[j]&(1<<i))
					ct++;
			for(int j=1;j<=n;j++)
				if(ct%j) vis[j]=0;
		}
		for(int i=1;i<=n;i++)
			if(vis[i])
				printf("%d ",i);
		printf("\n");
	}
	return 0;
}