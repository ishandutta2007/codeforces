#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n,k;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		if(k>(n+1)/2)
		{
			printf("-1\n");
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				if(i==j&&i%2&&k)
				{
					k--;
					printf("R");
				}
				else printf(".");
			printf("\n");
		}
	}
}