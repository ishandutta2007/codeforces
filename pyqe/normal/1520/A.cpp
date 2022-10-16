#include <bits/stdc++.h>

using namespace std;

long long n;
bitset<26> vtd;

int main()
{
	long long t,rr,i,k,l;
	bool bad;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		vtd.reset();
		bad=0;
		for(i=1;i<=n;i++)
		{
			scanf(" %c",&ch);
			k=ch-'A';
			if(i==1||k!=l)
			{
				bad|=vtd[k];
				vtd[k]=1;
			}
			l=k;
		}
		if(!bad)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}