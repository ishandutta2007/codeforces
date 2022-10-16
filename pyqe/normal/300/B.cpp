#include <bits/stdc++.h>

using namespace std;

long long n,m,dsu[100069],fq[100069],zs=0;
vector<long long> cc[100069],sq[100069];
vector<vector<long long>> vl[4];

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

int main()
{
	long long i,j,k,l,sz;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		dsu[i]=i;
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		dsu[fd(l)]=fd(k);
	}
	for(i=1;i<=n;i++)
	{
		cc[fd(i)].push_back(i);
	}
	for(i=1;i<=n;i++)
	{
		if(fd(i)==i)
		{
			sz=cc[i].size();
			if(sz>3)
			{
				printf("-1\n");
				return 0;
			}
			vl[sz].push_back(cc[i]);
			fq[sz]++;
		}
	}
	if(fq[2]>fq[1]||(fq[1]-fq[2])%3)
	{
		printf("-1\n");
		return 0;
	}
	for(i=0;i<fq[3];i++)
	{
		zs++;
		sq[zs]=vl[3][i];
	}
	for(i=0;i<fq[2];i++)
	{
		zs++;
		sq[zs]=vl[2][i];
		sq[zs].push_back(vl[1][i][0]);
	}
	for(i=fq[2];i<fq[1];i++)
	{
		zs+=(i-fq[2])%3==0;
		sq[zs].push_back(vl[1][i][0]);
	}
	for(i=1;i<=zs;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%lld%c",sq[i][j]," \n"[j==2]);
		}
	}
}