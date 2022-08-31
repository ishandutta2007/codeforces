#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[1000005],b[1000005],pre[1000005],dis[1000005],st[1000005],tp;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	int nw=n;
	for(int i=n;i>0;i--)
	{
		if(nw>i)
		{
			printf("-1\n");
			return 0;
		}
		int u=i+b[i];
		while(nw>u-a[u])
		{
			nw--;
			pre[nw]=i;
			dis[nw]=dis[i]+1;
		}
	}
	if(nw) printf("-1\n");
	else
	{
		printf("%d\n",dis[0]);
		int u=0;
		while(u!=n)
		{
			st[++tp]=u;
			u=pre[u];
		}
		for(int i=tp;i>0;i--)
			printf("%d ",st[i]);
		printf("\n");
	}
	return 0;
}