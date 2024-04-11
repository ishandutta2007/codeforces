#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long l[2],r[2],i,t,j;
	
	scanf("%lld",&t);
	for(j=0;j<t;j++)
	{
		for(i=0;i<2;i++)
		{
			scanf("%lld%lld",l+i,r+i);
		}
		if(l[0]==l[1])
		{
			if(l[1]==r[1])
			{
				printf("%lld %lld\n",l[0]+1,l[0]);
			}
			else
			{
				printf("%lld %lld\n",l[0],l[0]+1);
			}
		}
		else
		{
			printf("%lld %lld\n",l[0],l[1]);
		}
	}
	
}