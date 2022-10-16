#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long x,y,i=0,j=0,r,c,it=0,z=0,ky[4]={0,1,0,-1},kx[4]={1,0,-1,0};
	
	scanf("%lld%lld",&x,&y);
	if(x==0&&y==0)
	{
		printf("0\n");
		return 0;
	}
	for(c=0;1;)
	{
		for(it=0;it<4;it++)
		{
			if(it%2==0)
			{
				c++;
			}
			for(r=0;r<c;r++)
			{
				i+=ky[it];
				j+=kx[it];
				if(i==y&&j==x)
				{
					printf("%lld\n",z);
					return 0;
				}
			}
			z++;
		}
	}
}