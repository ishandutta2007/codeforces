#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,a[1000005];
int getans(int x)
{
	return x>0?x:-x; 
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int mx=-1e9,mn=1e9,ans=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=2;i<=n;i++)
		{
			if(a[i-1]==-1&&a[i]!=-1)
				mx=max(mx,a[i]),mn=min(mn,a[i]);
			if(a[i-1]!=-1&&a[i]==-1)
				mx=max(mx,a[i-1]),mn=min(mn,a[i-1]);
			if(a[i-1]!=-1&&a[i]!=-1)
				ans=max(ans,getans(a[i]-a[i-1]));
		}
		if(mx<0)
		{
			printf("%d 0\n",ans);
			continue;
		}
		int x=(mx+mn)/2;
		ans=max(ans,getans(mx-x));
		ans=max(ans,getans(mn-x));
		printf("%d %d\n",ans,x);
	}
	return 0;
}