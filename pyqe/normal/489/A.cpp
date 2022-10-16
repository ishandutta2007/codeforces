#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[3069],pst[3069],zs=0;
pair<long long,long long> as[3069];
map<pair<long long,long long>,long long> yk;
vector<pair<long long,long long>> sq;

int main()
{
	long long i,k;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",a+i);
		as[i]={a[i],i};
	}
	sort(as,as+n);
	for(i=0;i<n;i++)
	{
		yk[as[i]]=i;
	}
	for(i=0;i<n;i++)
	{
		a[i]=yk[{a[i],i}];
		pst[a[i]]=i;
	}
	for(i=0;i<n;i++)
	{
		sq.push_back({i,pst[i]});
		zs++;
		k=a[i];
		swap(a[i],a[pst[i]]);
		swap(pst[i],pst[k]);
	}
	printf("%lld\n",zs);
	for(i=0;i<zs;i++)
	{
		printf("%lld %lld\n",sq[i].fr,sq[i].sc);
	}
}