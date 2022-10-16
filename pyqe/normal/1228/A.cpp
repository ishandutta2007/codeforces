#include <bits/stdc++.h>

using namespace std;

bitset<10> vtd;

int main()
{
	long long lh,rh,i,kk;
	bool bad;
	
	scanf("%lld%lld",&lh,&rh);
	for(i=lh;i<=rh;i++)
	{
		bad=0;
		vtd.reset();
		for(kk=i;kk>0;kk/=10)
		{
			if(vtd[kk%10])
			{
				bad=1;
				break;
			}
			vtd[kk%10]=1;
		}
		if(!bad)
		{
			printf("%lld\n",i);
			return 0;
		}
	}
	printf("-1\n");
}