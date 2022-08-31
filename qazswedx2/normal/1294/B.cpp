#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct pt
{
	int x,y;
	bool operator<(const pt xx) const
	{
		return x==xx.x?y<xx.y:x<xx.x;
	}
}a[1000005];
int n,t;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d%d",&a[i].x,&a[i].y);
		sort(a+1,a+n+1);
		int fl=0;
		for(int i=1;i<=n;i++)
			if(a[i].y<a[i-1].y)
				 fl=1;
		if(fl)
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=a[i].x-a[i-1].x;j++) printf("R");
			for(int j=1;j<=a[i].y-a[i-1].y;j++) printf("U");
		}
		printf("\n");
	}
	return 0;
}