#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,a[100005],t;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		if(a[n]-a[1]>2*m)
		{
			printf("-1\n");
			continue;
		}
		printf("%d\n",a[1]+m);
	}
	return 0;
}