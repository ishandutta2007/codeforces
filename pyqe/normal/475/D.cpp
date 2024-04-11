#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,nn=0;
pair<long long,long long> sk[100069];
map<long long,long long> sq;

int main()
{
	long long t,rr,i,j,k,l,w,sz;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		nn++;
		sk[nn]={i,0};
		sz=nn;
		nn=0;
		for(j=1;j<=sz;j++)
		{
			l=sk[j].fr;
			w=__gcd(sk[j].sc,k);
			sq[w]+=l-sk[nn].fr;
			nn+=w!=sk[nn].sc;
			sk[nn]={l,w};
		}
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&k);
		printf("%lld\n",sq[k]);
	}
}