#include <bits/stdc++.h>

using namespace std;

long long n,m,rt,pr[300069],cd[300069],dg[300069],ls[300069],sq[300069],zs=0;
bitset<300069> spc;
vector<long long> al[300069];
queue<long long> q;

void ers(long long x)
{
	long long i,sz=al[x].size(),l;
	
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		dg[l]--;
		if(!dg[l])
		{
			q.push(l);
		}
	}
}

int main()
{
	long long i,k,l,p;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",pr+i);
		if(!pr[i])
		{
			rt=i;
		}
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		if(cd[k]||spc[l])
		{
			printf("0\n");
			return 0;
		}
		cd[k]=l;
		spc[l]=1;
	}
	for(i=1;i<=n;i++)
	{
		if(!spc[i])
		{
			for(p=i;1;p=cd[p])
			{
				if(ls[pr[p]]<i)
				{
					dg[i]++;
					al[pr[p]].push_back(i);
				}
				ls[p]=i;
				if(!cd[p])
				{
					break;
				}
			}
		}
	}
	ers(0);
	for(;!q.empty();)
	{
		k=q.front();
		q.pop();
		for(p=k;1;p=cd[p])
		{
			zs++;
			sq[zs]=p;
			ers(p);
			if(!cd[p])
			{
				break;
			}
		}
	}
	if(zs<n)
	{
		printf("0\n");
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==n]);
	}
}