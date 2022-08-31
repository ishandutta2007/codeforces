#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,sum1,sum2,ans[1000005],p[1000005],prime[1000005],pt=0;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		if(x==1) sum1++;
		else sum2++;
	}
	if(!sum1) 
	{
		for(int i=1;i<=n;i++)
			printf("2 ");
		return 0;
	}
	if(!sum2)
	{
		for(int i=1;i<=n;i++)
			printf("1 ");
		return 0;
	}
	sum1--;
	sum2--;
	printf("2 1 ");
	for(int i=1;i<=sum2;i++)
		printf("2 ");
	for(int i=1;i<=sum1;i++)
		printf("1 ");
	return 0;
}