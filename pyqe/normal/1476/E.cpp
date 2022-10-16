#include <bits/stdc++.h>

using namespace std;

long long n,d,ca[4],sq[100069],zs=0;
array<long long,4> a[100069],pa;
map<array<long long,4>,long long> pst;
vector<long long> al[100069];
bitset<100069> vtd,vtd2;

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	vtd2[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dfs(l);
		}
		else if(vtd2[l])
		{
			printf("NO\n");
			exit(0);
		}
	}
	vtd2[x]=0;
	zs++;
	sq[zs]=x;
}

int main()
{
	long long t,rr,i,j,k,l,mk;
	char ch;
	
	scanf("%lld%lld%lld",&n,&t,&d);
	for(i=1;i<=n;i++)
	{
		for(j=0;j<d;j++)
		{
			scanf(" %c",&ch);
			if(ch!='_')
			{
				a[i][j]=ch-'a';
			}
			else
			{
				a[i][j]=-1;
			}
		}
		pst[a[i]]=i;
	}
	for(rr=0;rr<t;rr++)
	{
		for(i=0;i<d;i++)
		{
			scanf(" %c",&ch);
			ca[i]=ch-'a';
		}
		scanf("%lld",&k);
		for(i=0;i<d;i++)
		{
			if(a[k][i]+1&&a[k][i]!=ca[i])
			{
				printf("NO\n");
				return 0;
			}
		}
		for(mk=0;mk<1ll<<d;mk++)
		{
			for(i=0;i<d;i++)
			{
				pa[i]=-1;
				if(mk>>i&1)
				{
					pa[i]=ca[i];
				}
			}
			l=pst[pa];
			if(l&&l!=k)
			{
				al[l].push_back(k);
			}
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
	for(i=1;i<=zs;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==zs]);
	}
}