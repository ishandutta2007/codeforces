#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[4]={3,0,2,1};

int main()
{
	long long i,k,mn,e;
	pair<long long,long long> mne={1e18,-1};
	
	scanf("%lld",&n);
	for(i=0;i<=2;i++)
	{
		k=(n+i)%4;
		mne=min(mne,{a[k],i});
	}
	mn=mne.fr;
	e=mne.sc;
	printf("%lld %c\n",e,(char)mn+'A');
}