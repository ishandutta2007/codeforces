#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n,a[100005],b[100005],nw=0,ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i],&b[i]);
	for(int i=1;i<=n;i++)
	{
		if(min(a[i],b[i])-max(max(a[i-1],b[i-1]),nw+1)>=0)
			ans=ans+min(a[i],b[i])-max(max(a[i-1],b[i-1]),nw+1)+1;
		nw=min(a[i],b[i]);
		//printf("%d,%d,%d,%d\n",ans,nw,a[i],b[i]);
	}
	printf("%d",ans+1);
	return 0;
}