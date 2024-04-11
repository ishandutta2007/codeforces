#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n;

const long long inf=1e18;
int main()
{
	long long t,rr,i,k,l,w,bg;
	pair<long long,long long> mn,mx;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		mn.fr=inf;
		mx.fr=-inf;
		for(i=0;i<n;i++)
		{
			scanf("%lld%lld%lld",&k,&l,&w);
			if(k<mn.fr||l>mx.fr)
			{
				bg=inf;
			}
			mn=min(mn,{k,w});
			mx=max(mx,{l,-w});
			if(k==mn.fr&&l==mx.fr)
			{
				bg=min(bg,w);
			}
			printf("%lld\n",min(mn.sc-mx.sc,bg));
		}
	}
}