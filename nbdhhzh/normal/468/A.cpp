#include<cstdio>
using namespace std;
int n;
int main()
{
	scanf("%d",&n);
	if (n<4)printf("NO\n");else
	if (n&1)
	{
		printf("YES\n5 * 4 = 20\n20 + 3 = 23\n23 + 2 = 25\n25 - 1 = 24\n");
		for (int i=7;i<=n;i+=2)printf("%d - %d = 1\n",i,i-1);
		for (int i=7;i<=n;i+=2)printf("24 * 1 = 24\n");
	}else
	{
		printf("YES\n3 * 4 = 12\n12 * 2 = 24\n24 * 1 = 24\n");
		for (int i=6;i<=n;i+=2)printf("%d - %d = 1\n",i,i-1);
		for (int i=6;i<=n;i+=2)printf("24 * 1 = 24\n");
	}
}