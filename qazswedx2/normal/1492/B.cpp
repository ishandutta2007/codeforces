#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,a[100005],tans[100005],tt,vis[100005],mx;
int main()
{
	scanf("%d",&tt);
	while(tt--)
	{
		t=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		reverse(a+1,a+n+1);
		for(int i=1;i<=n;i++)
			vis[i]=1;
		mx=n;
		int l=1;
		for(int i=1;i<=n;i++)
		{
		/*	printf("i=%d,a=%d,mx=%d,l=%d\n",i,a[i],mx,l);
			for(int j=1;j<=n;j++)
				printf("%d ",vis[j]);
			printf("\n");*/
			if(mx==a[i])
			{
				for(int j=i;j>=l;j--)
					tans[++t]=a[j];
				for(int j=l;j<=i;j++)
					vis[a[j]]=0;
				l=i+1;
				while(mx&&!vis[mx]) mx--;
			}
		}
		for(int i=1;i<=n;i++)
			printf("%d ",tans[i]);
		printf("\n");
	}
	return 0;
}