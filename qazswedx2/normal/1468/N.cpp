#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,a[5],c[3];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&c[0],&c[1],&c[2]);
		scanf("%d%d%d%d%d",&a[0],&a[1],&a[2],&a[3],&a[4]);
		c[0]-=a[0],c[1]-=a[1],c[2]-=a[2];
		if(c[0]<0||c[1]<0||c[2]<0)
		{
			printf("No\n");
			continue;
		}
		a[3]-=min(c[0],a[3]);
		a[4]-=min(c[1],a[4]);
		c[2]-=(a[3]+a[4]);
		if(c[2]>=0) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}