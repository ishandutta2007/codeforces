#include <bits/stdc++.h>
 
using namespace std;
 
#define mp make_pair
#define fr first
#define sc second
 
long long n,d,dsu[200069],cc[200069],inf=1e18;
pair<long long,long long> as[200069];
bitset<200069> vtd;
 
long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}
 
int main()
{
	long long i,ii,k,w,c=0;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		as[i]={k,i};
	}
	sort(as+1,as+n+1);
	for(i=1;i<=n;i++)
	{
		k=as[i].sc;
		w=as[i].fr;
		vtd[k]=1;
		dsu[k]=k;
		cc[k]=1;
		for(ii=-1;ii<=1;ii+=2)
		{
			if(vtd[k+ii])
			{
				c-=(cc[fd(k+ii)]+1)/2;
				cc[fd(k)]+=cc[fd(k+ii)];
				dsu[fd(k+ii)]=fd(k);
			}
		}
		c+=(cc[fd(k)]+1)/2;
		if((c-cc[fd(1)]%2-(d%2&&cc[fd(n)]%2)+(cc[fd(1)]%2&&fd(1)==fd(n))>=d/2)||(c-(d%2==0&&cc[fd(n)]%2)>=(d+1)/2))
		{
			break;
		}
	}
	printf("%lld\n",w);
}