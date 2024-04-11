#include <bits/stdc++.h>

using namespace std;

long long n,m,dsu[2069],sq[2069];
bitset<1069> a[2][1069];
vector<long long> al[2069],vl[2069];
bitset<2069> vtd,vtd2;

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
	long long i,sz=al[x].size(),l,mx=0;
	
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
			printf("No\n");
			exit(0);
		}
		mx=max(mx,sq[l]);
	}
	vtd2[x]=0;
	sz=vl[x].size();
	for(i=0;i<sz;i++)
	{
		l=vl[x][i];
		sq[l]=mx+1;
	}
}

int main()
{
	long long i,j,k,l;
	string s;
	char ch;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n+m;i++)
	{
		dsu[i]=i;
	}
	for(i=1;i<=n;i++)
	{
		cin>>s;
		for(j=1;j<=m;j++)
		{
			ch=s[j-1];
			a[0][i][j]=ch=='=';
			a[1][i][j]=ch=='<';
			if(a[0][i][j])
			{
				dsu[fd(n+j)]=fd(i);
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(!a[0][i][j])
			{
				if(fd(i)==fd(n+j))
				{
					printf("No\n");
					return 0;
				}
				k=fd(i);
				l=fd(n+j);
				if(a[1][i][j])
				{
					swap(k,l);
				}
				al[k].push_back(l);
			}
		}
	}
	for(i=1;i<=n+m;i++)
	{
		vl[fd(i)].push_back(i);
	}
	for(i=1;i<=n+m;i++)
	{
		if(fd(i)==i&&!vtd[i])
		{
			dfs(i);
		}
	}
	printf("Yes\n");
	for(i=1;i<=n+m;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==n||i==n+m]);
	}
}