#include <bits/stdc++.h>

using namespace std;

long long dv=1e9+7,inf=1e18;
multiset<long long> ms;

int main()
{
	long long t,rr,k,lb=-inf,rb=inf,c=0,z=1;
	multiset<long long>::iterator it;
	string s;
	
	ms.insert(-inf);
	ms.insert(inf);
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		scanf("%lld",&k);
		if(s[1]=='D')
		{
			ms.insert(k);
			c+=k>lb&&k<rb;
		}
		else
		{
			if(k<lb||k>rb)
			{
				printf("0\n");
				return 0;
			}
			z=z*(1ll+(k>lb&&k<rb))%dv;
			it=ms.find(k);
			lb=*prev(it);
			rb=*next(it);
			ms.erase(it);
			c=0;
		}
	}
	printf("%lld\n",z*(c+1)%dv);
}