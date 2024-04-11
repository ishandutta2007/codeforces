#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d[2],a[100069],dg[100069],dsu[100069],cc[100069];
map<long long,long long> pst;
vector<pair<long long,long long>> al[100069];
bitset<100069> vtd,spc,sq;

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

void dfs(long long x)
{
	long long i,sz=al[x].size(),l,w;
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		w=al[x][i].sc;
		if(!vtd[l])
		{
			if(!spc[x])
			{
				sq[x]=w;
				sq[l]=w;
				spc[x]=1;
				spc[l]=1;
			}
			dfs(l);
		}
	}
	if(!spc[x])
	{
		printf("NO\n");
		exit(0);
	}
}

int main()
{
	long long i,ii,l;
	
	scanf("%lld%lld%lld",&n,d,d+1);
	for(i=1;i<=n;i++)
	{
		dsu[i]=i;
		cc[i]=1;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		for(ii=0;ii<2;ii++)
		{
			l=pst[d[ii]-a[i]];
			if(l)
			{
				al[i].push_back({l,ii});
				al[l].push_back({i,ii});
				dg[i]++;
				dg[l]++;
				if(fd(i)!=fd(l))
				{
					cc[fd(i)]+=cc[fd(l)];
					dsu[fd(l)]=fd(i);
				}
			}
		}
		pst[a[i]]=i;
	}
	for(i=1;i<=n;i++)
	{
		if((a[i]==d[0]-a[i]||a[i]==d[1]-a[i])&&cc[fd(i)]%2)
		{
			sq[i]=a[i]==d[1]-a[i];
			vtd[i]=1;
			cc[fd(i)]--;
		}
		else if(dg[i]<2&&!vtd[i])
		{
			dfs(i);
		}
	}
	for(i=1;i<=n;i++)
	{
		if(!vtd[i])
		{
			dfs(i);
		}
	}
	printf("YES\n");
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",(long long)sq[i]," \n"[i==n]);
	}
}