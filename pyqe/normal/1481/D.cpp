#include <bits/stdc++.h>

using namespace std;

long long n,d,nn,fh,ts[1069],sq[100069],zs;
bitset<1069> am[1069];
bitset<1069> vtd,vtd2;
bool r0,bad;

void dfs(long long x)
{
	long long i;
	
	vtd[x]=1;
	vtd2[x]=1;
	for(i=1;i<=n;i++)
	{
		if(am[x][i])
		{
			if(!vtd[i])
			{
				dfs(i);
			}
			else if(vtd2[i])
			{
				fh=i;
				r0=1;
				bad=0;
			}
			if(r0)
			{
				if(!bad)
				{
					zs++;
					sq[zs]=x;
				}
				bad|=x==fh;
				return;
			}
		}
	}
	vtd2[x]=0;
	nn++;
	ts[nn]=x;
}

int main()
{
	long long t,rr,i,j,k,l;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				scanf(" %c",&ch);
				am[i][j]=ch=='b';
			}
			vtd[i]=0;
			vtd2[i]=0;
		}
		zs=0;
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				if(am[i][j]==am[j][i])
				{
					break;
				}
			}
			if(j<=n)
			{
				break;
			}
		}
		if(i<=n)
		{
			k=i;
			l=j;
			for(i=0;i<d+1;i++)
			{
				zs++;
				sq[zs]=k;
				swap(k,l);
			}
		}
		if(!zs&&d%2)
		{
			for(i=0;i<d+1;i++)
			{
				zs++;
				sq[zs]=i%2+1;
			}
		}
		if(!zs)
		{
			nn=0;
			r0=0;
			for(i=1;i<=n;i++)
			{
				if(!vtd[i])
				{
					dfs(i);
					if(r0)
					{
						break;
					}
				}
			}
			if(r0)
			{
				k=zs;
				for(i=0;i<d+1-k;i++)
				{
					zs++;
					sq[zs]=sq[zs-k];
				}
				zs=min(zs,d+1);
			}
		}
		if(!zs&&n>2)
		{
			for(;zs<d+1;)
			{
				zs++;
				sq[zs]=ts[(zs+d/2)%2+1|2*(zs>d/2+1)];
			}
		}
		if(zs)
		{
			printf("YES\n");
			for(i=1;i<=zs;i++)
			{
				printf("%lld%c",sq[i]," \n"[i==zs]);
			}
		}
		else
		{
			printf("NO\n");
		}
	}
}