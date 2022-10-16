#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,wg[200069],lz[200069],sq[200069];
pair<pair<long long,pair<long long,long long>>,long long> as[200069];

int main()
{
	long long t,rr,i,k,l,w,mn,mx,pz,z=0;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&k,&l,&w);
			mn=max(w-l,0ll);
			mx=min(k,w);
			wg[i]=w;
			lz[i]=mn;
			as[i]={{k+l-w,{k-mn,k-mx}},i};
		}
		sort(as+1,as+n+1);
		z=0;
		for(i=1;i<=n;i++)
		{
			w=as[i].fr.fr;
			k=as[i].fr.sc.fr;
			l=as[i].fr.sc.sc;
			pz=as[i].sc;
			if(i==1||w!=as[i-1].fr.fr||l>mx)
			{
				z++;
				mx=k;
			}
			sq[pz]=lz[pz]+k-mx;
		}
		printf("%lld\n",z);
		for(i=1;i<=n;i++)
		{
			printf("%lld %lld\n",sq[i],wg[i]-sq[i]);
		}
	}
}