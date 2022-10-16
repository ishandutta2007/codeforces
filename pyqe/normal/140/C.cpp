#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,nn=0,a[100069],tri[3],sq[100069][3],zs=0;
map<long long,long long> fq;
priority_queue<pair<long long,long long>> pq;

int main()
{
	long long i,j,k;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		if(!fq[k])
		{
			nn++;
			a[nn]=k;
		}
		fq[k]++;
	}
	for(i=1;i<=nn;i++)
	{
		pq.push({fq[a[i]],a[i]});
	}
	for(;1;)
	{
		for(i=0;i<3;i++)
		{
			if(pq.empty())
			{
				i=-1;
				break;
			}
			tri[i]=pq.top().sc;
			pq.pop();
		}
		if(i==-1)
		{
			break;
		}
		zs++;
		for(i=0;i<3;i++)
		{
			sq[zs][i]=tri[i];
			fq[tri[i]]--;
			if(fq[tri[i]])
			{
				pq.push({fq[tri[i]],tri[i]});
			}
		}
		sort(sq[zs],sq[zs]+3,greater<long long>());
	}
	printf("%lld\n",zs);
	for(i=1;i<=zs;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%lld%c",sq[i][j]," \n"[j==2]);
		}
	}
}