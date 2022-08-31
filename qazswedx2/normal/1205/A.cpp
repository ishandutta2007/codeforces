#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int main()
{
	scanf("%d",&n);
	if(n%2==0)
	{
		printf("NO");
		return 0;
	}
	printf("YES\n");
	for(int i=1;i<=n;i++)
		printf("%d ",i*2-(i%2));
	for(int i=1;i<=n;i++)
		printf("%d ",i*2-(i%2==0));
	return 0;
}