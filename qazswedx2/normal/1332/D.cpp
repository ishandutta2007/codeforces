#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int lim,n;
int main()
{
	scanf("%d",&n);
	lim=1;
	while(lim<=n) lim<<=1;
	printf("2 3\n");
	printf("%d %d 0\n",lim+n,lim);
	printf("%d %d %d",n,lim+n,n);
	return 0;
}