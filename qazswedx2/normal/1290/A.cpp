#include<cstdio>
#include<cstring> 
#include<algorithm>
using namespace std;
int t,n,m,k,a[100005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		k=min(k,m-1);
		int nans=0;
		for(int i=0;i<=k;i++)
		{
			int nw=1e9;
			for(int j=0;j<=m-k-1;j++)
			{
			//	printf("i=%d,j=%d,nans=%d\n",i,j,max(a[i+j+1],a[n-i-j]));
				nw=min(nw,max(a[i+j+1],a[n-(m-1-i-j)]));
			}
			nans=max(nans,nw);
		}
		printf("%d\n",nans);
	} 
	return 0;
}