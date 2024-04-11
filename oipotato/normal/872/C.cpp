#include<cstdio>
using namespace std;
int n,q;
int main()
{
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		scanf("%d",&n);
		if(n<4)
		{
			puts("-1");
		}
		else if(n%4==0||n%4==2)
		{
			printf("%d\n",n/4);
		}
		else if(n%4==1)
		{
			if(n==5)
			{
				puts("-1");
			}
			else
			{
				printf("%d\n",n/4-1);
			}
		}
		else
		{
			if(n==7||n==11)
			{
				puts("-1");
			}
			else
			{
				printf("%d\n",n/4-1);
			}
		}
	}
	return 0;
}