#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,fq[100069];
pair<long long,long long> as[100069];
bitset<100069> vtd;

int main()
{
	long long t,rr,i,k,w,c,y,x;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=0;i<n*m;i++)
		{
			scanf("%lld",&k);
			as[i]={k,i};
		}
		sort(as,as+n*m,greater<pair<long long,long long>>());
		for(i=0;i<m;i++)
		{
			vtd[i]=0;
		}
		c=0;
		for(i=0;i<n;i++)
		{
			fq[i]=0;
		}
		bad=0;
		for(i=0;i<n*m;i++)
		{
			w=as[i].fr;
			k=as[i].sc;
			y=k/m;
			x=k%m;
			c+=!vtd[x];
			vtd[x]=1;
			fq[y]++;
			bad|=fq[y]>=2;
			if(c==m&&bad)
			{
				break;
			}
		}
		printf("%lld\n",w);
	}
}