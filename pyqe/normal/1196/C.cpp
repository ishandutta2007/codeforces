#include <bits/stdc++.h>

using namespace std;

long long n,mx[2],mn[2];

int main()
{
	long long t,rr,i,ii,yx[2],k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(ii=0;ii<2;ii++)
		{
			mn[ii]=1e5;
			mx[ii]=-1e5;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lld%lld",yx,yx+1);
			for(ii=0;ii<4;ii++)
			{
				scanf("%lld",&k);
				if(!k)
				{
					if(ii&&ii<3)
					{
						mn[ii%2]=min(mn[ii%2],yx[ii%2]);
					}
					else
					{
						mx[ii%2]=max(mx[ii%2],yx[ii%2]);
					}
				}
			}
		}
		for(ii=0;ii<2;ii++)
		{
			if(mn[ii]<mx[ii])
			{
				ii=-1;
				break;
			}
		}
		if(ii==-1)
		{
			printf("0\n");
		}
		else
		{
			printf("1 %lld %lld\n",mn[0],mn[1]);
		}
	}
}