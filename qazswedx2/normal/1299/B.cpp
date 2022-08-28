#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int a[100005],b[100005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i],&b[i]);
	if(n%2)
	{
		printf("NO\n");
		return 0;
	}
	int x=a[1]+a[n/2+1],y=b[1]+b[n/2+1];
	for(int i=1;i<=n/2;i++)
	{
		int xx=a[i]+a[n/2+i],yy=b[i]+b[n/2+i];
		if(x!=xx||y!=yy)
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}