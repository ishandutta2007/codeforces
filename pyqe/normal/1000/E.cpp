#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,dsu[300069],dh[300069];
vector<long long> al[300069],al2[300069];
bitset<300069> vtd,vtd2;
pair<long long,long long> dp[300069];

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

void bgt(long long x,long long b4)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	vtd2[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(l==b4)
		{
			continue;
		}
		if(!vtd[l])
		{
			dh[l]=dh[x]+1;
			bgt(l,x);
		}
		if(vtd2[fd(l)]&&dh[fd(l)]<dh[fd(x)])
		{
			dsu[fd(x)]=fd(l);
		}
	}
	vtd2[x]=0;
}

void ffh(long long x)
{
	long long i,sz=al2[x].size(),l;
	
	vtd[x]=1;
	dp[x]={0,x};
	for(i=0;i<sz;i++)
	{
		l=al2[x][i];
		if(!vtd[l])
		{
			ffh(l);
			dp[x]=max(dp[x],{dp[l].fr+1,dp[l].sc});
		}
	}
}

int main()
{
	long long i,j,k,l,sz;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	for(i=1;i<=n;i++)
	{
		dsu[i]=i;
	}
	bgt(1,0);
	for(i=1;i<=n;i++)
	{
		sz=al[i].size();
		for(j=0;j<sz;j++)
		{
			l=al[i][j];
			al2[fd(i)].push_back(fd(l));
		}
	}
	vtd.reset();
	ffh(fd(1));
	vtd.reset();
	k=dp[fd(1)].sc;
	ffh(k);
	printf("%lld\n",dp[k].fr);
}