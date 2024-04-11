#include <bits/stdc++.h>

using namespace std;

long long n,m,sq[300069],fq[2],pwk,dv=998244353;
vector<long long> al[300069];
bitset<300069> vtd;
bool r0;

long long pw(long long x,long long y)
{
	if(!y)
	{
		return 1;
	}
	pwk=pw(x,y/2);
	pwk=pwk*pwk%dv;
	if(y%2)
	{
		pwk=pwk*x%dv;
	}
	return pwk;
}

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	fq[sq[x]]++;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			sq[l]=!sq[x];
			dfs(l);
			if(r0)
			{
				return;
			}
		}
		else
		{
			if(sq[l]==sq[x])
			{
				r0=1;
				return;
			}
		}
	}
}

int main()
{
	long long t,rr,i,ii,k,l,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)
		{
			al[i].clear();
			vtd[i]=0;
		}
		for(i=0;i<m;i++)
		{
			scanf("%lld%lld",&k,&l);
			al[k].push_back(l);
			al[l].push_back(k);
		}
		z=1;
		for(i=1;i<=n;i++)
		{
			if(!vtd[i])
			{
				for(ii=0;ii<2;ii++)
				{
					fq[ii]=0;
				}
				r0=0;
				dfs(i);
				if(!r0)
				{
					k=0;
					for(ii=0;ii<2;ii++)
					{
						k=(k+pw(2,fq[ii]))%dv;
					}
					z=z*k%dv;
				}
				else
				{
					z=0;
					break;
				}
			}
		}
		printf("%lld\n",z);
	}
}