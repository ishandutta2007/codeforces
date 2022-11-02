#include <cstdio>
#include <algorithm>
using namespace std;
int x[210],y[210],n,a,b,ans;
int main()
{
	scanf("%d%d%d",&n,&a,&b);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&x[i],&y[i]);
	for(int i=n+1;i<=n*2;i++)
	{
		x[i]=y[i-n];
		y[i]=x[i-n];
	}
	for(int i=1;i<=n*2;i++)
		for(int j=1;j<=n*2;j++)
			if(i!=j&&i!=j-n&&i!=j+n)
			{
				if(x[i]+x[j]<=a&&y[i]<=b&&y[j]<=b)
					ans=max(ans,x[i]*y[i]+x[j]*y[j]);
				if(x[i]+x[j]<=b&&y[i]<=a&&y[j]<=a)
					ans=max(ans,x[i]*y[i]+x[j]*y[j]);
			}
	printf("%d\n",ans);
	return 0;
}