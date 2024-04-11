#include <bits/stdc++.h>

using namespace std;

long long n,m,pr[1000069],dis[1000069],cdis,tg,zs[2];
vector<long long> al[1000069],z[2];
bitset<1000069> vtd,vtd2,bad;

long long fd(long long x)
{
	if(pr[x]!=x)
	{
		pr[x]=fd(pr[x]);
	}
	return pr[x];
}

void scc(long long x)
{
	long long i,sz=al[x].size(),l;
	
	dis[x]=cdis;
	vtd[x]=1;
	vtd2[x]=1;
	cdis++;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			scc(l);
		}
		if(vtd2[fd(l)]&&dis[fd(l)]<dis[fd(x)])
		{
			pr[fd(x)]=fd(l);
		}
	}
	cdis--;
	vtd2[x]=0;
}

int main()
{
	long long t,rr,i,j,k,l,sz,ii;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)
		{
			al[i].clear();
			pr[i]=i;
		}
		for(i=0;i<m;i++)
		{
			scanf("%lld%lld",&k,&l);
			if(k==l)
			{
				continue;
			}
			al[k].push_back(l);
		}
		vtd.reset();
		for(i=1;i<=n;i++)
		{
			if(!vtd[i])
			{
				cdis=0;
				scc(i);
			}
		}
		bad.reset();
		for(i=1;i<=n;i++)
		{
			sz=al[i].size();
			for(j=0;j<sz;j++)
			{
				l=al[i][j];
				if(fd(l)!=fd(i))
				{
					bad[fd(i)]=1;
				}
			}
		}
		for(i=1;i<=n;i++)
		{
			if(!bad[fd(i)])
			{
				tg=fd(i);
				break;
			}
		}
		for(ii=0;ii<2;ii++)
		{
			z[ii].clear();
			zs[ii]=0;
		}
		for(i=1;i<=n;i++)
		{
			if(fd(i)==tg)
			{
				z[0].push_back(i);
				zs[0]++;
			}
			else
			{
				z[1].push_back(i);
				zs[1]++;
			}
		}
		if(!zs[0]||!zs[1])
		{
			printf("No\n");
			continue;
		}
		printf("Yes\n");
		printf("%lld %lld\n",(long long)z[0].size(),(long long)z[1].size());
		for(ii=0;ii<2;ii++)
		{
			sz=z[ii].size();
			for(i=0;i<sz;i++)
			{
				printf("%lld%c",z[ii][i]," \n"[i==sz-1]);
			}
		}
	}
}