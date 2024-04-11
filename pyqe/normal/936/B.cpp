#include <bits/stdc++.h>

using namespace std;

long long n,m,st,pr[100069][2],sq[200069],zs=0;
vector<long long> al[100069];
bitset<100069> vtd,vtd2;

void dfs(long long x,bool cw)
{
	long long i,sz=al[x].size(),l;
	
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(pr[l][!cw]==-1)
		{
			pr[l][!cw]=x;
			dfs(l,!cw);
		}
	}
}

void dfs2(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	vtd2[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dfs2(l);
		}
		else if(vtd2[l])
		{
			printf("Draw\n");
			exit(0);
		}
	}
	vtd2[x]=0;
}

int main()
{
	long long i,j,ii,k,sz,p,e;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&sz);
		for(j=0;j<sz;j++)
		{
			scanf("%lld",&k);
			al[i].push_back(k);
		}
		for(ii=0;ii<2;ii++)
		{
			pr[i][ii]=-1;
		}
	}
	scanf("%lld",&st);
	pr[st][0]=0;
	dfs(st,0);
	for(i=1;i<=n;i++)
	{
		if(al[i].empty()&&pr[i][1]!=-1)
		{
			printf("Win\n");
			for(p=i,e=1;p;p=pr[p][e],e^=1)
			{
				zs++;
				sq[zs]=p;
			}
			for(i=zs;i;i--)
			{
				printf("%lld%c",sq[i]," \n"[i==1]);
			}
			return 0;
		}
	}
	dfs2(st);
	printf("Lose\n");
}