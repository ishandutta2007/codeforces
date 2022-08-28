#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int ans=0;
int main()
{
	printf("? ");
	for(int i=1;i<=100;i++)
		printf("%d ",i);
	printf("\n");
	fflush(stdout);
	int x=0;
	scanf("%d",&x);
	ans=(x>>7)<<7;
	printf("? ");
	for(int i=1;i<=100;i++)
		printf("%d ",i<<7);
	printf("\n");
	fflush(stdout);
	scanf("%d",&x);
	ans+=(x&127);
	printf("! %d\n",ans);
	fflush(stdout);
	return 0;
}