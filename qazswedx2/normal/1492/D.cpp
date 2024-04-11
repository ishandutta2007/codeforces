#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a,b,k,tans[2][1000005];
int main()
{
	scanf("%d%d%d",&a,&b,&k);
	if(b==1)
	{
		if(!k)
		{
			printf("Yes\n");
			printf("1");
			for(int i=1;i<=a;i++)
				printf("0");
			printf("\n");
			printf("1");
			for(int i=1;i<=a;i++)
				printf("0");
			printf("\n");
		}
		else printf("No\n");
		return 0;
	}
	if(a==0)
	{
		if(!k)
		{
			printf("Yes\n");
			for(int i=1;i<=b;i++)
				printf("1");
			printf("\n");
			for(int i=1;i<=b;i++)
				printf("1");
			printf("\n");
		}
		else printf("No\n");
		return 0;
	}
	if(k>=a+b-1)
	{
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	tans[0][1]=tans[1][1]=1;
	tans[0][2]=1;
	tans[1][2+k]=1;
	int nww=b-2;
	for(int i=3;i<=a+b;i++)
	{
		if(i==2+k) continue;
		if(!nww) break;
		nww--;
		tans[0][i]=tans[1][i]=1;
	}
	for(int i=1;i<=a+b;i++)
		printf("%d",tans[0][i]);
	printf("\n");
	for(int i=1;i<=a+b;i++)
		printf("%d",tans[1][i]);
	printf("\n");
	return 0;
}