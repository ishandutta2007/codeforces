#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,u,v,a[1000005];
int F(int x)
{
	return x>0?x:-x;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&u,&v);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		int ans=v+min(v,u);
		for(int i=2;i<=n;i++)
			if(F(a[i]-a[i-1])>=2) ans=0;
			else if(a[i]!=a[i-1]) ans=min(ans,min(v,u));
		printf("%d\n",ans);
	}
	return 0;
}