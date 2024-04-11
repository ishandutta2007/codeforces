#include <bits/stdc++.h>

using namespace std;

long long a[2][4],pm[4],inf=1e18;

int main()
{
	long long t,rr,i,ii,jj,k,l,sm,lb[2],rb[2],lbb[2],rbb[2],z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		for(i=0;i<4;i++)
		{
			for(ii=0;ii<2;ii++)
			{
				scanf("%lld",&a[ii][i]);
			}
			pm[i]=i;
		}
		z=inf;
		for(;1;)
		{
			sm=0;
			for(ii=0;ii<2;ii++)
			{
				for(jj=0;jj<2;jj++)
				{
					k=pm[jj<<!ii];
					l=pm[1ll<<ii|jj<<!ii];
					sm+=abs(a[ii][k]-a[ii][l]);
					lb[jj]=min(a[ii][k],a[ii][l]);
					rb[jj]=max(a[ii][k],a[ii][l]);
				}
				lbb[ii]=max(lb[0],lb[1])-min(rb[0],rb[1]);
				rbb[ii]=max(rb[0],rb[1])-min(lb[0],lb[1]);
			}
			z=min(z,sm+max(max(lbb[0],lbb[1])-min(rbb[0],rbb[1]),0ll)*2);
			if(!next_permutation(pm,pm+4))
			{
				break;
			}
		}
		printf("%lld\n",z);
	}
}