#include<cstdio>
using namespace std;
bool a[10],b[10];
int n,m,x;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		a[x]=1;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&x);
		b[x]=1;
	}
	for(int i=1;i<=9;i++)
	{
		if(a[i]&&b[i])
		{
			printf("%d\n",i);
			return 0;
		}
	}
	for(int i=10;i<=99;i++)
	{
		if((a[i/10]||a[i%10])&&(b[i/10]||b[i%10]))
		{
			printf("%d\n",i);
			return 0;
		}
	}
	return 0;
}