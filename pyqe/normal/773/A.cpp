#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long t,rr,i,k,l,nm,dn,df,df2,lh,rh,md,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld%lld",&k,&l,&nm,&dn);
		if(nm==dn)
		{
			z=-1+(k==l);
		}
		else if(!nm)
		{
			z=-1+!k;
		}
		else
		{
			for(lh=1,rh=1e9;lh<=rh;)
			{
				md=(lh+rh)/2;
				df=nm*md-k;
				df2=dn*md-l;
				if(df>=0&&df2>=df)
				{
					z=df2;
					rh=md-1;
				}
				else
				{
					lh=md+1;
				}
			}
		}
		printf("%lld\n",z);
	}
}