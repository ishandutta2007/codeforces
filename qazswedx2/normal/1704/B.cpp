#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n,x,a[1000005];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&x);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		int mn=a[1],mx=a[1],ans=0;
		for(int i=1;i<=n;i++)
		{
			mn=min(mn,a[i]);
			mx=max(mx,a[i]);
			if(mx-mn>2*x)
			{
				mn=mx=a[i];
				ans++;
			}
		}
		printf("%d\n",ans);
	}
}