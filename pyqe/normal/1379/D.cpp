#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,d2,inf=1e18;
pair<long long,long long> a[200069];

int main()
{
	long long i,k,p,e;
	pair<long long,long long> mne={inf,-1};
	
	scanf("%lld%lld%lld%lld",&n,&d,&d,&d2);
	d/=2;
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&k,&k);
		a[i]={k%d,i};
	}
	sort(a+1,a+n+1);
	for(i=n+1;i<=n*2;i++)
	{
		a[i]=a[i-n];
		a[i].fr+=d;
	}
	for(i=n+1;i<=n*2;i++)
	{
		p=upper_bound(a+1,a+n*2,mp(a[i].fr-d2,inf))-a;
		mne=min(mne,{i-p,i});
	}
	e=mne.sc;
	printf("%lld %lld\n",mne.fr,a[e].fr-d);
	p=upper_bound(a+1,a+n*2,mp(a[e].fr-d2,inf))-a;
	for(i=p;i<e;i++)
	{
		printf("%lld%c",a[i].sc," \n"[i==e-1]);
	}
}