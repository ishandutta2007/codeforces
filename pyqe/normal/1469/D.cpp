#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,inf=1e18;

int main()
{
	long long t,rr,i,k,l,c,mn,e,e2;
	pair<long long,long long> mne;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		mne={inf,-1};
		for(i=2;i<n;i++)
		{
			for(c=0,k=n,l=i;l-1;c++)
			{
				k=(k-1)/l+1;
				if(k<l)
				{
					swap(k,l);
				}
			}
			if(k==2)
			{
				mne=min(mne,{c,i});
			}
		}
		mn=mne.fr;
		e=mne.sc;
		printf("%lld\n",n-3+mn);
		for(i=2;i<n;i++)
		{
			if(i!=e)
			{
				printf("%lld %lld\n",i,n);
			}
		}
		e2=n;
		for(k=n,l=e;l-1;)
		{
			printf("%lld %lld\n",e2,e);
			k=(k-1)/l+1;
			if(k<l)
			{
				swap(k,l);
				swap(e2,e);
			}
		}
	}
}