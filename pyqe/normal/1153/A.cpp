#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,inf=1e18;

int main()
{
	long long i,k,l,w;
	pair<long long,long long> mne={inf,-1};
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&k,&l);
		if(d<k)
		{
			w=k-d;
		}
		else
		{
			w=(d-k+l-1)/l*l+k-d;
		}
		mne=min(mne,{w,i});
	}
	printf("%lld\n",mne.sc);
}