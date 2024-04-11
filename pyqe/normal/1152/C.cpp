#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

int main()
{
	long long i,ii,k,l,df,w,z,e=0;
	pair<long long,long long> mne={1e18,-1};
	
	scanf("%lld%lld",&k,&l);
	df=abs(k-l);
	if(df)
	{
		for(i=1;i*i<=df;i++)
		{
			if(df%i==0)
			{
				for(ii=0;ii<2;ii++)
				{
					w=!ii?i:df/i;
					z=(w-k%w)%w;
					mne=min(mne,{(k+z)*(l+z)/w,z});
				}
			}
		}
		e=mne.sc;
	}
	printf("%lld\n",e);
}