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
		if(n==1)
		{
			printf("-1\n");
			continue;
		}
		for(int i=1;i<n;i++)
			printf("5");
		printf("4\n");
	}
	return 0;
}