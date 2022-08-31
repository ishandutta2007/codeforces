#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[1000005],f[1000005],g[1000005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		f[i]=f[i-1]|a[i];
	for(int i=n;i>0;i--)
		g[i]=g[i+1]|a[i];
	int ans=-1,id=0;
	for(int i=1;i<=n;i++)
	{
		int nw=(a[i]|f[i-1])-f[i-1];
		nw=(nw|g[i+1])-g[i+1];
		//printf("i=%d,nw=%d\n",i,nw);
		if(ans<nw)
		{
			ans=nw;
			id=i;
		}
	}
	printf("%d ",a[id]);
	for(int i=1;i<=n;i++)
		if(i!=id)
			printf("%d ",a[i]);
	return 0;
}