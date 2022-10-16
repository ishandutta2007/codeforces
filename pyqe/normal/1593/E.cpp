#include <bits/stdc++.h>

using namespace std;

long long n,d,dg[400069],nr[400069];
vector<long long> al[400069];
queue<long long> q;

int main()
{
	long long t,rr,i,k,l,sz,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=1;i<=n;i++)
		{
			al[i].clear();
			dg[i]=0;
			nr[i]=0;
		}
		for(i=0;i<n-1;i++)
		{
			scanf("%lld%lld",&k,&l);
			al[k].push_back(l);
			al[l].push_back(k);
			dg[k]++;
			dg[l]++;
		}
		for(i=1;i<=n;i++)
		{
			if(dg[i]<=1)
			{
				q.push(i);
				nr[i]=1;
			}
		}
		z=n;
		for(;!q.empty();)
		{
			k=q.front();
			q.pop();
			z--;
			if(nr[k]==d)
			{
				continue;
			}
			sz=al[k].size();
			for(i=0;i<sz;i++)
			{
				l=al[k][i];
				dg[l]--;
				if(dg[l]==1)
				{
					q.push(l);
					nr[l]=nr[k]+1;
				}
			}
		}
		printf("%lld\n",z);
	}
}