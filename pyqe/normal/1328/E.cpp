#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,pr[200069],dh[200069],pst[200069],sbt[200069],cdh=0;
vector<long long> al[200069];
bitset<200069> vtd;
pair<long long,long long> qq[200069];

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	dh[x]=cdh;
	n++;
	pst[x]=n;
	sbt[x]=1;
	cdh++;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			pr[l]=x;
			dfs(l);
			sbt[x]+=sbt[l];
		}
	}
	cdh--;
}

int main()
{
	long long t,rr,i,k,l,sz;
	
	scanf("%lld%lld",&n,&t);
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	n=0;
	pr[1]=1;
	dfs(1);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&sz);
		for(i=1;i<=sz;i++)
		{
			scanf("%lld",&k);
			qq[i]={dh[pr[k]],pr[k]};
		}
		sort(qq+1,qq+sz+1);
		for(i=1;i<=sz;i++)
		{
			k=qq[i].sc;
			if(i-1)
			{
				if(pst[k]<pst[l]||pst[k]>pst[l]+sbt[l]-1)
				{
					i=-1;
					break;
				}
			}
			l=k;
		}
		if(i!=-1)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}