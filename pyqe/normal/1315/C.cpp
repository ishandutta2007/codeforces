#include <bits/stdc++.h>

using namespace std;

long long n,sq[100069];
multiset<long long> ms;
multiset<long long>::iterator it;

int main()
{
	long long t,rr,i,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n*2;i++)
		{
			ms.insert(i);
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			sq[i*2-1]=k;
			ms.erase(ms.find(k));
		}
		for(i=1;i<=n*2;i+=2)
		{
			it=ms.upper_bound(sq[i]);
			if(it==ms.end())
			{
				i=-1;
				break;
			}
			sq[i+1]=(*it);
			ms.erase(it);
		}
		if(i!=-1)
		{
			for(i=1;i<=n*2;i++)
			{
				printf("%lld%c",sq[i]," \n"[i==n*2]);
			}
		}
		else
		{
			printf("-1\n");
		}
		ms.clear();
	}
}