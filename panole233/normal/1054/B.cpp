#include<cstdio>
#include<cstring>

int n,a[100001],ma;

int main()
{
	scanf("%d",&n); ma=-1;
	for (int i=1; i<=n; i++)
	{
		scanf("%d",&a[i]);
		if (a[i]>ma+1) {printf("%d\n",i); return 0;}
		if (a[i]>ma) ma=a[i];
	}
	printf("-1\n");
	return 0;
}