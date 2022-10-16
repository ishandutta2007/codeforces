#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,nn,sbt[500069],mx2[500069],dh[500069],pr[500069],eu[500069],sq[500069],zs,zs2,inf=1e18;
vector<long long> al[500069];
bitset<500069> vtd;
pair<long long,long long> dp[500069],sq2[500069];

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	vector<long long> v;
	
	vtd[x]=1;
	sbt[x]=1;
	dp[x]={0,0};
	mx2[x]=0;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dh[l]=dh[x]+1;
			pr[l]=x;
			dfs(l);
			sbt[x]+=sbt[l];
			if(sbt[l]>=dp[x].fr)
			{
				mx2[x]=dp[x].fr;
				dp[x]={sbt[l],l};
			}
			else
			{
				mx2[x]=max(mx2[x],sbt[l]);
			}
			v.push_back(l);
		}
	}
	al[x]=v;
}

void trv(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			trv(l);
		}
	}
	nn++;
	eu[nn]=x;
}

int main()
{
	long long t,rr,i,k,l,p,mx;
	
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
		dh[1]=0;
		dfs(1);
		for(i=1;i<=n;i++)
		{
			vtd[i]=0;
		}
		mx=-inf;
		zs=0;
		for(p=1;1;p=dp[p].sc)
		{
			mx=max(mx,mx2[p]);
			zs++;
			sq[zs]=p;
			if(zs==(n+1)/2)
			{
				break;
			}
			if((n-zs)%2==0&&max(mx,dp[p].fr)<=(n-zs)/2)
			{
				nn=0;
				for(;p;p=pr[p])
				{
					trv(p);
					nn--;
				}
				zs2=0;
				for(i=1;i<=nn/2;i++)
				{
					zs2++;
					sq2[zs2]={eu[i],eu[i+nn/2]};
				}
				break;
			}
		}
		if(zs==(n+1)/2)
		{
			printf("PATH\n%lld\n",zs);
			for(i=1;i<=zs;i++)
			{
				printf("%lld%c",sq[i]," \n"[i==zs]);
			}
		}
		else
		{
			printf("PAIRING\n%lld\n",zs2);
			for(i=1;i<=zs2;i++)
			{
				printf("%lld %lld\n",sq2[i].fr,sq2[i].sc);
			}
		}
	}
}