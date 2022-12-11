#include<cstdio>
using namespace std;
int n,p,i,x,a[110];
int main()
{
	scanf("%d",&n);
	scanf("%d",&p);for (i=1;i<=p;i++)scanf("%d",&x),a[x]=1;
	scanf("%d",&p);for (i=1;i<=p;i++)scanf("%d",&x),a[x]=1;
	for (i=1;i<=n;i++)if (!a[i])break;
	if (i>n)printf("I become the guy.\n");else printf("Oh, my keyboard!\n");
}