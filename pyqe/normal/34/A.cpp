#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long inf=1e18;
long long n,a[100069];

int main()
{
	long long i,e;
	pair<long long,long long> mne={inf,-1};
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=1;i<=n;i++)
	{
		mne=min(mne,{abs(a[i]-a[i%n+1]),i});
	}
	e=mne.sc;
	printf("%lld %lld\n",e,e%n+1);
}