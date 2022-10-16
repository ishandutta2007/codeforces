#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,dg[100069],nr[100069];
deque<pair<long long,long long>> dq;

int main()
{
	long long i,k,l,w,z;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		dg[i]=0;
		nr[i]=1e18;
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		dg[k]++;
		nr[k]=min(nr[k],(l+n-k)%n);
	}
	for(i=1;i<=n*2-1;i++)
	{
		k=(i-1)%n+1;
		if(dg[k])
		{
			w=i+(dg[k]-1)*n+nr[k];
			for(;!dq.empty()&&dq.back().fr<=w;dq.pop_back());
			dq.push_back({w,i});
		}
		for(;!dq.empty()&&dq.front().sc<i-n+1;dq.pop_front());
		if(i>=n)
		{
			z=0;
			if(!dq.empty())
			{
				z=dq.front().fr-(i-n+1);
			}
			printf("%lld%c",z," \n"[i==n*2-1]);
		}
	}
}