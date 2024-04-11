#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(n%2==0)
		{
			for(int i=1;i<=n/2;i++)
				printf("1");
			printf("\n");
		}
		else
		{
			printf("7");
			for(int i=1;i<=n/2-1;i++)
				printf("1");
			printf("\n");
		}
	}
	return 0;
}