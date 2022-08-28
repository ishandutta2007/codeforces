#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,x;
		scanf("%d%d",&n,&x);
		if(n<=2)
		{
			printf("1\n");
			continue;
		}
		n-=3;
		printf("%d\n",n/x+2);
	}
	return 0;
}