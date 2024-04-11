#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cmath>
using namespace std;
int a,b,c,d;
int main()
{
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if(c==0&&d==0)
	{
		if(abs(a-b)>=2)
		{
			printf("NO");
			return 0;
		}
	printf("YES\n");
		if(a>b) printf("0 ");
		for(int i=1;i<=min(a,b);i++)
			printf("1 0 ");
		if(a<b) printf("1 ");
		return 0;
	}
	if(a==0&&b==0)
	{
		if(abs(c-d)>=2)
		{
			printf("NO");
			return 0;
		}
	printf("YES\n");
		if(c>d) printf("2 ");
		for(int i=1;i<=min(c,d);i++)
			printf("3 2 ");
		if(c<d) printf("3 ");
		return 0;
	}
	if(abs(a+c-b-d)>=2||a>b||c<d)
	{
		printf("NO");
		return 0;
	}
	printf("YES\n");
	b-=a,c-=d;
	if(b>c) printf("1 ");
	for(int i=1;i<=a;i++)
		printf("0 1 ");
	for(int i=1;i<=min(b,c);i++)
		printf("2 1 ");
	for(int i=1;i<=d;i++)
		printf("2 3 ");
	if(c>b) printf("2 ");
	return 0;
}