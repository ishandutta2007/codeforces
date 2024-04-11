#include<cstdio>
#include<algorithm>
using namespace std;
int k1,k2,k3;
bool check(int a,int b,int c,int k1,int k2,int k3)
{
	for(int i=1;i<=1000000;i++)
	{
		if((i-1)%k1+1!=a&&(i-1)%k2+1!=b&&(i-1)%k3+1!=c)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	scanf("%d%d%d",&k1,&k2,&k3);
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=3;j++)
		{
			for(int k=1;k<=3;k++)
			{
				if(check(i,j,k,k1,k2,k3))
				{
					puts("YES");
					return 0;
				}
			}
		}
	}
	puts("NO");
	return 0;
}