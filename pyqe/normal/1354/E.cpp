#include <bits/stdc++.h>

using namespace std;

long long n,m,cr,a[3],fq[5069][2],pr[5069][5069],sq[5069];
vector<long long> al[5069],vl[5069][2];
bitset<5069> vtd,nr;

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	vl[cr][nr[x]].push_back(x);
	fq[cr][nr[x]]++;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			nr[l]=nr[x]^1;
			dfs(l);
		}
		else if(nr[l]==nr[x])
		{
			printf("NO\n");
			exit(0);
		}
	}
}

int main()
{
	long long i,j,ii,k,l,e;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<3;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		{
			pr[i][j]=-1;
		}
	}
	pr[0][0]=0;
	for(i=1;i<=n;i++)
	{
		if(!vtd[i])
		{
			cr=i;
			dfs(i);
		}
		for(ii=0;ii<2;ii++)
		{
			for(j=fq[i][ii];j<=n;j++)
			{
				if(pr[i-1][j-fq[i][ii]]!=-1)
				{
					pr[i][j]=ii;
				}
			}
		}
	}
	if(pr[n][a[1]]==-1)
	{
		printf("NO\n");
	}
	else
	{
		for(e=a[1],i=n;i;e-=fq[i][pr[i][e]],i--)
		{
			for(j=0;j<fq[i][pr[i][e]];j++)
			{
				sq[vl[i][pr[i][e]][j]]=2;
			}
		}
		printf("YES\n");
		for(i=1;i<=n;i++)
		{
			if(!sq[i])
			{
				if(a[0])
				{
					sq[i]=1;
					a[0]--;
				}
				else
				{
					sq[i]=3;
				}
			}
			printf("%lld",sq[i]);
		}
		printf("\n");
	}
}