#include <bits/stdc++.h>

using namespace std;

long long n,pst[100069],fq[100069],dsu[100069];
multiset<long long> ms;

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
	long long t,rr,i,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			pst[k]=i;
			fq[i]=1;
			ms.insert(-1);
		}
		for(i=1;i<=n+1;i++)
		{
			dsu[i]=i;
		}
		for(i=1;i<=n;i++)
		{
			k=pst[i];
			if(fq[k]!=-*ms.begin())
			{
				i=-1;
				break;
			}
			ms.erase(ms.begin());
			if(fd(k+1)<=n)
			{
				ms.erase(ms.find(-fq[fd(k+1)]));
				fq[fd(k+1)]+=fq[k];
				ms.insert(-fq[fd(k+1)]);
			}
			dsu[fd(k)]=fd(k+1);
		}
		ms.clear();
		if(i!=-1)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
}