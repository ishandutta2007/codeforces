#include <bits/stdc++.h>

using namespace std;

const long long dv=998244353;
long long n,cr,pr[100069],dg[100069],sq[100069];
vector<long long> al[100069];
bitset<100069> vtd;

void rtd(long long x)
{
	long long i,sz=al[x].size(),l;
	vector<long long> v;
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			pr[l]=x;
			v.push_back(l);
			rtd(l);
		}
	}
	al[x]=v;
}

void trv(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	if(pr[x]&&!vtd[pr[x]])
	{
		dg[pr[x]]=(dg[pr[x]]+cr-1)%cr;
	}
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dg[l]=(dg[l]+cr-1)%cr;
			if(!dg[l])
			{
				trv(l);
			}
			else
			{
				sq[cr]=0;
			}
		}
	}
}

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	
	dg[x]=(sz+(x!=1))%cr;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		dfs(l);
	}
	if(!dg[x])
	{
		trv(x);
	}
}

int main()
{
	long long t,rr,i,j,k,l;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			al[i].clear();
			vtd[i]=0;
		}
		for(i=0;i<n-1;i++)
		{
			scanf("%lld%lld",&k,&l);
			al[k].push_back(l);
			al[l].push_back(k);
		}
		rtd(1);
		for(i=n;i;i--)
		{
			sq[i]=0;
			if((n-1)%i==0)
			{
				if(i-1)
				{
					sq[i]=1;
					cr=i;
					for(j=1;j<=n;j++)
					{
						vtd[j]=0;
					}
					dfs(1);
					sq[i]&=!dg[1];
				}
				else
				{
					sq[i]=1;
					for(j=0;j<n-1;j++)
					{
						sq[i]=sq[i]*2%dv;
					}
				}
				for(j=i*2;j<=n;j+=i)
				{
					sq[i]=(sq[i]+dv-sq[j])%dv;
				}
			}
		}
		for(i=1;i<=n;i++)
		{
			printf("%lld%c",sq[i]," \n"[i==n]);
		}
	}
}