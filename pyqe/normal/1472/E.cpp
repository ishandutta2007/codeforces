#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,sq[200069],inf=1e18;
pair<pair<long long,long long>,long long> a[200069];

int main()
{
	long long t,rr,i,k,l,pz,mn,e;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld%lld",&k,&l);
			if(k>l)
			{
				swap(k,l);
			}
			a[i]={{k,-l},i};
		}
		sort(a+1,a+n+1);
		mn=inf;
		for(i=1;i<=n;i++)
		{
			k=a[i].fr.fr;
			l=-a[i].fr.sc;
			pz=a[i].sc;
			if(l>mn)
			{
				sq[pz]=e;
			}
			else
			{
				sq[pz]=-1;
				mn=l;
				e=pz;
			}
		}
		for(i=1;i<=n;i++)
		{
			printf("%lld%c",sq[i]," \n"[i==n]);
		}
	}
}