#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,a[1000005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		for(int i=n;i>0;i--)
			printf("%d ",a[i]);
		printf("\n");
	}
	return 0;
}