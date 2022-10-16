#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m=0,cr,am[2069][2069],dsu[2069],nr[2069],ls[2069];
pair<long long,long long> ed[2000069],as[2000069];
vector<pair<long long,long long>> al[2069];

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
	
	ls[x]=cr;
	if(nr[x]!=am[cr][x])
	{
		printf("NO\n");
		exit(0);
	}
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		w=al[x][i].sc;
		if(ls[l]<cr)
		{
			nr[l]=nr[x]+w;
			dfs(l);
		}
	}
}

int main()
{
	long long i,j,k,l,w,p;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%lld",&am[i][j]);
			if(i<j)
			{
				m++;
				ed[m]={i,j};
				as[m]={am[i][j],m};
			}
			else if((i==j&&am[i][j])||(i>j&&(am[i][j]!=am[j][i]||!am[i][j])))
			{
				printf("NO\n");
				return 0;
			}
		}
		dsu[i]=i;
	}
	sort(as+1,as+m+1);
	for(i=1;i<=m;i++)
	{
		w=as[i].fr;
		p=as[i].sc;
		k=ed[p].fr;
		l=ed[p].sc;
		if(fd(k)!=fd(l))
		{
			al[k].push_back({l,w});
			al[l].push_back({k,w});
			dsu[fd(l)]=fd(k);
		}
	}
	for(i=1;i<=n;i++)
	{
		cr=i;
		nr[i]=0;
		dfs(i);
	}
	printf("YES\n");
}