#include<cstdio>
#include<cstring>
#include<algorithm>
int t,n,a,b;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		int fl=0;
		scanf("%d%d%d",&n,&a,&b);
		for(int i=1;i<=a;i++)
		{
			int x;
			scanf("%d",&x);
			if(x==n) fl=1;
		}
		for(int i=1;i<=b;i++)
		{
			int x;
			scanf("%d",&x);
		}
		if(fl) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}