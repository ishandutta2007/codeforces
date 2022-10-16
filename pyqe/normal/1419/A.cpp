#include <bits/stdc++.h>

using namespace std;

long long n;
bitset<2> vtd;

int main()
{
	long long t,rr,i,k;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		vtd.reset();
		for(i=1;i<=n;i++)
		{
			scanf(" %c",&ch);
			k=ch-'0';
			vtd[i%2]=vtd[i%2]|k%2==i%2;
		}
		printf("%lld\n",2ll-(n%2^!vtd[n%2]));
	}
}