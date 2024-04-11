#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,fq[100069],fqq[100069],zs=0;
multiset<pair<long long,long long>> ms;
multiset<pair<long long,long long>>::iterator it[2];

int main()
{
	long long i,k,mx=-1e18;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		if(fq[k])
		{
			ms.erase({fq[k],fqq[fq[k]]});
			zs--;
			fqq[fq[k]]--;
			if(fqq[fq[k]])
			{
				ms.insert({fq[k],fqq[fq[k]]});
				zs++;
			}
		}
		fq[k]++;
		if(fqq[fq[k]])
		{
			ms.erase({fq[k],fqq[fq[k]]});
			zs--;
		}
		fqq[fq[k]]++;
		ms.insert({fq[k],fqq[fq[k]]});
		zs++;
		it[0]=ms.begin();
		it[1]=ms.end();
		it[1]--;
		if((zs==1&&((*it[0]).fr==1||(*it[0]).sc==1))||(zs==2&&(*it[0]==mp(1ll,1ll)||*it[1]==mp((*it[0]).fr+1,1ll))))
		{
			mx=i;
		}
	}
	printf("%lld\n",mx);
}