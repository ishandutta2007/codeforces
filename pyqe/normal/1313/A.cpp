#include <bits/stdc++.h>

using namespace std;

long long n,aa[3],a[3];

int main()
{
	long long t,rr,i,j,mk,mkk,mx,c;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		for(i=0;i<3;i++)
		{
			scanf("%lld",aa+i);
		}
		mx=0;
		for(mk=0;mk<1<<(1<<3);mk++)
		{
			for(i=0;i<3;i++)
			{
				a[i]=aa[i];
			}
			c=0;
			for(i=1;i<1<<3;i++)
			{
				if(mk>>i&1)
				{
					mkk=i;
					for(j=0;j<3;j++)
					{
						if(mkk>>j&1)
						{
							if(!a[j])
							{
								c=-1;
								break;
							}
							a[j]--;
						}
					}
					if(c==-1)
					{
						break;
					}
					c++;
				}
			}
			mx=max(mx,c);
		}
		printf("%lld\n",mx);
	}
}