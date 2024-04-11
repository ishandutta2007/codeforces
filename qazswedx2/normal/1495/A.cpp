#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int t,n,a[1000005],b[1000005],at,bt;
inline int F(int x)
{
	return x>0?x:-x;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		at=bt=0;
		for(int i=1;i<=2*n;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			if(x==0) a[++at]=F(y);
			else b[++bt]=F(x);
		}
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		double ans=0;
		for(int i=1;i<=n;i++)
			ans+=sqrt(1.0*a[i]*a[i]+1.0*b[i]*b[i]);
		printf("%.15f\n",ans);
	}
	return 0;
}