#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,st,fn,d,d2,dh[100069];
vector<long long> al[100069];
bitset<100069> vtd;

pair<long long,long long> dfs(long long ky,long long x)
{
	long long i,sz=al[x].size(),l;
	pair<long long,long long> wp,zp={0,x};
	
	vtd[x]=ky;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(vtd[l]!=ky)
		{
			if(ky)
			{
				dh[l]=dh[x]+1;
			}
			wp=dfs(ky,l);
			wp.fr++;
			zp=max(zp,wp);
		}
	}
	return zp;
}

int main()
{
	long long t,rr,i,k,l,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld%lld%lld",&n,&st,&fn,&d,&d2);
		for(i=1;i<=n;i++)
		{
			al[i].clear();
		}
		for(i=0;i<n-1;i++)
		{
			scanf("%lld%lld",&k,&l);
			al[k].push_back(l);
			al[l].push_back(k);
		}
		dh[st]=0;
		z=dfs(0,dfs(1,st).sc).fr;
		if(d2<=d*2||z<=d*2||dh[fn]<=d)
		{
			printf("Alice\n");
		}
		else
		{
			printf("Bob\n");
		}
	}
}