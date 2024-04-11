#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n,a,b,p[100005];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&a,&b);
		p[1]=a,p[n]=b;
		int t=1;
		for(int i=n;i>0;i--)
		{
			if(i==a||i==b) continue;
			p[++t]=i;
		}
		int mn=1e9,mx=0;
		for(int i=1;i<=n/2;i++)
			mn=min(mn,p[i]);
		for(int i=n/2+1;i<=n;i++)
			mx=max(mx,p[i]);
		if(mn!=a||mx!=b)
		{
			printf("-1\n");
		}
		else
		{
			for(int i=1;i<=n;i++)
				printf("%d ",p[i]);
			printf("\n");
		}
	}
	return 0;
}