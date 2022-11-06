#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;
int t,a;
int b[233]={0,-1,-1,-1,1,-1,1,-1,2,1,2,-1,3};
int main()
{
	scanf("%d",&a);
	while(a--)
	{
		scanf("%d",&t);
		if(t<=12)
		{
			printf("%d\n",b[t]);
		}
		else if(t%4==0)
		{
			printf("%d\n",t/4);
		}
		else if(t%4==1)
		{
			printf("%d\n",(t-9)/4+1);
		}
		else if(t%4==2)
		{
			printf("%d\n",(t-6)/4+1);
		}
		else printf("%d\n",(t-15)/4+2);
	}
	return 0;
}