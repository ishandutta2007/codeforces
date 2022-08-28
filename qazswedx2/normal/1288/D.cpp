#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m,a[500005][10],b[500005],vis[100005],idx,idy;
bool check(int x)
{
	for(int i=0;i<(1<<m);i++)
		vis[i]=0;
	for(int i=1;i<=n;i++)
	{
		int sum=0;
		for(int j=1;j<=m;j++)
		{
			int nw=a[i][j]>=x;
			if(nw) sum|=(1<<(j-1));
		}
		vis[sum]=i;
		//if(x==2) printf("i=%d,sum=%d\n",i,sum);
	}
	for(int i=0;i<(1<<m);i++)
		for(int j=0;j<(1<<m);j++)
		{
			//if(i==21&&j==11&&x==2) printf("%d,%d,%d\n",vis[i],vis[j],(i|j)==(1<<m)-1);
			if(vis[i]&&vis[j]&&(i|j)==(1<<m)-1)
			{
				//printf("i=%d,j=%d,x=%d\n",i,j,x);
				idx=vis[i],idy=vis[j];
				return 1;
			}
		}
	return 0;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]); 
	int l=0,r=1e9;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	printf("%d %d\n",idx,idy);
	return 0;
}