#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,a[1000005],r,nr,ans,nans,vis[1000005];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	r=nr=1;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		nr=max(nr,i+1);
		r=max(r,i+1);
		if(!vis[i])
		{
			while(r<=n&&(a[r]-a[i]<m||vis[r])) r++;
			if(r<=n) vis[i]=r,vis[r]=i,nans++;
		}
		else
		{
			int l=vis[i];
			while(nr<=n&&vis[nr]) nr++;
			vis[l]=nr,vis[nr]=l;
			while(r<=n&&(a[r]-a[i]<m||vis[r])) r++;
			if(r<=n) vis[i]=r,vis[r]=i,nans++;
		}
		ans=max(ans,nans);
	}
	printf("%d",ans);
	return 0;
}