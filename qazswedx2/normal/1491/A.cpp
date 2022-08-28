#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,a[1000005];
int main()
{
	scanf("%d%d",&n,&m);
	int sum=0;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),sum+=a[i];
	for(int i=1;i<=m;i++)
	{
		int op,x,y;
		scanf("%d%d",&op,&x);
		if(op==1)
		{
			sum-=a[x];
			a[x]^=1;
			sum+=a[x];
		}
		else
		{
			if(x<=sum) printf("1\n");
			else printf("0\n");
		}
	}
	return 0;
 }