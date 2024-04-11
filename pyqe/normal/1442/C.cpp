#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,dp[19][200069],pwk,dv=998244353,inf=1e18;
vector<long long> al[2][200069];
pair<long long,long long> nr[2][200069];
priority_queue<pair<pair<long long,long long>,pair<bool,long long>>> pqq;
priority_queue<pair<long long,long long>> pq;

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

void ad(long long xx,long long x,long long w,long long w2)
{
	if(mp(w,w2)<nr[xx][x])
	{
		pqq.push({{-w,-w2},{xx,x}});
		nr[xx][x]={w,w2};
	}
}

int main()
{
	long long i,j,ii,ky,k,l,w,w2,sz,z=inf;
	pair<long long,long long> z2;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[0][k].push_back(l);
		al[1][l].push_back(k);
	}
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n;i++)
		{
			nr[ii][i]={inf,inf};
		}
	}
	pqq.push({{0,0},{0,1}});
	nr[0][1]={0,0};
	for(;!pqq.empty();)
	{
		w=-pqq.top().fr.fr;
		w2=-pqq.top().fr.sc;
		ky=pqq.top().sc.fr;
		k=pqq.top().sc.sc;
		pqq.pop();
		if(mp(w,w2)>nr[ky][k])
		{
			continue;
		}
		ad(!ky,k,w+1,w2);
		sz=al[ky][k].size();
		for(i=0;i<sz;i++)
		{
			l=al[ky][k][i];
			ad(ky,l,w,w2+1);
		}
	}
	z2=min(nr[0][n],nr[1][n]);
	if(z2.fr>=18)
	{
		printf("%lld\n",(pw(2,z2.fr)+dv-1+z2.sc)%dv);
		return 0;
	}
	for(i=0;i<19;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(!i)
			{
				dp[i][j]=inf*(j>1);
			}
			else
			{
				dp[i][j]=dp[i-1][j]+(1ll<<i-1);
			}
			pq.push({-dp[i][j],j});
		}
		for(;!pq.empty();)
		{
			w=-pq.top().fr;
			k=pq.top().sc;
			pq.pop();
			if(w>dp[i][k])
			{
				continue;
			}
			sz=al[i%2][k].size();
			for(j=0;j<sz;j++)
			{
				l=al[i%2][k][j];
				if(w+1<dp[i][l])
				{
					pq.push({-w-1,l});
					dp[i][l]=w+1;
				}
			}
		}
		z=min(z,dp[i][n]);
	}
	printf("%lld\n",z%dv);
}