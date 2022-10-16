#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,nn,nr[100069],sbt[100069],a[3000069],inf=1e18;
vector<pair<long long,long long>> al[100069];

void dfs(long long x)
{
	long long i,sz=al[x].size(),l,w;
	bool lf=1;
	
	sbt[x]=0;
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		w=al[x][i].sc;
		if(nr[x]+w<nr[l])
		{
			nr[l]=nr[x]+w;
			dfs(l);
			sbt[x]+=sbt[l];
			lf=0;
			for(;w;w/=2)
			{
				nn++;
				a[nn]=(w-w/2)*sbt[l];
			}
		}
	}
	d+=nr[x]*lf;
	sbt[x]+=lf;
}

int main()
{
	long long t,rr,i,k,l,w;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=1;i<=n;i++)
		{
			al[i].clear();
			nr[i]=inf;
		}
		for(i=0;i<n-1;i++)
		{
			scanf("%lld%lld%lld",&k,&l,&w);
			al[k].push_back({l,w});
			al[l].push_back({k,w});
		}
		d*=-1;
		nn=0;
		nr[1]=0;
		dfs(1);
		sort(a+1,a+nn+1,greater<long long>());
		for(i=1;d>0;i++)
		{
			d-=a[i];
		}
		printf("%lld\n",i-1);
	}
}