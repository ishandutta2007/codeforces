#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,nv=0,ct[2],e,dp[200069],vi[200069],sbt[200069];
vector<pair<long long,long long>> al[200069];
bitset<200069> vtd;

void bd(long long ky,long long x)
{
	long long i,ii,sz=al[x].size(),l,p;
	
	vi[x]=nv;
	sbt[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		p=al[x][i].sc;
		if(!vtd[p]&&vi[l]<nv)
		{
			bd(ky,l);
			sbt[x]+=sbt[l];
			for(ii=0;ii<2;ii++)
			{
				if(sbt[l]==dp[ky-1-ii])
				{
					ct[ii]=l;
					ct[!ii]=x;
					e=p;
				}
			}
		}
	}
}

bool rk(long long ky,long long x)
{
	long long ii,p[2];
	
	if(ky<=3)
	{
		return 1;
	}
	nv++;
	e=-1;
	bd(ky,x);
	if(e==-1)
	{
		return 0;
	}
	vtd[e]=1;
	for(ii=0;ii<2;ii++)
	{
		p[ii]=ct[ii];
	}
	return rk(ky-1,p[0])&&rk(ky-2,p[1]);
}

int main()
{
	long long i,k,l;
	
	scanf("%lld",&n);
	dp[0]=1;
	dp[1]=1;
	for(d=1;dp[d]+dp[d-1]<=n;)
	{
		d++;
		dp[d]=dp[d-1]+dp[d-2];
	}
	if(n!=dp[d])
	{
		printf("NO\n");
		return 0;
	}
	for(i=1;i<=n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back({l,i});
		al[l].push_back({k,i});
	}
	if(rk(d,1))
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}