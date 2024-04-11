#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,k;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		if((n-k)%2==0)
		{
			printf("%d %d ",(n-k)/2+1,(n-k)/2+1);
			for(int i=3;i<=k;i++)
				printf("%d ",1);
			printf("\n");
			continue;
		}
		for(int i=1;i<=k-3;i++)
			printf("%d ",1);
		n-=(k-3);
		if((n/2)%2)
		{
			printf("%d %d %d\n",n/2-1,n/2-1,2);
		}
		else
		{
			printf("%d %d %d\n",n/2,n/4,n/4);
		}
	}
	return 0;
}