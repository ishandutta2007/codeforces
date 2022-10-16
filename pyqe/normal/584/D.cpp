#include <bits/stdc++.h>

using namespace std;

long long n,z[3];
bitset<369> vtd;

int main()
{
	long long i,j,r,c=0;
	bool bad=0;
	
	vtd[1]=1;
	for(i=2;i<=300;i++)
	{
		if(!vtd[i])
		{
			for(j=i*i;j<=300;j+=i)
			{
				vtd[j]=1;
			}
		}
	}
	scanf("%lld",&n);
	for(i=n;1;i--)
	{
		bad=1;
		for(j=2;j*j<=i;j++)
		{
			if(i%j==0)
			{
				bad=0;
				break;
			}
		}
		if(!i||bad)
		{
			z[0]=i;
			break;
		}
	}
	for(i=0;i<=300;i++)
	{
		if(!vtd[i])
		{
			for(j=i;j<=300;j++)
			{
				if(!vtd[j])
				{
					if(z[0]+i+j==n)
					{
						z[1]=i;
						z[2]=j;
						sort(z,z+3);
						for(r=0;r<3;r++)
						{
							if(z[r])
							{
								c++;
							}
						}
						printf("%lld\n",c);
						for(r=0;r<3;r++)
						{
							if(z[r])
							{
								printf("%lld%c",z[r]," \n"[r==2]);
							}
						}
						return 0;
					}
				}
			}
		}
	}
}