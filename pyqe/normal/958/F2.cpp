#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n,m,ttl=0,a[200069],wg[200069],fq[200069];
vector<long long> vl[200069];

int main()
{
	long long i,mn=inf,z=inf;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=1;i<=m;i++)
	{
		scanf("%lld",wg+i);
		ttl+=wg[i];
	}
	for(i=1;i<=n;i++)
	{
		vl[a[i]].push_back(i);
		fq[a[i]]++;
	}
	for(i=1;i<=m;i++)
	{
		if(fq[i]<wg[i])
		{
			printf("-1\n");
			return 0;
		}
		if(wg[i])
		{
			mn=min(mn,vl[i][fq[i]-wg[i]]);
		}
	}
	for(i=n;i;i--)
	{
		z=min(z,i-mn+1-ttl);
		fq[a[i]]--;
		if(fq[a[i]]<wg[a[i]])
		{
			break;
		}
		mn=min(mn,vl[a[i]][fq[a[i]]-wg[a[i]]]);
	}
	printf("%lld\n",z);
}