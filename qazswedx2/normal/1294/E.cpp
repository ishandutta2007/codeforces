#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define id(x,y) ((x-1)*m+y)
int n,m,a[1000005],vis[1000005];
int submod(int x,int mod)
{
	return (x%mod+mod)%mod;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[id(i,j)]);
	int tans=0;
	for(int i=1;i<=m;i++)
	{
		int nans=1e9;
		for(int j=0;j<n;j++)
			vis[j]=0;
		//printf("i=%d\n",i);
		for(int j=1;j<=n;j++)
		{
			int nw=a[id(j,i)]-i;
			if(nw%m) continue;
			nw=nw/m+1;
			if(nw<1||nw>n) continue;
			vis[submod(j-nw,n)]++;
			//printf("nw=%d,submod(j-nw,m)=%d,j=%d\n",nw,submod(j-nw,n),j);
		}
		for(int j=0;j<n;j++)
			nans=min(nans,j+n-vis[j]);
		tans+=nans;
	}
	printf("%d",tans);
	return 0;
}