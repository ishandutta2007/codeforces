#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,a[100069],inf=1e18;

int main()
{
	long long t,rr,i,k,c,mn,e,z;
	pair<long long,long long> mne;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		mne={inf,-1};
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			for(c=0,k=a[i];k%d==0;k/=d,c++);
			mne=min(mne,{c,i});
		}
		mn=mne.fr;
		e=mne.sc;
		z=0;
		for(i=1;i<=n;i++)
		{
			z+=a[i]*(mn+1+(i<e));
		}
		printf("%lld\n",z);
	}
}