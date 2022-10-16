#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,dg[200069],sq[200069];
vector<long long> al[200069];
bitset<200069> vtd;
pair<long long,long long> dp[200069][2];

void bd(long long x)
{
	long long i,l;
	pair<long long,long long> tmp;
	
	vtd[x]=1;
	dp[x][0]={0,-1};
	dp[x][1]={1,-dg[x]};
	for(i=0;i<dg[x];i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			bd(l);
			tmp=max(dp[l][0],dp[l][1]);
			dp[x][0]={dp[x][0].fr+tmp.fr,dp[x][0].sc+tmp.sc};
			dp[x][1]={dp[x][1].fr+dp[l][0].fr,dp[x][1].sc+dp[l][0].sc};
		}
	}
}

void trv(long long x,long long e)
{
	long long i,l;
	
	vtd[x]=1;
	if(!e)
	{
		sq[x]=1;
	}
	else
	{
		sq[x]=dg[x];
	}
	for(i=0;i<dg[x];i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			trv(l,!e&&dp[l][1]>dp[l][0]);
		}
	}
}

int main()
{
	long long i,ii,k,l,e;
	pair<pair<long long,long long>,long long> ze;
	
	scanf("%lld",&n);
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		for(ii=0;ii<2;ii++)
		{
			al[k].push_back(l);
			dg[k]++;
			swap(k,l);
		}
	}
	bd(1);
	ze=max(mp(dp[1][0],0),{dp[1][1],1});
	e=ze.sc;
	vtd.reset();
	trv(1,e);
	printf("%lld %lld\n",ze.fr.fr+(n==2),-ze.fr.sc);
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==n]);
	}
}