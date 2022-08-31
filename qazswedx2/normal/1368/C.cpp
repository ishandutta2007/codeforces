#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int main()
{
	scanf("%d",&n);
	printf("%d\n",3*n+4);
	for(int i=1;i<=n+1;i++)
	{
		printf("%d %d\n",i,i);
		printf("%d %d\n",i,1+i);
		printf("%d %d\n",1+i,i);
	}
	printf("%d %d\n",n+2,n+2);
	return 0;
}