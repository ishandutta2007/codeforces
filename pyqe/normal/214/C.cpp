#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],dgg[100069],dg[100069];
vector<long long> al[100069];
queue<long long> q[3];

int main()
{
	long long rr,i,j,k,l,sz,p,c,sm,z=1e18;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		a[i]--;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&sz);
		for(j=0;j<sz;j++)
		{
			scanf("%lld",&k);
			al[k].push_back(i);
			dgg[i]++;
		}
	}
	for(rr=0;rr<3;rr++)
	{
		for(i=1;i<=n;i++)
		{
			dg[i]=dgg[i];
			if(!dg[i])
			{
				q[a[i]].push(i);
			}
		}
		sm=0;
		for(c=0,p=rr;c<n;p=(p+1)%3)
		{
			for(;!q[p].empty();)
			{
				k=q[p].front();
				q[p].pop();
				c++;
				sm++;
				sz=al[k].size();
				for(i=0;i<sz;i++)
				{
					l=al[k][i];
					dg[l]--;
					if(!dg[l])
					{
						q[a[l]].push(l);
					}
				}
			}
			sm+=(c<n);
		}
		z=min(z,sm);
	}
	printf("%lld\n",z);
}