#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,nn=0,inf=1e18;
pair<long long,long long> sk[69];

int main()
{
	long long i,j,k,w,p,mn=inf,c=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		nn++;
		sk[nn]={i,0};
		p=0;
		for(j=1;j<=nn;j++)
		{
			w=__gcd(k,sk[j].sc);
			p+=!p||w!=sk[p].sc;
			sk[p]={sk[j].fr,w};
		}
		nn=p;
		if(sk[1].sc==1)
		{
			mn=min(mn,i-sk[1].fr);
		}
		c+=k==1;
	}
	if(mn==inf)
	{
		printf("-1\n");
		return 0;
	}
	printf("%lld\n",mn+n-max(c,1ll));
}