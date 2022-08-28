#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[1000005],b[1000005],vis[1000005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	int fl=1;
	if(!b[n]) fl=0;
	for(int i=n;n-i<b[n];i--)
		if(b[i]!=b[n]-(n-i)||!b[i])
			fl=0;
	for(int i=1;i<=n;i++)
		if(a[i])
			vis[a[i]]=0;
	for(int i=1;i<=n;i++)
		if(b[i])
			vis[b[i]]=i;
	if(fl)
	{
		int fl1=1;
		for(int i=b[n]+1;i<=n;i++)
			if(vis[i]>i-b[n]-1)
			{
				fl1=0;
				break;
			}
		if(fl1)
		{
			printf("%d",n-b[n]);
			return 0;
		}
	}
	int maxn=0;
	for(int i=1;i<=n;i++)
		maxn=max(maxn,vis[i]-(i-1));
	printf("%d",maxn+n);
	return 0;
}