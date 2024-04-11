#include <bits/stdc++.h>

using namespace std;

long long n,d,d2;

int main()
{
	long long t,rr,i,k,l;
	bool bad,bad2;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&n,&d,&d2);
		bad=0;
		bad2=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			if(i-1)
			{
				bad|=k!=l;
				bad2|=abs(k-l)>1;
			}
			l=k;
		}
		printf("%lld\n",d2*!bad+min(d,d2)*!bad2);
	}
}